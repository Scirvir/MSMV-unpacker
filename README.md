# MotorStorm RA unpacker

Unpacks (and repacks) resource archive from MotorStorm, cache_ps3.dat.

## Archive structure
### cache_ps3.dat
Main resource archive.
| Offset | Value |
|-|-|
| 0x0 | RA header `52 41 00 05`. |
| 0x4 | Unpacked chunk size. |
| 0x8 | Chunk size. |
| 0xd | Whether this chunk is uncompressed (`0x1`) or not (`0x0`). |

### cache_ps3.bin
File index. Entries are sorted on 'hash' field.
| Header ||
|-|-|
| 0x0 - 0xB | `00 00 00 C8 00 00 00 0D 00 00 00 01` |
| 0xC - 0xF | Number of files in the archive. |

Every 16 bytes is a file entry. Example of the first entry:
|||
|-|-|
| 0x10 - 0x17 | File starting offset on uncompressed blob |
| 0x18 - 0x1B | Size of file uncompressed |
| 0x1C - 0x1F | Hash |

### cache_ps3.cnk
Chunk index.
|||
|-|-|
| 0x0 - 0x3 | Number of chunks in the archive |
| 0x4 - 0x7 | Chunk #1 size on cache_ps3.dat |
| 0x8 - 0xB | Chunk #2 size on cache_ps3.dat |
| 0xC - 0xF | Chunk #3 size on cache_ps3.dat |
| ... |

## Usage 
### Requirements
- Python 3.4+.
- Files found in [releases](https://github.com/Scirvir/MSMV-unpacker/releases).
- cache_ps3.dat and cache_ps3.txt from the game.

Unpacking:
```
python MS-unpacker.py --mode unpack
```

Repacking:
```
python MS-unpacker.py --mode repack
```
Launch either of these with the `-h` flag for additional information. Both of these will search in, and save to, the current directory if you don't specify something else.

### Support
- NTSC-U [BCUS-98137] 1.00
- PAL [BCES-00006] 1.00

## TODO

The main obstacle right now is figuring how the hash is calculated. This would mean:
- `cache_ps3.txt` no longer needed for splitting the uncompressed blob into individual files.
- Support for the 3.10 versions and the Japanese release [BCJS-30004], neither of which contain `cache_ps3.txt`.

## Disclaimer

The unpacking algorithm was minimally modified from the output of the decompiled code the game uses for the same purpose. Credit to the developers at Evolution Studios who made the original.