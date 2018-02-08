#include <stdio.h>
#define SISWA 4
#define MAPEL 4

void cetakArray(const int nilai[][MAPEL], int siswa, int test);
int nilaiMinimum(const int nilai[][MAPEL], int siswa, int test);
int nilaiMaksimum(const int nilai[][MAPEL], int siswa, int test);
double rerata(const int aturNilai[], int test);

int main()
{
  int i;
  const int nilaiSiswa[SISWA][MAPEL] =
    {
      {77, 68, 86, 73},
      {96, 87, 89, 78},
      {70, 90, 86, 81},
      {80, 91, 98, 87}
    };

  printf("Daftar Penilaian Siswa \n");
  cetakArray(nilaiSiswa, SISWA, MAPEL);
  printf("\n\nNilai terendah : %d\n", nilaiMinimum(nilaiSiswa, SISWA, MAPEL));
  printf("Nilai tertinggi : %d\n", nilaiMaksimum(nilaiSiswa, SISWA, MAPEL));

  for(i = 0; i < SISWA; i++)
    {
      printf("Nilai rata-rata siswa ke %d adalah %.2f\n",
                     i, rerata(nilaiSiswa[i], MAPEL));
    }

  return 0;
}

void cetakArray(const int nilai[][MAPEL], int siswa, int test)
{
  int i;
  int j;

  printf("                [A]  [B]  [C]  [D]");
  for (i = 0; i < siswa; i++)
    {
      printf("\nNilai Siswa [%d] ", i);
      for (j = 0; j < test; j++)
                {
                  printf("%-5d", nilai[i][j]);
                }
    }
}

int nilaiMinimum(const int nilai[][MAPEL], int siswa, int test)
{
  int i;
  int j;
  int nilaiTerendah = 100;

  for (i = 0; i < siswa; i++)
    {
      for (j = 0; j < test; j++)
                {
                  if (nilai[i][j] < nilaiTerendah)
                    {
                      nilaiTerendah = nilai[i][j];
                    }
                }
    }
 
  return nilaiTerendah;
}

int nilaiMaksimum(const int nilai[][MAPEL], int siswa, int test)
{
  int i;
  int j;
  int nilaiTertinggi;

  nilaiTertinggi = 0;
  for (i = 0; i < siswa; i++)
    {
      for (j = 0; j < test; j++)
                {
                  if (nilai[i][j] > nilaiTertinggi)
                    {
                      nilaiTertinggi = nilai[i][j];
                    }
                }
    }
  return nilaiTertinggi;
}

double rerata(const int aturNilai[], int test)
{
  int i;
  int total;

  total = 0;
  for (i = 0; i < test; i++)
    {
      total = total + aturNilai[i];
    }

  return (double) total / test;
}