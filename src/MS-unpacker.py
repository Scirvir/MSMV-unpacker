import os
from csv import reader as csv_reader
import argparse
from math import floor, ceil, log, pow
from shutil import copyfileobj
import subprocess
from platform import system


repeats_count = {}
verbose_lvl_conf = None


class FileListEntry:
    def __init__(self, offset, file_size, hash, file_path):
        self.offset = offset
        self.file_size = file_size
        self.hash = hash
        self.file_path = file_path


# https://stackoverflow.com/a/14822210
def convert_size(size_bytes):
   if size_bytes == 0:
       return "0B"
   size_name = ("B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB")
   i = int(floor(log(size_bytes, 1024)))
   p = pow(1024, i)
   s = round(size_bytes / p, 2)
   return "%s %s" % (s, size_name[i])

def write_to_console(verbose_lvl, msg, end = "\n"):
    global verbose_lvl_conf
    if verbose_lvl <= verbose_lvl_conf:
        print(msg, end=end)


def form_header_bytes(chunk_size):
    chunk_header_string = f"52410005{str(hex(chunk_size))[2:].zfill(8)}{str(hex(chunk_size + 0x10))[2:].zfill(8)}00010000"
    return bytearray.fromhex(chunk_header_string)


def directory_to_unchunked_blob_with_filelist(src_folder_path: str = "", dst_blob_path: str = "", unpacked_bin_file: str = "", toc_file: str = ""):
    if src_folder_path == "":
        write_to_console(0, "No source folder provided.")
        return
    if dst_blob_path == "":
        write_to_console(0, "No blob destination file provided.")
        return
    if unpacked_bin_file == "":
        write_to_console(0, "No bin destination file provided.")
        return
    if toc_file == "":
        write_to_console(0, "No file list provided.")
        return

    toc = []
    with open(toc_file, 'r') as file:
        reader = csv_reader(file, delimiter='\t')
        next(reader, None)
        for row in reader:
            offset = int(row[0])
            file_path = src_folder_path + "/" + row[3]
            file_size = os.path.getsize(file_path)
            hash = int(row[2], 16)
            toc.append(FileListEntry(offset, file_size, hash, file_path))

    toc = sorted(toc, key=lambda x: x.offset)
    with open(dst_blob_path, 'wb') as datfile:
        for entry in toc:
            file_path = entry.file_path
            offset = entry.offset
            file_size = entry.file_size
            hash = entry.hash

            with open(file_path, 'rb') as infile:
                copyfileobj(infile, datfile)
    
    next_file_starting_offset = 0
    for entry in toc:
        entry.offset = next_file_starting_offset
        next_file_starting_offset += entry.file_size
    toc = sorted(toc, key=lambda x: x.hash)
    with open(unpacked_bin_file, 'wb') as binfile:
        binfile.write(bytearray.fromhex(f"000000C80000000D00000001{str(hex(len(toc)))[2:].zfill(8)}"))

        for entry in toc:
            offset = str(hex(entry.offset))[2:].zfill(16)
            file_size =  str(hex(entry.file_size))[2:].zfill(8)
            hash = str(hex(entry.hash))[2:].zfill(8)

            binfile.write(
                bytearray.fromhex(f"{offset}{file_size}{hash}")
            )
        offset = str(hex(toc[-1].offset + toc[-1].file_size)[2:].zfill(16))
        binfile.write(
            bytearray.fromhex(f"{offset}")
        )


def chunk_blob(blob_path: str = "", out_cnk_path: str = "", chunked_cache_path: str = "", chunk_size: str = 0x8000):
    
    source_offset = 0
    chunk_header = form_header_bytes(chunk_size)
    source_file_size = os.stat(blob_path).st_size

    source = None
    chunk_file = None
    dest = None

    result = False

    try:
        source = open(blob_path, 'rb')
        chunk_file = open(out_cnk_path, 'wb')

        num_of_chunks = ceil(source_file_size / 0x8000)
        chunk_file.write(bytearray.fromhex(str(hex(num_of_chunks))[2:].zfill(8)))
        dest = open(chunked_cache_path, 'wb')
        
        while (source_offset + chunk_size) < source_file_size:
            source.seek(source_offset)
            dest.write(chunk_header)
            data = source.read(chunk_size)
            dest.write(data)
            chunk_file.write(bytearray.fromhex(f"{chunk_size + 0x10:08x}"))
            source_offset += chunk_size

        source.seek(source_offset)
        chunk_size = source_file_size - source_offset
        chunk_header = form_header_bytes(chunk_size)
        dest.write(chunk_header)
        data = source.read(chunk_size)
        dest.write(data)
        chunk_size = len(data)
        chunk_file.write(bytearray.fromhex(f"{chunk_size + 0x10:08x}"))

        result = True
    finally:
        if source is not None:
            source.close()
        if chunk_file is not None:
            chunk_file.close()
        if dest is not None:
            dest.close()
        
        return result


def repack_folder(config: dict):
    output_chunk_file = config['output_chunk_file']
    output_bin_file = config['output_bin_file']
    input_folder = config['input_folder']
    chunked_cache_path = config['output_archive_file']
    toc_file = config['toc_file']
    chunk_size = 0x8000
    
    directory_to_unchunked_blob_with_filelist(input_folder, "./temp_unpacked_prechunking", output_bin_file, toc_file)
    result = chunk_blob("./temp_unpacked_prechunking", output_chunk_file, chunked_cache_path, chunk_size)

    if result:
        os.remove("./temp_unpacked_prechunking")
    else:
        write_to_console(0, "Something went wrong.")


def split_binary_file(input_file_path, offset, file_size, output_file_path, repeats_folder, output_root_folder):

    global repeats_count
    filepath_for_os = os.path.join(output_root_folder, output_file_path)

    with open(input_file_path, 'rb') as input_file:
        input_file.seek(offset)
        file_data = input_file.read(file_size)

    file_exists = os.path.isfile(filepath_for_os)
    if(not file_exists):
        os.makedirs(os.path.dirname(filepath_for_os), exist_ok=True)
        with open(filepath_for_os, 'wb') as output_file:
            output_file.write(file_data)
    else:
        write_to_console(2, f"{filepath_for_os} already exists. Writing to '{repeats_folder}'")

        filepath_for_os_repeats = os.path.join(repeats_folder, output_file_path)       
        os.makedirs(os.path.dirname(filepath_for_os_repeats), exist_ok=True)

        count = repeats_count.get(output_file_path, 0)

        with open(f'{filepath_for_os_repeats}_{count}', 'wb') as output_file:
            output_file.write(file_data)
        
        repeats_count.update({output_file_path: count + 1})


def split_cache_blob(config):
    global verbose_lvl_conf
    acum_found_files_size = 0
    file_count = 0
    results = {}

    input_file_path = config['uncompressed_blob_bin']
    output_root_folder = os.path.join(config['output_folder'], 'cache_ps3')
    toc_file = config['toc_file']
    repeats_folder = config['repeats_folder']

    toc = []
    input_file_size = os.stat(input_file_path).st_size

    with open(toc_file, 'r') as file:
        reader = csv_reader(file, delimiter='\t')
        next(reader, None)
        for row in reader:
            offset = int(row[0])
            file_size = int(row[1])
            hash = int(row[2], 16)
            output_file_path = row[3]
            toc.append((offset, file_size, hash, output_file_path))

    for offset, file_size, hash, output_file_path in toc:
        if ((offset + file_size) <= input_file_size):
            split_binary_file(input_file_path, offset, file_size, output_file_path, repeats_folder, output_root_folder)
            acum_found_files_size += file_size
            file_count +=1
        else:
            write_to_console(1, f"{output_file_path} offset and/or size out of bounds for archive. Skipping.")

    results.update({
        "blob_size": input_file_size,
        "acum_found_files_size": acum_found_files_size,
        "file_count": file_count,
        "coverage": acum_found_files_size/input_file_size
        })
    return results


def unpack_subprocess(cache_path, uncompressed_blob_path):
    global verbose_lvl_conf
    unpacker_windows = ["./MSMV-unpacker-win64.exe", "-c", cache_path, "-u", uncompressed_blob_path]
    unpacker_linux = ["./MSMV-unpacker-linux", "-c", cache_path, "-u", uncompressed_blob_path]
    cmd = []
    current_platform = system()
    if current_platform == 'Windows':
        cmd = unpacker_windows
    else:
        cmd = unpacker_linux

    try:
        with subprocess.Popen(
            cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, bufsize=1
        ) as proc:
            for line in proc.stdout:
                write_to_console(3, line.strip())
            for error_line in proc.stderr:
                write_to_console(0, error_line.strip())
        return True
    except Exception as e:
        write_to_console(0, e)
    return False


def extract(config):
    result = False
    input_cache_dat = config["input_cache_dat"]
    uncompressed_blob_bin = "tmp_uncompressed_blob_bin"
    config.update({"uncompressed_blob_bin": uncompressed_blob_bin})

    write_to_console(1, f'Start unpacking "{input_cache_dat}" archive.')
    unpack_subprocess(input_cache_dat, uncompressed_blob_bin)
    write_to_console(1, "Done unpacking. Extracting files...")

    results = split_cache_blob(config)
    os.remove(uncompressed_blob_bin)

    write_to_console(1, """
Done. 
Files extracted: {}
Coverage: {:.5f}%""".format(results["file_count"], results["coverage"] * 100), end=" ")
    acum_found_files_size = results["acum_found_files_size"]
    blob_size = results["blob_size"]
    unextracted_size = blob_size - acum_found_files_size

    if unextracted_size > 0:
        write_to_console(1, "({}/{}, {} weren't extracted)".format(acum_found_files_size, blob_size, convert_size(unextracted_size)))


def main(config):
    global verbose_lvl_conf
    mode = config["mode"]
    verbose_lvl_conf = int(config["verbose"])
    if mode not in ["unpack", "repack"]:
        print('"mode" parameter missing. Please run with "--mode" followed by either "unpack" or "repack"')
        exit()

    if mode == "unpack":
        extract(config)
    elif mode == "repack":
        repack_folder(config)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
                    formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                    description='Support script for unpacking MotorStorm file archive "cache_ps3.dat" by Scirvir.',
                    epilog='See known issues or report them at https://github.com/Scirvir/MSMV-unpacker"')
    parser.add_argument("--mode", help='Either "unpack" or "repack"', default="")

    parser.add_argument("--input_cache_dat", help="Path to cache_ps3.dat.", default="./cache_ps3.dat")
    parser.add_argument("--output_folder", help="Folder where output files will be saved to.", default="./cache_ps3_file_split_output/")
    parser.add_argument("--repeats_folder", help="Folder where output files will be saved to if a file with a matching name is found in the regular output folder.", default="./cache_ps3_file_split_output/cache_ps3_duplicates/")
    parser.add_argument("--toc_file", help="Path to 'cache_ps3.txt'.", default="./cache_ps3.txt")
    
    parser.add_argument("--input_folder", help="Path to cache_ps3_folder.", default="./cache_ps3_file_split_output/cache_ps3")
    parser.add_argument("--output_bin_file", help="", default="./unpacked_cache_ps3.bin")
    parser.add_argument("--output_chunk_file", help="Path where chunk index file (cache_ps3.cnk) will be stored.", default="./unpacked_cache_ps3.cnk")
    parser.add_argument("--output_archive_file", help="Path where chunked blob file will be stored.", default="./unpacked_cache_ps3.dat")
    parser.add_argument("--verbose", action='store', type=int, help='''
Verbose level.
    0 - Errors only
    1 - Info and errors
    2 - Info, errors and duplicates
                        ''', default="1")

    config = vars(parser.parse_args())
    main(config)
