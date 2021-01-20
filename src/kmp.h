#pragma once

void KMP_preprocessing(const string P, const uint M, uint *lps)
{
   uint i = 1, len = lps[0] = 0;

   while (i < M)
   {
      if (P[i] == P[len]) len++, lps[i++] = len;
      else
      {
          if (len != 0) len = lps[len - 1];
          else lps[i++] = 0;
      }
   }
}

uint knuthMorrisPratt(const string T, const uint N, const string P, const uint M)
{
   uint i = 0, j = 0, cnt = 0;
   uint *lps = new uint[M];

   KMP_preprocessing(P, M, lps);

   while (i < N)
   {
      if (P[j] == T[i]) i++, j++;
      if (j == M) cnt++, j = lps[j-1];
      else if (i < N && P[j] != T[i])
      {
          if (j != 0) j = lps[j - 1];
          else i++;
      }
   }

   return cnt;
}
