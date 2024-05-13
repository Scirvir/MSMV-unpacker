import os
import csv
import argparse

repeats_count = {}

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
        print(f"{filepath_for_os} already exists. Writing to '{repeats_folder}'")

        filepath_for_os_repeats = os.path.join(repeats_folder, output_file_path)       
        os.makedirs(os.path.dirname(filepath_for_os_repeats), exist_ok=True)

        count = repeats_count.get(output_file_path, 0)

        with open(f'{filepath_for_os_repeats}_{count}', 'wb') as output_file:
            output_file.write(file_data)
        
        repeats_count.update({output_file_path: count + 1})


def main(config):
    input_file_path = config['input_file']
    output_root_folder = os.path.join(config['output_folder'], 'cache_ps3')
    toc_file = config['toc_file']
    repeats_folder = config['repeats_folder']

    toc = []
    input_file_size = os.stat(input_file_path).st_size

    with open(toc_file, 'r') as file:
        reader = csv.reader(file, delimiter='\t')
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
        else:
            print(f"{output_file_path} offset and/or size out of bounds for archive. Skipping.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
                    formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                    description='Support script for unpacking MotorStorm file archive "cache_ps3.dat" by Scirvir.',
                    epilog='See known issues or report them at https://github.com/Scirvir/MSMV-unpacker"')
    parser.add_argument('-i', "--input_file", help="Path to uncompressed blob file.", default="./cache_ps3_uncompressed_blob.bin")
    parser.add_argument('-f', "--output_folder", help="Folder where output files will be saved to.", default="./cache_ps3_file_split_output/")
    parser.add_argument('-r', "--repeats_folder", help="Folder where output files will be saved to if a file with a matching name is found in the regular output folder.", default="./cache_ps3_file_split_output/cache_ps3_duplicates/")
    parser.add_argument('-t', "--toc_file", help="Path to 'cache_ps3.txt'.", default="./cache_ps3.txt")

    config = vars(parser.parse_args())
    
    main(config)
