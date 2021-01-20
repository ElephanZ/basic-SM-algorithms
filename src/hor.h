#pragma once

void horspool_preprocessing(const string P, const uint M, uint *hbc)
{
   for (uint i = 0; i < SIGMA_SIZE; i++) hbc[i] = M;
   for (uint i = 0; i < M - 1; i++) hbc[(uint)P[i]] = M - i - 1;
}

uint horspool(const string T, const uint N, const string P, const uint M)
{
   uint cnt = 0;
   uint *hbc = new uint[SIGMA_SIZE];

   auto check = [=](const uint s)
   {
      uint j = 0;
      while (j < M && T[s + j] == P[j]) j++;
      return j >= M;
   };

   horspool_preprocessing(P, M, hbc);

   for (uint i = 0; i <= N - M; i += hbc[(uint)T[M + i - 1]])
      if (check(i)) cnt++;

   delete[] hbc;
   
   return cnt;
}
