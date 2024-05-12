# MotorStorm RA unpacker

Unpacks asset archive from MotorStorm, cache_ps3.dat.

## RA structure
| Offset | Value |
|-|-|
| 0x0 | RA header `52 41 00 05` |
| 0x4 | Unpacked blob size. Always `0x8000` except for the last chunk. |
| 0x8 | Chunk size. Add `0x10` to this value to get the offset of next chunk. |
| 0xd | Whether this chunk is uncompressed or not. |

## Usage 
### Requirements
- Python 3.4+.
- Binaries found in [releases](https://github.com/Scirvir/MSMV-unpacker/releases) for your platform.
- cache_ps3.dat and cache_ps3.txt from the game.

Run the unpacker:
```
MSMV-unpacker-win64.exe -c "/path/to/cache_ps3.dat" -u "/path/to/uncompressed_blob_save_location"
```

Run splitter script:
```
python3 cache_ps3_file_split.py -i "/path/to/uncompressed_blob_file" -t "/path/to/cache_ps3.txt" -f "/path/to/output_folder/"
```
Launch either of these with the `-h` flag for additional information. Both of these will search in, and save to, the current directory if you don't specify something else.

### Support
- NTSC-U [BCUS-98137] 1.00
- PAL [BCES-00006] 1.00

## TODO

The main obstacle right now is figuring how the hashing algorithm and look-up works with the `cache_ps3.bin` and `cache_ps3.chk` files. This would mean:
- `cache_ps3.txt` no longer needed for splitting the uncompressed blob into individual files.
- Support for the 3.10 versions and the Japanese [BCJS-30004] 1.00 release, neither of which contain `cache_ps3.txt`.

## Disclaimer

The unpacking algorithm was minimally modified from the output of the decompiled code the game uses for the same purpose. Credit to the developers at Evolution Studios who made the original.