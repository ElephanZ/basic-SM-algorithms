#pragma once

void horspool_preprocessing(string P, size_t M, uint *hbc)
{
   for (size_t i = 0; i < SIGMA_SIZE; i++) hbc[i] = M;
   for (size_t i = 0; i < M - 1; i++) hbc[(size_t)P[i]] = M - i - 1;
}

uint horspool(string T, size_t N, string P, size_t M)
{
   uint cnt = 0;
   uint *hbc = new uint[SIGMA_SIZE];

   auto check = [=](size_t s) {
      size_t j = 0;
      while (j < M && T[s + j] == P[j]) j++;
      return j >= M;
   };

   horspool_preprocessing(P, M, hbc);

   for (size_t i = 0; i <= N - M; i += hbc[T[M + i - 1]])
      if (check(i)) cnt++;

   return cnt;
}

