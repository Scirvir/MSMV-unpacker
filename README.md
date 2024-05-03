# MotorStorm RA unpacker

Unpacks asset archive from MotorStorm, cache_ps3.dat 

### RA structure:
| Offset | Value |
|-|-|
| 0x0 | RA header `52 41 00 05` |
| 0x4 | Unpacked blob size. Always `0x8000` except for the last chunk |
| 0x8 | Packed size including header . Add `0x10` to this value to get offset of next packed blob |
| 0xd | Whether this chunk is uncompressed or not |

### Useful stuff
```
gcc -shared -o src/evoUnpack.dll src/evo.Unpack.c
```
```
writeRegionToFile('D:\\github\\MSMV-unpack\\uncompressedBlob0.bin',0x340060E40,0x8000)
```