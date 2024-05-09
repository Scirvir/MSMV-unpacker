#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned int CHUNK_OFFSET = 0x0;
unsigned int BLOB_SIZE = 0x0000;

unsigned long get_file_size(char* filepath){
  unsigned long length = 0;
  FILE * f = fopen (filepath, "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
  }

  return length;
}

char* read_file(char* filepath);

char* Unpack(char* param_1, char* param_2){
  bool bVar1;
  char bVar2;
  unsigned char bVar3;
  unsigned char bVar4;
  char bVar5;
  unsigned int uVar6;
  unsigned short int unpackedBlobSize;
  unsigned char *puVar8;
  unsigned short int uVar9;
  int16_t uVar10;
  unsigned int uVar11;
  unsigned short int uVar12;
  unsigned char uVar13;
  unsigned long long uVar14;
  unsigned short int uVar15;
  unsigned short int iVar16;
  char *pbVar17;
  char *pbVar20;
  unsigned long lVar18;
  unsigned long long uVar19;
  unsigned short int uVar21;
  unsigned short uVar22;
  unsigned short int iVar23;
  short int iVar24;
  unsigned char bVar27;
  char cVar28;
  unsigned short int lVar25;
  unsigned short int  iVar26;
  char *pbVar29;
  unsigned char *uVar30;
  unsigned short int iVar31;
  unsigned short int lVar32;
  unsigned short int lVar33;
  unsigned int in_vr0_32_0 = 0xFFFFFFFF;
  unsigned int in_vr0_32_1 = 0xFFFFFFFF;
  unsigned int in_vr0_32_2 = 0xFFFFFFFF;
  unsigned int in_vr0_32_3 = 0xFFFFFFFF;
  char local_f80[256];
  char abStack_e80[256];
  char abStack_d80[256];
  int local_c80[128];
  char abStack_a80[512];
  unsigned int auStack_880[128];
  char abStack_680[512];
  int auStack_480[128];
  char abStack_280[512];

  unsigned char* ab280 = abStack_280;
  unsigned char* ab680 = abStack_680;
  unsigned char* aba80 = abStack_a80;
  unsigned char* abd80 = abStack_d80;
  unsigned char* abe80 = abStack_e80;
  unsigned char* au480 = auStack_480;
  unsigned char* au880 = auStack_880;
  unsigned char* c80 = local_c80;
  unsigned char* f80 = local_f80;

  if ((((param_2 == (char *)0x0) || (*param_2 != 'R')) || (param_2[1] != 'A')) ||
      ((param_2[2] != '\0' || (param_2[3] != '\x05')))) {
    uVar13 = 0;
  }
  else
  {
    iVar23 = 1;
    pbVar20 = (char *)(param_2 + 0x10);
    unpackedBlobSize = (char)param_2[7];
    unpackedBlobSize = unpackedBlobSize | (char)param_2[6] << 8;
    BLOB_SIZE = unpackedBlobSize;
    uVar13 = 0;
    param_1 = (unsigned char*) calloc(unpackedBlobSize, sizeof(unsigned char));
    uVar30 = param_1;
    if (param_2[0xd] == '\0')
    {
      while (true)
      {
        iVar23 = iVar23 + -1;
        uVar13 = uVar13 >> 1;
        pbVar29 = pbVar20;
        if (iVar23 == 0)
        {
          pbVar29 = pbVar20 + 1;
          uVar13 = (unsigned long long)*pbVar20;
          iVar23 = 8;
        }
        if ((uVar13 & 1) == 0)
          break;
        bVar2 = *pbVar29;
        bVar3 = pbVar29[1];
        uVar13 = uVar13 >> 1;
        bVar4 = pbVar29[2];
        iVar24 = iVar23 + -2;
        pbVar20 = pbVar29 + 3;
        if (iVar23 == 1)
        {
          uVar13 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar29 + 4;
          iVar24 = 7;
        }
        uVar21 = uVar13 >> 1;
        iVar23 = iVar24 + -1;
        if (iVar24 == 0)
        {
          uVar21 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar20 + 1;
          iVar23 = 7;
        }
        uVar22 = uVar21 >> 1;
        iVar24 = iVar23 + -1;
        uVar11 = (unsigned int)uVar22;
        if (iVar23 == 0)
        {
          bVar27 = *pbVar20;
          uVar22 = (unsigned long long)bVar27;
          pbVar20 = pbVar20 + 1;
          iVar24 = 7;
          uVar11 = (unsigned int)bVar27;
        }
        uVar11 = (uVar11 & 1) + (int)((uVar21 & 1) + (long long)(int)((uVar13 & 1) << 1)) * 2;
        uVar22 = uVar22 >> 1;
        iVar23 = iVar24 + -1;
        if (iVar24 == 0)
        {
          uVar22 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar20 + 1;
          iVar23 = 7;
        }
        iVar24 = iVar23 + -1;
        uVar13 = uVar22 >> 1;
        if (iVar23 == 0)
        {
          uVar13 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar20 + 1;
          iVar24 = 7;
        }
        uVar21 = uVar13 >> 1;
        uVar10 = (unsigned int)uVar21;
        if (iVar24 == 0)
        {
          bVar27 = *pbVar20;
          uVar21 = (unsigned long long)bVar27;
          pbVar20 = pbVar20 + 1;
          iVar24 = 8;
          uVar10 = (unsigned int)bVar27;
        }
        uVar10 = (uVar10 & 1) + (int)((uVar13 & 1) + (long long)(int)((uVar22 & 1) << 1)) * 2;
        bVar1 = bVar4 != 0;
        if (bVar1)
        {
          uVar12 = 0;
          do
          {
            iVar24 = iVar24 + -1;
            uVar21 = uVar21 >> 1;
            uVar6 = uVar11 & 3;
            uVar9 = (unsigned int)uVar21;
            if (iVar24 == 0)
            {
              bVar27 = *pbVar20;
              uVar21 = (unsigned long long)bVar27;
              pbVar20 = pbVar20 + 1;
              iVar24 = 8;
              uVar9 = (unsigned int)bVar27;
            }
            iVar23 = 1;
            iVar26 = 1;
            uVar13 = (unsigned long long)(int)(uVar9 & 1);
            bVar27 = (char)(uVar9 & 1);
            if (uVar11 + 1 != 1)
            {
              if (uVar6 != 0)
              {
                if (uVar6 != 1)
                {
                  if (uVar6 != 2)
                  {
                    iVar24 = iVar24 + -1;
                    uVar21 = uVar21 >> 1;
                    uVar9 = (unsigned int)uVar21;
                    if (iVar24 == 0)
                    {
                      bVar27 = *pbVar20;
                      uVar21 = (unsigned long long)bVar27;
                      pbVar20 = pbVar20 + 1;
                      iVar24 = 8;
                      uVar9 = (unsigned int)bVar27;
                    }
                    uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                    iVar23 = 2;
                  }
                  iVar24 = iVar24 + -1;
                  uVar21 = uVar21 >> 1;
                  uVar9 = (unsigned int)uVar21;
                  if (iVar24 == 0)
                  {
                    bVar27 = *pbVar20;
                    uVar21 = (unsigned long long)bVar27;
                    pbVar20 = pbVar20 + 1;
                    iVar24 = 8;
                    uVar9 = (unsigned int)bVar27;
                  }
                  iVar26 = iVar23 + 1;
                  uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                }
                iVar24 = iVar24 + -1;
                uVar21 = uVar21 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar24 == 0)
                {
                  bVar27 = *pbVar20;
                  uVar21 = (unsigned long long)bVar27;
                  pbVar20 = pbVar20 + 1;
                  iVar24 = 8;
                  uVar9 = (unsigned int)bVar27;
                }
                iVar23 = (uVar9 & 1) + (int)(uVar13 << 1);
                uVar13 = (unsigned long long)iVar23;
                bVar27 = (char)iVar23;
                if (iVar26 + 1 == uVar11 + 1)
                  goto LAB_007865f0;
              }
              lVar18 = ((((unsigned long long)uVar11 << 0x20) >> 0x22) - 1 & 0xffffffff) + 1;
              do
              {
                iVar24 = iVar24 + -1;
                uVar22 = uVar21 >> 1;
                if (iVar24 == 0)
                {
                  uVar22 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = iVar24 + -1;
                uVar14 = uVar22 >> 1;
                if (iVar24 == 0)
                {
                  uVar14 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = iVar24 + -1;
                uVar15 = uVar14 >> 1;
                if (iVar24 == 0)
                {
                  uVar15 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = iVar24 + -1;
                uVar21 = uVar15 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar24 == 0)
                {
                  uVar21 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  uVar9 = (unsigned int)*pbVar20;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = (uVar9 & 1) +
                         (int)(((uVar15 & 1) +
                                    (long long)(int)(((uVar14 & 1) +
                                                         (long long)(int)(((uVar22 & 1) +
                                                                              (long long)(int)((uVar13 & 0xffffffff) << 1) &
                                                                          0xffffffff)
                                                                         << 1) &
                                                     0xffffffff)
                                                    << 1) &
                                0xffffffff)
                               << 1);
                uVar13 = (unsigned long long)iVar23;
                bVar27 = (char)iVar23;
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
          LAB_007865f0:
            iVar24 = iVar24 + -1;
            uVar21 = uVar21 >> 1;
            *(abe80 + uVar12) = bVar27;
            uVar6 = uVar10 & 3;
            uVar9 = (unsigned int)uVar21;
            if (iVar24 == 0)
            {
              bVar27 = *pbVar20;
              uVar21 = (unsigned long long)bVar27;
              pbVar20 = pbVar20 + 1;
              iVar24 = 8;
              uVar9 = (unsigned int)bVar27;
            }
            iVar23 = 1;
            iVar26 = 1;
            uVar13 = (unsigned long long)(int)(uVar9 & 1);
            cVar28 = (char)(uVar9 & 1);
            if (uVar10 + 1 != 1)
            {
              if (uVar6 != 0)
              {
                if (uVar6 != 1)
                {
                  if (uVar6 != 2)
                  {
                    iVar24 = iVar24 + -1;
                    uVar21 = uVar21 >> 1;
                    uVar9 = (unsigned int)uVar21;
                    if (iVar24 == 0)
                    {
                      bVar27 = *pbVar20;
                      uVar21 = (unsigned long long)bVar27;
                      pbVar20 = pbVar20 + 1;
                      iVar24 = 8;
                      uVar9 = (unsigned int)bVar27;
                    }
                    uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                    iVar23 = 2;
                  }
                  iVar24 = iVar24 + -1;
                  uVar21 = uVar21 >> 1;
                  uVar9 = (unsigned int)uVar21;
                  if (iVar24 == 0)
                  {
                    bVar27 = *pbVar20;
                    uVar21 = (unsigned long long)bVar27;
                    pbVar20 = pbVar20 + 1;
                    iVar24 = 8;
                    uVar9 = (unsigned int)bVar27;
                  }
                  iVar26 = iVar23 + 1;
                  uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                }
                iVar24 = iVar24 + -1;
                uVar21 = uVar21 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar24 == 0)
                {
                  bVar27 = *pbVar20;
                  uVar21 = (unsigned long long)bVar27;
                  pbVar20 = pbVar20 + 1;
                  iVar24 = 8;
                  uVar9 = (unsigned int)bVar27;
                }
                iVar23 = (uVar9 & 1) + (int)(uVar13 << 1);
                uVar13 = (unsigned long long)iVar23;
                cVar28 = (char)iVar23;
                if (iVar26 + 1 == uVar10 + 1)
                  goto LAB_00786838;
              }
              lVar18 = ((((unsigned long long)uVar10 << 0x20) >> 0x22) - 1 & 0xffffffff) + 1;
              do
              {
                iVar24 = iVar24 + -1;
                uVar22 = uVar21 >> 1;
                if (iVar24 == 0)
                {
                  uVar22 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = iVar24 + -1;
                uVar14 = uVar22 >> 1;
                if (iVar24 == 0)
                {
                  uVar14 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = iVar24 + -1;
                uVar15 = uVar14 >> 1;
                if (iVar24 == 0)
                {
                  uVar15 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = iVar24 + -1;
                uVar21 = uVar15 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar24 == 0)
                {
                  uVar21 = (unsigned long long)*pbVar20;
                  iVar24 = 8;
                  uVar9 = (unsigned int)*pbVar20;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = (uVar9 & 1) +
                         (int)(((uVar15 & 1) +
                                    (long long)(int)(((uVar14 & 1) +
                                                         (long long)(int)(((uVar22 & 1) +
                                                                              (long long)(int)((uVar13 & 0xffffffff) << 1) &
                                                                          0xffffffff)
                                                                         << 1) &
                                                     0xffffffff)
                                                    << 1) &
                                0xffffffff)
                               << 1);
                uVar13 = (unsigned long long)iVar23;
                cVar28 = (char)iVar23;
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
          LAB_00786838:
            uVar9 = uVar12 + 1;
            *(f80 + uVar12) = cVar28 + 1;
            uVar12 = uVar9;
          } while (bVar4 != uVar9);
        }
        uVar13 = (unsigned long long)local_f80[0];
        if (bVar1)
        {
          uVar22 = 0;
          uVar11 = 0;
          do
          {
            uVar15 = (unsigned long long)*(f80 + uVar11);
            uVar14 = uVar22;
            if (uVar13 != uVar15)
            {
              lVar18 = uVar13 - uVar15;
              uVar13 = uVar13 - 1 & 0xffffffff;
              uVar19 = lVar18 - 1;
              uVar10 = (unsigned int)uVar19 & 7;
              uVar14 = uVar22 >> 1;
              if (uVar15 < uVar13)
              {
                if ((uVar19 & 7) != 0)
                {
                  if (uVar10 != 1)
                  {
                    if (uVar10 != 2)
                    {
                      if (uVar10 != 3)
                      {
                        if (uVar10 != 4)
                        {
                          if (uVar10 != 5)
                          {
                            if (uVar10 != 6)
                            {
                              uVar14 = uVar22 >> 2;
                              uVar13 = uVar13 - 1 & 0xffffffff;
                            }
                            uVar14 = uVar14 >> 1;
                            uVar13 = uVar13 - 1 & 0xffffffff;
                          }
                          uVar14 = uVar14 >> 1;
                          uVar13 = uVar13 - 1 & 0xffffffff;
                        }
                        uVar14 = uVar14 >> 1;
                        uVar13 = uVar13 - 1 & 0xffffffff;
                      }
                      uVar14 = uVar14 >> 1;
                      uVar13 = uVar13 - 1 & 0xffffffff;
                    }
                    uVar14 = uVar14 >> 1;
                    uVar13 = uVar13 - 1 & 0xffffffff;
                  }
                  uVar14 = uVar14 >> 1;
                  uVar13 = uVar13 - 1 & 0xffffffff;
                  if (uVar13 <= uVar15)
                    goto LAB_00786960;
                }
                lVar18 = (((uVar19 << 0x20) >> 0x23) - 1 & 0xffffffff) + 1;
                do
                {
                  uVar14 = uVar14 >> 8;
                  uVar13 = uVar13 - 8 & 0xffffffff;
                  lVar18 = lVar18 + -1;
                } while (lVar18 != 0);
              }
            }
            LAB_00786960:
            uVar10 = uVar11 + 1;
            *(abd80 + uVar11) = (char)uVar14;
            uVar22 = uVar14 + 1 & 0xffffffff;
            uVar11 = uVar10;
          } while (bVar4 != uVar10);
        }
        lVar18 = 4;
        iVar23 = 0;
        do
        {
          *(auStack_880 + iVar23 + 3) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 2) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 1) = in_vr0_32_1;
          *(auStack_880 + iVar23) = in_vr0_32_0;
          *(auStack_880 + iVar23 + 7) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 6) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 5) = in_vr0_32_1;
          *(auStack_880 + iVar23 + 4) = in_vr0_32_0;
          *(auStack_880 + iVar23 + 11) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 10) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 9) = in_vr0_32_1;
          *(auStack_880 + iVar23 + 8) = in_vr0_32_0;
          *(auStack_880 + iVar23 + 15) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 14) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 13) = in_vr0_32_1;
          *(auStack_880 + iVar23 + 12) = in_vr0_32_0;
          *(auStack_880 + iVar23 + 19) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 18) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 17) = in_vr0_32_1;
          *(auStack_880 + iVar23 + 16) = in_vr0_32_0;
          *(auStack_880 + iVar23 + 23) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 22) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 21) = in_vr0_32_1;
          *(auStack_880 + iVar23 + 20) = in_vr0_32_0;
          *(auStack_880 + iVar23 + 27) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 26) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 25) = in_vr0_32_1;
          *(auStack_880 + iVar23 + 24) = in_vr0_32_0;
          *(auStack_880 + iVar23 + 31) = in_vr0_32_3;
          *(auStack_880 + iVar23 + 30) = in_vr0_32_2;
          *(auStack_880 + iVar23 + 29) = in_vr0_32_1;
          *(auStack_880 + iVar23 + 28) = in_vr0_32_0;
          lVar18 = lVar18 + -1;
          iVar23 = iVar23 + 32;
        } while (lVar18 != 0);
        if (bVar1)
        {
          lVar18 = 2;
          uVar11 = 0;
          do
          {
            bVar27 = *(f80 + uVar11);
            uVar10 = (unsigned int)bVar27;
            if ((unsigned long long)bVar27 != 0)
            {
              uVar13 = (unsigned long long)bVar27 - 1;
              bVar5 = *(abd80 + uVar11);
              lVar25 = 0;
              lVar32 = lVar18;
              if ((uVar13 & 1) != 0)
              {
                uVar10 = bVar27 - 1;
                uVar12 = (unsigned int)((bVar5 >> (uVar10 & 0x3f) & 1) != 0);
                bVar27 = *(au880 + uVar12);
                lVar25 = (unsigned char)bVar27 << 1;
                if (bVar27 == 0xff)
                {
                  lVar32 = (long long)((int)lVar18 + 2);
                  *(au880 + uVar12) = (lVar18 >> 1);
                  lVar25 = lVar18;
                }
                if ((int)lVar25 < 0)
                  break;
              }
              uVar10 = uVar10 - 1;
              lVar18 = (uVar13 >> 1 & 0x7fffffff) + 1;
              while (true)
              {
                iVar23 = (int)lVar25;
                if ((bVar5 >> (uVar10 & 0x3f) & 1) != 0)
                {
                  iVar23 = iVar23 + 1;
                }
                iVar31 = (int)lVar32;
                iVar26 = (*(au880 + iVar23)) << 1;
                if ((iVar26 >> 1) == 0xff)
                {
                  lVar32 = (long long)(iVar31 + 2);
                  *(au880 + iVar23) = *(au880 + iVar23) & (unsigned char) (iVar31 >> 1); /* write single byte to int array*/
                  iVar26 = iVar31;
                }
                if ((iVar26 < 0) || (iVar23 < 0))
                  goto LAB_00786bec;
                lVar18 = lVar18 + -1;
                iVar31 = (int)lVar32;
                if (lVar18 == 0)
                  break;
                if ((bVar5 >> (uVar10 - 1 & 0x3f) & 1) != 0)
                {
                  iVar26 = iVar26 + 1;
                }
                lVar25 = (*(au880 + iVar26)) << 1;
                lVar33 = lVar32;
                if ((lVar25 >> 1) == 0xff)
                {
                  lVar33 = (long long)(iVar31 + 2);
                  *(au880 + iVar26) = *(au880 + iVar26) & (unsigned char) (iVar31 >> 1);
                  lVar25 = lVar32;
                }
                if (((int)lVar25 < 0) || (iVar26 < 0))
                  goto LAB_00786bec;
                uVar10 = uVar10 - 2;
                lVar32 = lVar33;
              }
              lVar25 = (*(au880 + iVar23)) << 1;
              lVar18 = lVar32;
              if (iVar31 + -2 == (int)lVar25)
              {
                lVar18 = lVar25;
              }
              (*(au880 + iVar23)) = 0;
              (*(ab680 + iVar23)) = (*(abe80 + uVar11));
            }
            uVar11 = uVar11 + 1;
          } while (bVar4 != uVar11);
        }
        LAB_00786bec:
        bVar4 = *pbVar20;
        uVar21 = uVar21 >> 1;
        pbVar29 = pbVar20 + 1;
        iVar23 = iVar24 + -2;
        if (iVar24 == 1)
        {
          uVar21 = (unsigned long long)*pbVar29;
          pbVar29 = pbVar20 + 2;
          iVar23 = 7;
        }
        uVar13 = uVar21 >> 1;
        iVar24 = iVar23 + -1;
        if (iVar23 == 0)
        {
          uVar13 = (unsigned long long)*pbVar29;
          pbVar29 = pbVar29 + 1;
          iVar24 = 7;
        }
        uVar22 = uVar13 >> 1;
        iVar23 = iVar24 + -1;
        uVar11 = (unsigned int)uVar22;
        if (iVar24 == 0)
        {
          bVar27 = *pbVar29;
          uVar22 = (unsigned long long)bVar27;
          pbVar29 = pbVar29 + 1;
          iVar23 = 7;
          uVar11 = (unsigned int)bVar27;
        }
        uVar11 = (uVar11 & 1) + (int)((uVar13 & 1) + (long long)(int)((uVar21 & 1) << 1)) * 2;
        uVar22 = uVar22 >> 1;
        iVar24 = iVar23 + -1;
        if (iVar23 == 0)
        {
          uVar22 = (unsigned long long)*pbVar29;
          pbVar29 = pbVar29 + 1;
          iVar24 = 7;
        }
        iVar23 = iVar24 + -1;
        uVar13 = uVar22 >> 1;
        if (iVar24 == 0)
        {
          uVar13 = (unsigned long long)*pbVar29;
          pbVar29 = pbVar29 + 1;
          iVar23 = 7;
        }
        uVar21 = uVar13 >> 1;
        uVar10 = (unsigned int)uVar21;
        if (iVar23 == 0)
        {
          bVar27 = *pbVar29;
          uVar21 = (unsigned long long)bVar27;
          pbVar29 = pbVar29 + 1;
          iVar23 = 8;
          uVar10 = (unsigned int)bVar27;
        }
        uVar10 = (uVar10 & 1) + (int)((uVar13 & 1) + (long long)(int)((uVar22 & 1) << 1)) * 2;
        bVar1 = bVar4 != 0;
        if (bVar1)
        {
          uVar12 = 0;
          do
          {
            iVar23 = iVar23 + -1;
            uVar21 = uVar21 >> 1;
            uVar6 = uVar11 & 3;
            uVar9 = (unsigned int)uVar21;
            if (iVar23 == 0)
            {
              bVar27 = *pbVar29;
              uVar21 = (unsigned long long)bVar27;
              pbVar29 = pbVar29 + 1;
              iVar23 = 8;
              uVar9 = (unsigned int)bVar27;
            }
            iVar24 = 1;
            iVar26 = 1;
            uVar13 = (unsigned long long)(int)(uVar9 & 1);
            bVar27 = (char)(uVar9 & 1);
            if (uVar11 + 1 != 1)
            {
              if (uVar6 != 0)
              {
                if (uVar6 != 1)
                {
                  if (uVar6 != 2)
                  {
                    iVar23 = iVar23 + -1;
                    uVar21 = uVar21 >> 1;
                    uVar9 = (unsigned int)uVar21;
                    if (iVar23 == 0)
                    {
                      bVar27 = *pbVar29;
                      uVar21 = (unsigned long long)bVar27;
                      pbVar29 = pbVar29 + 1;
                      iVar23 = 8;
                      uVar9 = (unsigned int)bVar27;
                    }
                    uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                    iVar24 = 2;
                  }
                  iVar23 = iVar23 + -1;
                  uVar21 = uVar21 >> 1;
                  uVar9 = (unsigned int)uVar21;
                  if (iVar23 == 0)
                  {
                    bVar27 = *pbVar29;
                    uVar21 = (unsigned long long)bVar27;
                    pbVar29 = pbVar29 + 1;
                    iVar23 = 8;
                    uVar9 = (unsigned int)bVar27;
                  }
                  iVar26 = iVar24 + 1;
                  uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                }
                iVar23 = iVar23 + -1;
                uVar21 = uVar21 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar23 == 0)
                {
                  bVar27 = *pbVar29;
                  uVar21 = (unsigned long long)bVar27;
                  pbVar29 = pbVar29 + 1;
                  iVar23 = 8;
                  uVar9 = (unsigned int)bVar27;
                }
                iVar24 = (uVar9 & 1) + (int)(uVar13 << 1);
                uVar13 = (unsigned long long)iVar24;
                bVar27 = (char)iVar24;
                if (iVar26 + 1 == uVar11 + 1)
                  goto LAB_00786f78;
              }
              lVar18 = ((((unsigned long long)uVar11 << 0x20) >> 0x22) - 1 & 0xffffffff) + 1;
              do
              {
                iVar23 = iVar23 + -1;
                uVar22 = uVar21 >> 1;
                if (iVar23 == 0)
                {
                  uVar22 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  pbVar29 = pbVar29 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar14 = uVar22 >> 1;
                if (iVar23 == 0)
                {
                  uVar14 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  pbVar29 = pbVar29 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar15 = uVar14 >> 1;
                if (iVar23 == 0)
                {
                  uVar15 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  pbVar29 = pbVar29 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar21 = uVar15 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar23 == 0)
                {
                  uVar21 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  uVar9 = (unsigned int)*pbVar29;
                  pbVar29 = pbVar29 + 1;
                }
                iVar24 = (uVar9 & 1) +
                         (int)(((uVar15 & 1) +
                                    (long long)(int)(((uVar14 & 1) +
                                                         (long long)(int)(((uVar22 & 1) +
                                                                              (long long)(int)((uVar13 & 0xffffffff) << 1) &
                                                                          0xffffffff)
                                                                         << 1) &
                                                     0xffffffff)
                                                    << 1) &
                                0xffffffff)
                               << 1);
                uVar13 = (unsigned long long)iVar24;
                bVar27 = (char)iVar24;
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
            LAB_00786f78:
            iVar23 = iVar23 + -1;
            uVar21 = uVar21 >> 1;
            *(abe80 + uVar12) = bVar27;
            uVar6 = uVar10 & 3;
            uVar9 = (unsigned int)uVar21;
            if (iVar23 == 0)
            {
              bVar27 = *pbVar29;
              uVar21 = (unsigned long long)bVar27;
              pbVar29 = pbVar29 + 1;
              iVar23 = 8;
              uVar9 = (unsigned int)bVar27;
            }
            iVar24 = 1;
            iVar26 = 1;
            uVar13 = (unsigned long long)(int)(uVar9 & 1);
            cVar28 = (char)(uVar9 & 1);
            if (uVar10 + 1 != 1)
            {
              if (uVar6 != 0)
              {
                if (uVar6 != 1)
                {
                  if (uVar6 != 2)
                  {
                    iVar23 = iVar23 + -1;
                    uVar21 = uVar21 >> 1;
                    uVar9 = (unsigned int)uVar21;
                    if (iVar23 == 0)
                    {
                      bVar27 = *pbVar29;
                      uVar21 = (unsigned long long)bVar27;
                      pbVar29 = pbVar29 + 1;
                      iVar23 = 8;
                      uVar9 = (unsigned int)bVar27;
                    }
                    uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                    iVar24 = 2;
                  }
                  iVar23 = iVar23 + -1;
                  uVar21 = uVar21 >> 1;
                  uVar9 = (unsigned int)uVar21;
                  if (iVar23 == 0)
                  {
                    bVar27 = *pbVar29;
                    uVar21 = (unsigned long long)bVar27;
                    pbVar29 = pbVar29 + 1;
                    iVar23 = 8;
                    uVar9 = (unsigned int)bVar27;
                  }
                  iVar26 = iVar24 + 1;
                  uVar13 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar13 << 1));
                }
                iVar23 = iVar23 + -1;
                uVar21 = uVar21 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar23 == 0)
                {
                  bVar27 = *pbVar29;
                  uVar21 = (unsigned long long)bVar27;
                  pbVar29 = pbVar29 + 1;
                  iVar23 = 8;
                  uVar9 = (unsigned int)bVar27;
                }
                iVar24 = (uVar9 & 1) + (int)(uVar13 << 1);
                uVar13 = (unsigned long long)iVar24;
                cVar28 = (char)iVar24;
                if (iVar26 + 1 == uVar10 + 1)
                  goto LAB_007871c0;
              }
              lVar18 = ((((unsigned long long)uVar10 << 0x20) >> 0x22) - 1 & 0xffffffff) + 1;
              do
              {
                iVar23 = iVar23 + -1;
                uVar22 = uVar21 >> 1;
                if (iVar23 == 0)
                {
                  uVar22 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  pbVar29 = pbVar29 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar14 = uVar22 >> 1;
                if (iVar23 == 0)
                {
                  uVar14 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  pbVar29 = pbVar29 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar15 = uVar14 >> 1;
                if (iVar23 == 0)
                {
                  uVar15 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  pbVar29 = pbVar29 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar21 = uVar15 >> 1;
                uVar9 = (unsigned int)uVar21;
                if (iVar23 == 0)
                {
                  uVar21 = (unsigned long long)*pbVar29;
                  iVar23 = 8;
                  uVar9 = (unsigned int)*pbVar29;
                  pbVar29 = pbVar29 + 1;
                }
                iVar24 = (uVar9 & 1) +
                         (int)(((uVar15 & 1) +
                                    (long long)(int)(((uVar14 & 1) +
                                                         (long long)(int)(((uVar22 & 1) +
                                                                              (long long)(int)((uVar13 & 0xffffffff) << 1) &
                                                                          0xffffffff)
                                                                         << 1) &
                                                     0xffffffff)
                                                    << 1) &
                                0xffffffff)
                               << 1);
                uVar13 = (unsigned long long)iVar24;
                cVar28 = (char)iVar24;
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
            LAB_007871c0:
            uVar9 = uVar12 + 1;
            *(f80 + uVar12) = cVar28 + 1;
            uVar12 = uVar9;
          } while (bVar4 != uVar9);
        }
        uVar13 = (unsigned long long)local_f80[0];
        if (bVar1)
        {
          uVar22 = 0;
          uVar11 = 0;
          do
          {
            uVar15 = (unsigned long long)*(f80 + uVar11);
            uVar14 = uVar22;
            if (uVar13 != uVar15)
            {
              lVar18 = uVar13 - uVar15;
              uVar13 = uVar13 - 1 & 0xffffffff;
              uVar19 = lVar18 - 1;
              uVar10 = (unsigned int)uVar19 & 7;
              uVar14 = uVar22 >> 1;
              if (uVar15 < uVar13)
              {
                if ((uVar19 & 7) != 0)
                {
                  if (uVar10 != 1)
                  {
                    if (uVar10 != 2)
                    {
                      if (uVar10 != 3)
                      {
                        if (uVar10 != 4)
                        {
                          if (uVar10 != 5)
                          {
                            if (uVar10 != 6)
                            {
                              uVar14 = uVar22 >> 2;
                              uVar13 = uVar13 - 1 & 0xffffffff;
                            }
                            uVar14 = uVar14 >> 1;
                            uVar13 = uVar13 - 1 & 0xffffffff;
                          }
                          uVar14 = uVar14 >> 1;
                          uVar13 = uVar13 - 1 & 0xffffffff;
                        }
                        uVar14 = uVar14 >> 1;
                        uVar13 = uVar13 - 1 & 0xffffffff;
                      }
                      uVar14 = uVar14 >> 1;
                      uVar13 = uVar13 - 1 & 0xffffffff;
                    }
                    uVar14 = uVar14 >> 1;
                    uVar13 = uVar13 - 1 & 0xffffffff;
                  }
                  uVar14 = uVar14 >> 1;
                  uVar13 = uVar13 - 1 & 0xffffffff;
                  if (uVar13 <= uVar15)
                    goto LAB_007872e8;
                }
                lVar18 = (((uVar19 << 0x20) >> 0x23) - 1 & 0xffffffff) + 1;
                do
                {
                  uVar14 = uVar14 >> 8;
                  uVar13 = uVar13 - 8 & 0xffffffff;
                  lVar18 = lVar18 + -1;
                } while (lVar18 != 0);
              }
            }
            LAB_007872e8:
            uVar10 = uVar11 + 1;
            *(abd80 + uVar11) = (char)uVar14;
            uVar22 = uVar14 + 1 & 0xffffffff;
            uVar11 = uVar10;
          } while (bVar4 != uVar10);
        }
        lVar18 = 4;
        iVar24 = 0;
        do
        {
          *(auStack_480 + iVar24 + 3) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 2) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 1) = in_vr0_32_1;
          *(auStack_480 + iVar24) =  in_vr0_32_0;
          *(auStack_480 + iVar24 + 7) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 6) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 5) = in_vr0_32_1;
          *(auStack_480 + iVar24 + 4) = in_vr0_32_0;
          *(auStack_480 + iVar24 + 11) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 10) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 9) = in_vr0_32_1;
          *(auStack_480 + iVar24 + 8) = in_vr0_32_0;
          *(auStack_480 + iVar24 + 15) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 14) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 13) = in_vr0_32_1;
          *(auStack_480 + iVar24 + 12) = in_vr0_32_0;
          *(auStack_480 + iVar24 + 19) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 18) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 17) = in_vr0_32_1;
          *(auStack_480 + iVar24 + 16) = in_vr0_32_0;
          *(auStack_480 + iVar24 + 23) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 22) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 21) = in_vr0_32_1;
          *(auStack_480 + iVar24 + 20) = in_vr0_32_0;
          *(auStack_480 + iVar24 + 27) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 26) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 25) = in_vr0_32_1;
          *(auStack_480 + iVar24 + 24) = in_vr0_32_0;
          *(auStack_480 + iVar24 + 31) = in_vr0_32_3;
          *(auStack_480 + iVar24 + 30) = in_vr0_32_2;
          *(auStack_480 + iVar24 + 29) = in_vr0_32_1;
          *(auStack_480 + iVar24 + 28) = in_vr0_32_0;
          lVar18 = lVar18 + -1;
          iVar24 = iVar24 + 32;
        } while (lVar18 != 0);
        if (bVar1)
        {
          lVar18 = 2;
          uVar11 = 0;
          do
          {
            bVar27 = *(f80 + uVar11);
            uVar10 = (unsigned int)bVar27;
            if ((unsigned long long)bVar27 != 0)
            {
              uVar13 = (unsigned long long)bVar27 - 1;
              bVar5 = *(abd80 + uVar11);
              lVar25 = 0;
              lVar32 = lVar18;
              if ((uVar13 & 1) != 0)
              {
                uVar10 = bVar27 - 1;
                uVar12 = (unsigned int)((bVar5 >> (uVar10 & 0x3f) & 1) != 0);
                bVar27 = *(au480 + uVar12);
                lVar25 = (unsigned long long)bVar27 << 1;
                if (bVar27 == 0xff)
                {
                  lVar32 = (long long)((int)lVar18 + 2);
                  *(au480 + uVar12) = (lVar18 >> 1);
                  lVar25 = lVar18;
                }
                if ((int)lVar25 < 0)
                  break;
              }
              uVar10 = uVar10 - 1;
              lVar18 = (uVar13 >> 1 & 0x7fffffff) + 1;
              while (true)
              {
                iVar24 = (int)lVar25;
                if ((bVar5 >> (uVar10 & 0x3f) & 1) != 0)
                {
                  iVar24 = iVar24 + 1;
                }
                iVar31 = (int)lVar32;
                iVar26 = (*(au480 + iVar24)) << 1;
                if ((iVar26 >> 1) == 0xff)
                {
                  lVar32 = (long long)(iVar31 + 2);
                  *(au480 + iVar24) = *(au480 + iVar24) & (unsigned char) (iVar31 >> 1);
                  iVar26 = iVar31;
                }
                if ((iVar26 < 0) || (iVar24 < 0))
                  goto LAB_007031d0;
                lVar18 = lVar18 + -1;
                iVar31 = (int)lVar32;
                if (lVar18 == 0)
                  break;
                if ((bVar5 >> (uVar10 - 1 & 0x3f) & 1) != 0)
                {
                  iVar26 = iVar26 + 1;
                }
                lVar25 = (*(au480 + iVar26)) << 1;
                lVar33 = lVar32;
                if ((lVar25 >> 1) == 0xff)
                {
                  lVar33 = (long long)(iVar31 + 2);
                  *(au480 + iVar26) = *(au480 + iVar26) & (unsigned char) (iVar31 >> 1);
                  lVar25 = lVar32;
                }
                if (((int)lVar25 < 0) || (iVar26 < 0))
                  goto LAB_007031d0;
                uVar10 = uVar10 - 2;
                lVar32 = lVar33;
              }
              lVar25 = (*(au480 + iVar24)) << 1;
              lVar18 = lVar32;
              if (iVar31 + -2 == (int)lVar25)
              {
                lVar18 = lVar25;
              }
              (*(au480 + iVar24)) = 0;
              (*(ab280 + iVar24)) = (*(abe80 + uVar11));
            }
            uVar11 = uVar11 + 1;
          } while (bVar4 != uVar11);
        }
        LAB_007031d0:
        bVar4 = *pbVar29;
        uVar21 = uVar21 >> 1;
        pbVar20 = pbVar29 + 1;
        iVar24 = iVar23 + -2;
        if (iVar23 == 1)
        {
          uVar21 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar29 + 2;
          iVar24 = 7;
        }
        uVar13 = uVar21 >> 1;
        iVar23 = iVar24 + -1;
        if (iVar24 == 0)
        {
          uVar13 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar20 + 1;
          iVar23 = 7;
        }
        uVar22 = uVar13 >> 1;
        iVar24 = iVar23 + -1;
        uVar11 = (unsigned int)uVar22;
        if (iVar23 == 0)
        {
          bVar27 = *pbVar20;
          uVar22 = (unsigned long long)bVar27;
          pbVar20 = pbVar20 + 1;
          iVar24 = 7;
          uVar11 = (unsigned int)bVar27;
        }
        uVar11 = (uVar11 & 1) + (int)((uVar13 & 1) + (long long)(int)((uVar21 & 1) << 1)) * 2;
        uVar22 = uVar22 >> 1;
        iVar26 = iVar24 + -1;
        if (iVar24 == 0)
        {
          uVar22 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar20 + 1;
          iVar26 = 7;
        }
        iVar23 = iVar26 + -1;
        uVar21 = uVar22 >> 1;
        if (iVar26 == 0)
        {
          uVar21 = (unsigned long long)*pbVar20;
          pbVar20 = pbVar20 + 1;
          iVar23 = 7;
        }
        uVar13 = uVar21 >> 1;
        uVar10 = (unsigned int)uVar13;
        if (iVar23 == 0)
        {
          bVar27 = *pbVar20;
          uVar13 = (unsigned long long)bVar27;
          pbVar20 = pbVar20 + 1;
          iVar23 = 8;
          uVar10 = (unsigned int)bVar27;
        }
        uVar10 = (uVar10 & 1) + (int)((uVar21 & 1) + (long long)(int)((uVar22 & 1) << 1)) * 2;
        bVar1 = bVar4 != 0;
        if (bVar1)
        {
          uVar12 = 0;
          do
          {
            iVar23 = iVar23 + -1;
            uVar13 = uVar13 >> 1;
            uVar6 = uVar11 & 3;
            uVar9 = (unsigned int)uVar13;
            if (iVar23 == 0)
            {
              bVar27 = *pbVar20;
              uVar13 = (unsigned long long)bVar27;
              pbVar20 = pbVar20 + 1;
              iVar23 = 8;
              uVar9 = (unsigned int)bVar27;
            }
            iVar24 = 1;
            iVar26 = 1;
            uVar21 = (unsigned long long)(int)(uVar9 & 1);
            bVar27 = (char)(uVar9 & 1);
            if (uVar11 + 1 != 1)
            {
              if (uVar6 != 0)
              {
                if (uVar6 != 1)
                {
                  if (uVar6 != 2)
                  {
                    iVar23 = iVar23 + -1;
                    uVar13 = uVar13 >> 1;
                    uVar9 = (unsigned int)uVar13;
                    if (iVar23 == 0)
                    {
                      bVar27 = *pbVar20;
                      uVar13 = (unsigned long long)bVar27;
                      pbVar20 = pbVar20 + 1;
                      iVar23 = 8;
                      uVar9 = (unsigned int)bVar27;
                    }
                    uVar21 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar21 << 1));
                    iVar24 = 2;
                  }
                  iVar23 = iVar23 + -1;
                  uVar13 = uVar13 >> 1;
                  uVar9 = (unsigned int)uVar13;
                  if (iVar23 == 0)
                  {
                    bVar27 = *pbVar20;
                    uVar13 = (unsigned long long)bVar27;
                    pbVar20 = pbVar20 + 1;
                    iVar23 = 8;
                    uVar9 = (unsigned int)bVar27;
                  }
                  iVar26 = iVar24 + 1;
                  uVar21 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar21 << 1));
                }
                iVar23 = iVar23 + -1;
                uVar13 = uVar13 >> 1;
                uVar9 = (unsigned int)uVar13;
                if (iVar23 == 0)
                {
                  bVar27 = *pbVar20;
                  uVar13 = (unsigned long long)bVar27;
                  pbVar20 = pbVar20 + 1;
                  iVar23 = 8;
                  uVar9 = (unsigned int)bVar27;
                }
                iVar24 = (uVar9 & 1) + (int)(uVar21 << 1);
                uVar21 = (unsigned long long)iVar24;
                bVar27 = (char)iVar24;
                if (iVar26 + 1 == uVar11 + 1)
                  goto LAB_00787900;
              }
              lVar18 = ((((unsigned long long)uVar11 << 0x20) >> 0x22) - 1 & 0xffffffff) + 1;
              do
              {
                iVar23 = iVar23 + -1;
                uVar22 = uVar13 >> 1;
                if (iVar23 == 0)
                {
                  uVar22 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar14 = uVar22 >> 1;
                if (iVar23 == 0)
                {
                  uVar14 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar15 = uVar14 >> 1;
                if (iVar23 == 0)
                {
                  uVar15 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar13 = uVar15 >> 1;
                uVar9 = (unsigned int)uVar13;
                if (iVar23 == 0)
                {
                  uVar13 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  uVar9 = (unsigned int)*pbVar20;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = (uVar9 & 1) +
                         (int)(((uVar15 & 1) +
                                    (long long)(int)(((uVar14 & 1) +
                                                         (long long)(int)(((uVar22 & 1) +
                                                                              (long long)(int)((uVar21 & 0xffffffff) << 1) &
                                                                          0xffffffff)
                                                                         << 1) &
                                                     0xffffffff)
                                                    << 1) &
                                0xffffffff)
                               << 1);
                uVar21 = (unsigned long long)iVar24;
                bVar27 = (char)iVar24;
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
            LAB_00787900:
            iVar23 = iVar23 + -1;
            uVar13 = uVar13 >> 1;
            *(abe80 + uVar12) = bVar27;
            uVar6 = uVar10 & 3;
            uVar9 = (unsigned int)uVar13;
            if (iVar23 == 0)
            {
              bVar27 = *pbVar20;
              uVar13 = (unsigned long long)bVar27;
              pbVar20 = pbVar20 + 1;
              iVar23 = 8;
              uVar9 = (unsigned int)bVar27;
            }
            iVar24 = 1;
            iVar26 = 1;
            uVar21 = (unsigned long long)(int)(uVar9 & 1);
            cVar28 = (char)(uVar9 & 1);
            if (uVar10 + 1 != 1)
            {
              if (uVar6 != 0)
              {
                if (uVar6 != 1)
                {
                  if (uVar6 != 2)
                  {
                    iVar23 = iVar23 + -1;
                    uVar13 = uVar13 >> 1;
                    uVar9 = (unsigned int)uVar13;
                    if (iVar23 == 0)
                    {
                      bVar27 = *pbVar20;
                      uVar13 = (unsigned long long)bVar27;
                      pbVar20 = pbVar20 + 1;
                      iVar23 = 8;
                      uVar9 = (unsigned int)bVar27;
                    }
                    uVar21 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar21 << 1));
                    iVar24 = 2;
                  }
                  iVar23 = iVar23 + -1;
                  uVar13 = uVar13 >> 1;
                  uVar9 = (unsigned int)uVar13;
                  if (iVar23 == 0)
                  {
                    bVar27 = *pbVar20;
                    uVar13 = (unsigned long long)bVar27;
                    pbVar20 = pbVar20 + 1;
                    iVar23 = 8;
                    uVar9 = (unsigned int)bVar27;
                  }
                  iVar26 = iVar24 + 1;
                  uVar21 = (unsigned long long)(int)((uVar9 & 1) + (int)(uVar21 << 1));
                }
                iVar23 = iVar23 + -1;
                uVar13 = uVar13 >> 1;
                uVar9 = (unsigned int)uVar13;
                if (iVar23 == 0)
                {
                  bVar27 = *pbVar20;
                  uVar13 = (unsigned long long)bVar27;
                  pbVar20 = pbVar20 + 1;
                  iVar23 = 8;
                  uVar9 = (unsigned int)bVar27;
                }
                iVar24 = (uVar9 & 1) + (int)(uVar21 << 1);
                uVar21 = (unsigned long long)iVar24;
                cVar28 = (char)iVar24;
                if (iVar26 + 1 == uVar10 + 1)
                  goto LAB_00787b48;
              }
              lVar18 = ((((unsigned long long)uVar10 << 0x20) >> 0x22) - 1 & 0xffffffff) + 1;
              do
              {
                iVar23 = iVar23 + -1;
                uVar22 = uVar13 >> 1;
                if (iVar23 == 0)
                {
                  uVar22 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar14 = uVar22 >> 1;
                if (iVar23 == 0)
                {
                  uVar14 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar15 = uVar14 >> 1;
                if (iVar23 == 0)
                {
                  uVar15 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  pbVar20 = pbVar20 + 1;
                }
                iVar23 = iVar23 + -1;
                uVar13 = uVar15 >> 1;
                uVar9 = (unsigned int)uVar13;
                if (iVar23 == 0)
                {
                  uVar13 = (unsigned long long)*pbVar20;
                  iVar23 = 8;
                  uVar9 = (unsigned int)*pbVar20;
                  pbVar20 = pbVar20 + 1;
                }
                iVar24 = (uVar9 & 1) +
                         (int)(((uVar15 & 1) +
                                    (long long)(int)(((uVar14 & 1) +
                                                         (long long)(int)(((uVar22 & 1) +
                                                                              (long long)(int)((uVar21 & 0xffffffff) << 1) &
                                                                          0xffffffff)
                                                                         << 1) &
                                                     0xffffffff)
                                                    << 1) &
                                0xffffffff)
                               << 1);
                uVar21 = (unsigned long long)iVar24;
                cVar28 = (char)iVar24;
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
            LAB_00787b48:
            uVar9 = uVar12 + 1;
            *(f80 + uVar12) = cVar28 + 1;
            uVar12 = uVar9;
          } while (bVar4 != uVar9);
        }
        uVar21 = (unsigned long long)local_f80[0];
        if (bVar1)
        {
          uVar22 = 0;
          uVar11 = 0;
          do
          {
            uVar15 = (unsigned long long)*(f80 + uVar11);
            uVar14 = uVar22;
            if (uVar21 != uVar15)
            {
              lVar18 = uVar21 - uVar15;
              uVar21 = uVar21 - 1 & 0xffffffff;
              uVar19 = lVar18 - 1;
              uVar10 = (unsigned int)uVar19 & 7;
              uVar14 = uVar22 >> 1;
              if (uVar15 < uVar21)
              {
                if ((uVar19 & 7) != 0)
                {
                  if (uVar10 != 1)
                  {
                    if (uVar10 != 2)
                    {
                      if (uVar10 != 3)
                      {
                        if (uVar10 != 4)
                        {
                          if (uVar10 != 5)
                          {
                            if (uVar10 != 6)
                            {
                              uVar14 = uVar22 >> 2;
                              uVar21 = uVar21 - 1 & 0xffffffff;
                            }
                            uVar14 = uVar14 >> 1;
                            uVar21 = uVar21 - 1 & 0xffffffff;
                          }
                          uVar14 = uVar14 >> 1;
                          uVar21 = uVar21 - 1 & 0xffffffff;
                        }
                        uVar14 = uVar14 >> 1;
                        uVar21 = uVar21 - 1 & 0xffffffff;
                      }
                      uVar14 = uVar14 >> 1;
                      uVar21 = uVar21 - 1 & 0xffffffff;
                    }
                    uVar14 = uVar14 >> 1;
                    uVar21 = uVar21 - 1 & 0xffffffff;
                  }
                  uVar14 = uVar14 >> 1;
                  uVar21 = uVar21 - 1 & 0xffffffff;
                  if (uVar21 <= uVar15)
                    goto LAB_00787c70;
                }
                lVar18 = (((uVar19 << 0x20) >> 0x23) - 1 & 0xffffffff) + 1;
                do
                {
                  uVar14 = uVar14 >> 8;
                  uVar21 = uVar21 - 8 & 0xffffffff;
                  lVar18 = lVar18 + -1;
                } while (lVar18 != 0);
              }
            }
            LAB_00787c70:
            uVar10 = uVar11 + 1;
            *(abd80 + uVar11) = (char)uVar14;
            uVar22 = uVar14 + 1 & 0xffffffff;
            uVar11 = uVar10;
          } while (bVar4 != uVar10);
        }
        lVar18 = 4;
        iVar24 = 0;
        do
        {
          *(local_c80 + iVar24 + 3) = in_vr0_32_3;
          *(local_c80 + iVar24 + 2) = in_vr0_32_2;
          *(local_c80 + iVar24 + 1) = in_vr0_32_1;
          *(local_c80 + iVar24) =  in_vr0_32_0;
          *(local_c80 + iVar24 + 7) = in_vr0_32_3;
          *(local_c80 + iVar24 + 6) = in_vr0_32_2;
          *(local_c80 + iVar24 + 5) = in_vr0_32_1;
          *(local_c80 + iVar24 + 4) = in_vr0_32_0;
          *(local_c80 + iVar24 + 11) = in_vr0_32_3;
          *(local_c80 + iVar24 + 10) = in_vr0_32_2;
          *(local_c80 + iVar24 + 9) = in_vr0_32_1;
          *(local_c80 + iVar24 + 8) = in_vr0_32_0;
          *(local_c80 + iVar24 + 15) = in_vr0_32_3;
          *(local_c80 + iVar24 + 14) = in_vr0_32_2;
          *(local_c80 + iVar24 + 13) = in_vr0_32_1;
          *(local_c80 + iVar24 + 12) = in_vr0_32_0;
          *(local_c80 + iVar24 + 19) = in_vr0_32_3;
          *(local_c80 + iVar24 + 18) = in_vr0_32_2;
          *(local_c80 + iVar24 + 17) = in_vr0_32_1;
          *(local_c80 + iVar24 + 16) = in_vr0_32_0;
          *(local_c80 + iVar24 + 23) = in_vr0_32_3;
          *(local_c80 + iVar24 + 22) = in_vr0_32_2;
          *(local_c80 + iVar24 + 21) = in_vr0_32_1;
          *(local_c80 + iVar24 + 20) = in_vr0_32_0;
          *(local_c80 + iVar24 + 27) = in_vr0_32_3;
          *(local_c80 + iVar24 + 26) = in_vr0_32_2;
          *(local_c80 + iVar24 + 25) = in_vr0_32_1;
          *(local_c80 + iVar24 + 24) = in_vr0_32_0;
          *(local_c80 + iVar24 + 31) = in_vr0_32_3;
          *(local_c80 + iVar24 + 30) = in_vr0_32_2;
          *(local_c80 + iVar24 + 29) = in_vr0_32_1;
          *(local_c80 + iVar24 + 28) = in_vr0_32_0;
          lVar18 = lVar18 + -1;
          iVar24 = iVar24 + 32;
        } while (lVar18 != 0);
        if (bVar1)
        {
          lVar18 = 2;
          uVar11 = 0;
          do
          {
            bVar27 = *(f80 + uVar11);
            if ((unsigned long long)bVar27 != 0)
            {
              uVar21 = (unsigned long long)bVar27 - 1;
              uVar12 = (unsigned int)uVar21;
              bVar5 = *(abd80 + uVar11);
              uVar10 = (unsigned int)((bVar5 >> (uVar12 & 0x3f) & 1) != 0);
              lVar25 = ((int16_t) ((unsigned char)*(c80 + uVar10))) << 1;
              lVar32 = lVar18;
              if ((lVar25 >> 1 ) == 0xff)
              {
                lVar32 = (long long)((int)lVar18 + 2);
                *(c80 + uVar10) = (lVar18 >> 1);
                lVar25 = lVar18;
              }
              uVar9 = (unsigned int)lVar25;
              if ((int)uVar9 < 0)
                break;
              if (bVar27 != 1)
              {
                if ((uVar21 & 1) != 0)
                {
                  uVar12 = uVar12 - 1;
                  uVar10 = uVar9 + 1;
                  if ((bVar5 >> (uVar12 & 0x3f) & 1) == 0)
                  {
                    uVar10 = uVar9;
                  }
                  // lVar25 = ((int16_t) (((unsigned char) *local_c80) + uVar10)) << 1;
                  lVar25 = ((int16_t) ((unsigned char)*(c80 + uVar10))) << 1;
                  if ((lVar25 >> 1 ) == 0xff)
                  {
                    *(c80 + uVar10) = (lVar32 >> 1);
                    lVar25 = lVar32;
                    lVar32 = (long long)((int)lVar32 + 2);
                  }
                  if (((int)lVar25 < 0) || ((int)uVar10 < 0))
                    break;
                  if (bVar27 == 2)
                    goto LAB_0078879c;
                }
                lVar18 = (((uVar21 << 0x20) >> 0x21) - 1 & 0xffffffff) + 1;
                do
                {
                  uVar10 = (unsigned int)lVar32;
                  iVar24 = (int)lVar25;
                  if ((bVar5 >> (uVar12 - 1 & 0x3f) & 1) != 0)
                  {
                    iVar24 = iVar24 + 1;
                  }
                  lVar33 = lVar32;
                  uVar9 = ((int16_t) ((unsigned char)*(c80 + iVar24))) << 1;
                  if ((uVar9 >> 1) == 0xff)
                  {
                    lVar33 = (long long)(int)(uVar10 + 2);
                    *(c80 + iVar24) = (uVar10 >> 1);
                    uVar9 = uVar10;
                  }
                  if (((int)uVar9 < 0) || (iVar24 < 0))
                    goto LAB_00787d90;
                  uVar12 = uVar12 - 2;
                  uVar10 = uVar9 + 1;
                  if ((bVar5 >> (uVar12 & 0x3f) & 1) == 0)
                  {
                    uVar10 = uVar9;
                  }
                  lVar25 = ((int16_t) ((unsigned char)*(c80 + uVar10))) << 1;
                  lVar32 = lVar33;
                  if ((lVar25 >> 1) == 0xff)
                  {
                    lVar32 = (long long)((int)lVar33 + 2);
                    *(c80 + uVar10) = (lVar33 >> 1);
                    lVar25 = lVar33;
                  }
                  if (((int)lVar25 < 0) || ((int)uVar10 < 0))
                    goto LAB_00787d90;
                  lVar18 = lVar18 + -1;
                } while (lVar18 != 0);
              }
              LAB_0078879c:
              lVar25 = ((int16_t) ((unsigned char)*(c80 + uVar10))) << 1;
              lVar18 = lVar32;
              if ((int)lVar32 + -2 == (int)lVar25)
              {
                lVar18 = lVar25;
              }
              *(c80 + uVar10) = 0;
              *(aba80 + uVar10) = *(abe80 + uVar11);
            }
            uVar11 = uVar11 + 1;
          } while (bVar4 != uVar11);
        }
        LAB_00787d90:
        iVar24 = 0;
        do
        {
          uVar21 = 0;
          do
          {
            iVar23 = iVar23 + -1;
            uVar13 = uVar13 >> 1;
            if (iVar23 == 0)
            {
              uVar13 = (unsigned long long)*pbVar20;
              iVar23 = 8;
              pbVar20 = pbVar20 + 1;
            }
            iVar26 = ((unsigned int)uVar13 & 1) + (int)(uVar21 << 1);
            uVar21 = (*(au480 + iVar26));
          } while (uVar21 != 0);
          bVar4 = (*(ab280 + iVar26));
          pbVar29 = pbVar20;
          if ((unsigned long long)bVar4 != 0)
          {
            pbVar29 = uVar30;
            pbVar17 = pbVar29 + bVar4;
            uVar30 = uVar30 + 1;
            *pbVar29 = *pbVar20;
            uVar21 = (unsigned long long)bVar4 - 1;
            pbVar29 = pbVar20 + 1;
            uVar11 = (unsigned int)uVar21 & 7;
            if (pbVar17 != (char *)uVar30)
            {
              if ((uVar21 & 7) != 0)
              {
                if (uVar11 != 1)
                {
                  if (uVar11 != 2)
                  {
                    if (uVar11 != 3)
                    {
                      if (uVar11 != 4)
                      {
                        if (uVar11 != 5)
                        {
                          if (uVar11 != 6)
                          {
                            bVar4 = *pbVar29;
                            pbVar29 = pbVar20 + 2;
                            *(char *)uVar30 = bVar4;
                            uVar30 = uVar30 + 1;
                          }
                          bVar4 = *pbVar29;
                          pbVar29 = pbVar29 + 1;
                          *(char *)uVar30 = bVar4;
                          uVar30 = uVar30 + 1;
                        }
                        bVar4 = *pbVar29;
                        pbVar29 = pbVar29 + 1;
                        *(char *)uVar30 = bVar4;
                        uVar30 = uVar30 + 1;
                      }
                      bVar4 = *pbVar29;
                      pbVar29 = pbVar29 + 1;
                      *(char *)uVar30 = bVar4;
                      uVar30 = uVar30 + 1;
                    }
                    bVar4 = *pbVar29;
                    pbVar29 = pbVar29 + 1;
                    *(char *)uVar30 = bVar4;
                    uVar30 = uVar30 + 1;
                  }
                  bVar4 = *pbVar29;
                  pbVar29 = pbVar29 + 1;
                  *(char *)uVar30 = bVar4;
                  uVar30 = uVar30 + 1;
                }
                bVar4 = *pbVar29;
                pbVar29 = pbVar29 + 1;
                *(char *)uVar30 = bVar4;
                uVar30 = uVar30 + 1;
                if(uVar21 > 65000){
                  printf("test");
                }
                if (pbVar17 == (char *)uVar30)
                  goto LAB_00787dfc;
              }
              lVar18 = (((uVar21 << 0x20) >> 0x23) - 1 & 0xffffffff) + 1;
              do
              {
                *uVar30 = *(pbVar29);
                uVar30 = uVar30 + 1;
                *uVar30 = *(pbVar29 + 1);
                uVar30 = uVar30 + 1;
                *uVar30 = *(pbVar29 + 2);
                uVar30 = uVar30 + 1;
                *uVar30 = *(pbVar29 + 3);
                uVar30 = uVar30 + 1;
                *uVar30 = *(pbVar29 + 4);
                uVar30 = uVar30 + 1;
                *uVar30 = *(pbVar29 + 5);
                uVar30 = uVar30 + 1;
                pbVar20 = pbVar29 + 7;
                *uVar30 = *(pbVar29 + 6);
                uVar30 = uVar30 + 1;
                pbVar29 = pbVar29 + 8;
                *uVar30 = *pbVar20;
                uVar30 = uVar30 + 1;
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
          }
          LAB_00787dfc:
          uVar21 = 0;
          do
          {
            iVar26 = iVar23 + -1;
            iVar31 = iVar23 + -2;
            uVar13 = uVar13 >> 1;
            iVar23 = iVar26;
            if (iVar26 == 0)
            {
              uVar13 = (unsigned long long)*pbVar29;
              iVar23 = 8;
              iVar31 = 7;
              pbVar29 = pbVar29 + 1;
            }
            iVar26 = ((unsigned int)uVar13 & 1) + (int)(uVar21 << 1);
            uVar21 = *(au880 + iVar26);
          } while (uVar21 != 0);
          uVar21 = *(ab680 + iVar26);
          if ((unsigned char) uVar21 == 0xff)
          {
            uVar21 = uVar13 >> 1;
            iVar23 = iVar31 + -1;
            if (iVar31 == 0)
            {
              uVar21 = (unsigned long long)*pbVar29;
              pbVar29 = pbVar29 + 1;
              iVar23 = 7;
            }
            uVar13 = uVar21 >> 1;
            if (iVar23 == 0)
            {
              uVar13 = (unsigned long long)*pbVar29;
              pbVar29 = pbVar29 + 1;
              iVar23 = 8;
            }
            bVar4 = *pbVar29;
            pbVar29 = pbVar29 + 1;
            uVar21 = (unsigned long long)(int)(((unsigned int)((uVar13 & 1 | (long long)(int)((uVar21 & 1) << 1)) << 8) |
                                       (unsigned int)bVar4) +
                                      0xff);
          }
          pbVar20 = pbVar29;
          if (uVar21 != 0)
          {
            uVar22 = 0;
            do
            {
              iVar23 = iVar23 + -1;
              uVar13 = uVar13 >> 1;
              if (iVar23 == 0)
              {
                uVar13 = (unsigned long long)*pbVar29;
                iVar23 = 8;
                pbVar29 = pbVar29 + 1;
              }
              iVar26 = ((unsigned int)uVar13 & 1) + (int)(uVar22 << 1);
              uVar22 = *(c80 + iVar26 );
            } while (uVar22 != 0);
            bVar4 = *(aba80 + iVar26);
            uVar11 = (unsigned int)bVar4;
            if (1 < bVar4)
            {
              iVar23 = iVar23 + -1;
              iVar26 = bVar4 - 1;
              uVar13 = uVar13 >> 1;
              uVar12 = bVar4 - 2;
              uVar11 = (unsigned int)uVar13;
              uVar10 = uVar12 & 3;
              if (iVar23 == 0)
              {
                bVar4 = *pbVar29;
                uVar13 = (unsigned long long)bVar4;
                pbVar29 = pbVar29 + 1;
                iVar23 = 8;
                uVar11 = (unsigned int)bVar4;
              }
              iVar31 = 1;
              iVar16 = 1;
              uVar11 = (uVar11 & 1) + 2;
              if (iVar26 != 1)
              {
                if (uVar10 != 0)
                {
                  if (uVar10 != 1)
                  {
                    if (uVar10 != 2)
                    {
                      iVar23 = iVar23 + -1;
                      uVar13 = uVar13 >> 1;
                      uVar10 = (unsigned int)uVar13;
                      if (iVar23 == 0)
                      {
                        bVar4 = *pbVar29;
                        uVar13 = (unsigned long long)bVar4;
                        pbVar29 = pbVar29 + 1;
                        iVar23 = 8;
                        uVar10 = (unsigned int)bVar4;
                      }
                      uVar11 = uVar11 * 2 + (uVar10 & 1);
                      iVar31 = 2;
                    }
                    iVar23 = iVar23 + -1;
                    uVar13 = uVar13 >> 1;
                    uVar10 = (unsigned int)uVar13;
                    if (iVar23 == 0)
                    {
                      bVar4 = *pbVar29;
                      uVar13 = (unsigned long long)bVar4;
                      pbVar29 = pbVar29 + 1;
                      iVar23 = 8;
                      uVar10 = (unsigned int)bVar4;
                    }
                    uVar11 = uVar11 * 2 + (uVar10 & 1);
                    iVar16 = iVar31 + 1;
                  }
                  iVar23 = iVar23 + -1;
                  uVar13 = uVar13 >> 1;
                  uVar10 = (unsigned int)uVar13;
                  if (iVar23 == 0)
                  {
                    bVar4 = *pbVar29;
                    uVar13 = (unsigned long long)bVar4;
                    pbVar29 = pbVar29 + 1;
                    iVar23 = 8;
                    uVar10 = (unsigned int)bVar4;
                  }
                  uVar11 = uVar11 * 2 + (uVar10 & 1);
                  if (iVar16 + 1 == iVar26)
                    goto LAB_00788124;
                }
                lVar18 = ((((unsigned long long)uVar12 << 0x20) >> 0x22) - 1 & 0xffffffff) + 1;
                do
                {
                  iVar23 = iVar23 + -1;
                  uVar13 = uVar13 >> 1;
                  uVar10 = (unsigned int)uVar13;
                  if (iVar23 == 0)
                  {
                    uVar13 = (unsigned long long)*pbVar29;
                    iVar23 = 8;
                    uVar10 = (unsigned int)*pbVar29;
                    pbVar29 = pbVar29 + 1;
                  }
                  iVar23 = iVar23 + -1;
                  uVar13 = uVar13 >> 1;
                  uVar12 = (unsigned int)uVar13;
                  if (iVar23 == 0)
                  {
                    uVar13 = (unsigned long long)*pbVar29;
                    iVar23 = 8;
                    uVar12 = (unsigned int)*pbVar29;
                    pbVar29 = pbVar29 + 1;
                  }
                  iVar23 = iVar23 + -1;
                  uVar13 = uVar13 >> 1;
                  uVar9 = (unsigned int)uVar13;
                  if (iVar23 == 0)
                  {
                    uVar13 = (unsigned long long)*pbVar29;
                    iVar23 = 8;
                    uVar9 = (unsigned int)*pbVar29;
                    pbVar29 = pbVar29 + 1;
                  }
                  iVar23 = iVar23 + -1;
                  uVar13 = uVar13 >> 1;
                  uVar6 = (unsigned int)uVar13;
                  if (iVar23 == 0)
                  {
                    uVar13 = (unsigned long long)*pbVar29;
                    iVar23 = 8;
                    uVar6 = (unsigned int)*pbVar29;
                    pbVar29 = pbVar29 + 1;
                  }
                  uVar11 = (((uVar11 * 2 + (uVar10 & 1)) * 2 + (uVar12 & 1)) * 2 + (uVar9 & 1)) * 2 + (uVar6 & 1);
                  lVar18 = lVar18 + -1;
                } while (lVar18 != 0);
              }
            }
            LAB_00788124:
            // uVar11 = ~uVar11;
            puVar8 = (unsigned char *)uVar30;
            uVar15 = uVar21 - 1;
            uVar10 = (unsigned int)uVar15 & 7;
            uVar14 = 1;
            *puVar8 = (*(puVar8 - uVar11 - 1));
            uVar22 = uVar14;
            if (uVar21 != 1)
            {
              if ((uVar15 & 7) != 0)
              {
                if (uVar10 != 1)
                {
                  if (uVar10 != 2)
                  {
                    if (uVar10 != 3)
                    {
                      if (uVar10 != 4)
                      {
                        if (uVar10 != 5)
                        {
                          if (uVar10 != 6)
                          {
                            uVar14 = 2;
                            (*(puVar8 + 1)) = (*(puVar8 - uVar11));
                          }
                          iVar26 = (int)uVar14;
                          uVar14 = uVar14 + 1;
                          (*(puVar8 + (int)iVar26)) = (*(puVar8 + (int)iVar26- uVar11 - 1));
                        }
                        iVar26 = (int)uVar14;
                        uVar14 = uVar14 + 1;
                        (*(puVar8 + (int)iVar26)) = (*(puVar8 + (int)iVar26- uVar11 - 1));
                      }
                      iVar26 = (int)uVar14;
                      uVar14 = uVar14 + 1;
                      (*(puVar8 + (int)iVar26)) = (*(puVar8 + (int)iVar26- uVar11 - 1));
                    }
                    iVar26 = (int)uVar14;
                    uVar14 = uVar14 + 1;
                    (*(puVar8 + (int)iVar26)) = (*(puVar8 + (int)iVar26- uVar11 - 1));
                  }
                  iVar26 = (int)uVar14;
                  uVar14 = uVar14 + 1;
                  (*(puVar8 + (int)iVar26)) = (*(puVar8 + (int)iVar26- uVar11 - 1));
                }
                uVar22 = uVar14 + 1;
                (*(puVar8 + (int)uVar14)) = (*(puVar8 + (int)uVar14 - uVar11 - 1));
                if (uVar21 == uVar22)
                  goto LAB_00788384;
              }
              lVar18 = (((uVar15 << 0x20) >> 0x23) - 1 & 0xffffffff) + 1;
              do
              {
                uVar21 = uVar22 + 1 & 0xffffffff;
                uVar14 = uVar21 + 1 & 0xffffffff;
                (*(puVar8 + (int)uVar22)) = (*(puVar8 + (int)uVar22- uVar11 - 1));
                uVar22 = uVar14 + 1 & 0xffffffff;
                (*(puVar8 + (int)uVar21)) = (*(puVar8 + (int)uVar21- uVar11 - 1));
                uVar21 = uVar22 + 1 & 0xffffffff;
                (*(puVar8 + (int)uVar14)) = (*(puVar8 + (int)uVar14- uVar11 - 1));
                uVar14 = uVar21 + 1 & 0xffffffff;
                (*(puVar8 + (int)uVar22)) = (*(puVar8 + (int)uVar22- uVar11 - 1));
                uVar22 = uVar14 + 1 & 0xffffffff;
                (*(puVar8 + (int)uVar21)) = (*(puVar8 + (int)uVar21- uVar11 - 1));
                uVar21 = uVar22 + 1 & 0xffffffff;
                (*(puVar8 + (int)uVar14)) = (*(puVar8 + (int)uVar14- uVar11 - 1));
                (*(puVar8 + (int)uVar22)) = (*(puVar8 + (int)uVar22- uVar11 - 1));
                uVar22 = uVar21 + 1 & 0xffffffff;
                (*(puVar8 + (int)uVar21)) = (*(puVar8 + (int)uVar21- uVar11 - 1));
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
            }
            LAB_00788384:
            uVar30 = uVar30 + uVar22;
            pbVar20 = pbVar29;
          }
          iVar24 = iVar24 + 1;
          // if((((puVar8 + (int)uVar21)) - (unsigned char*) param_1) > 0x860){
          //   printf("breakpoint: bVar3 %x bVar2 %x iVar24 %x", bVar3,bVar2,iVar24);
          // }
        } while (((unsigned int)bVar3 + (unsigned int)bVar2 * 0x100) != iVar24);
      }
      uVar13 = ((unsigned long long)(char)(((int)uVar30 - (int)param_1 == (int)unpackedBlobSize) << 1) << 0x20) >> 0x21;
    }
    else
    {
      // FUN_00012a50(param_1, pbVar20, uVar7);
      uVar13 = 1;
    }
  }
  return param_1;
}

char* read_file(char *filepath){
    
  char * buffer = 0;
  long length;
  FILE * f = fopen (filepath, "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }

  return buffer;
}

char* read_chunk_from_file(char *filepath){
    
  char * buffer = 0;
  short int length;
  FILE * f = fopen (filepath, "rb");

  if (f)
  {
    fseek(f, CHUNK_OFFSET + 0xA, SEEK_SET);
    
    length =  fgetc(f) << 8;
    length =  length | fgetc(f);
    length += 0x10;

    fseek (f, CHUNK_OFFSET, SEEK_SET);
    CHUNK_OFFSET += length;
    buffer = malloc (length);

    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }

  return buffer;
}

void save_chunk(char* addr){
  FILE *out = fopen("D:\\github\\MSMV-unpack\\uncompressed_blob_bces.bin", "ab");
  if(out != NULL)
  {
    size_t to_go = 1;
    while(to_go > 0)
    {
      const size_t wrote = fwrite(addr, to_go, BLOB_SIZE, out);
      if(wrote == 0)
        break;
      to_go -= wrote;
    }
    fclose(out);
  }
  free(addr);
}

int main(){

    char* arch;
    char* mem;
    unsigned long file_size = 0;
    
    if (remove("D:\\github\\MSMV-unpack\\uncompressed_blob_bces.bin") == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting the file.\n");
    }

    file_size = get_file_size("D:\\github\\MSMV-unpack\\cache_ps3_bcus_1.00.dat");
    printf("file_size %x\n", file_size);

    while(file_size > CHUNK_OFFSET){
      printf("Unpacking chunk at: 0x%x\n", CHUNK_OFFSET);
      arch = read_chunk_from_file("D:\\github\\MSMV-unpack\\cache_ps3_bcus_1.00.dat");
      mem = Unpack(mem, arch);
      save_chunk(mem);
      free(arch);
    }
}