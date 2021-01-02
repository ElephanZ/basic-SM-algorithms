#pragma once

void KMP_preprocessing(string P, uint M, int *kmp)
{
    uint i = 0;
    int j = kmp[0] = -1;

   while (i < M)
   {   
      while (j > -1 && P[i] != P[j]) j = kmp[j];
      i++, j++;
      kmp[i] = ((i < M && P[i] == P[j]) ? kmp[j] : kmp[i] = j);
   }
}

uint knuthMorrisPratt(string T, uint N, string P, uint M)
{
   uint i = 0, cnt = 0;
   int *kmp = new int[M];
   int j = 0;

   KMP_preprocessing(P, M, kmp);

   while (i < N)
   {
      while (j > -1 && P[j] != T[i]) j = kmp[j];
      i++, j++;
      if (j >= M) cnt++, j = kmp[j];
   }

   return cnt;
}
