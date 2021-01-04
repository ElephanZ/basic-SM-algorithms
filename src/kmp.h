#pragma once

void KMP_preprocessing(string P, uint M, int *lps)
{
   uint i = 0;
   int j = lps[0] = -1;

   while (i < M)
   {   
      while (j > -1 && P[i] != P[j]) j = lps[j];
      i++, j++;
      lps[i] = (i < M && P[i] == P[j] ? lps[j] : j);
   }
}

uint knuthMorrisPratt(string T, uint N, string P, uint M)
{
   uint i = 0, cnt = 0;
   int *lps = new int[M];
   int j = 0;

   KMP_preprocessing(P, M, lps);

   while (i < N)
   {
      while (j > -1 && P[j] != T[i]) j = lps[j];
      i++, j++;
      if (j >= M) cnt++, j = lps[j];
   }

   return cnt;
}
