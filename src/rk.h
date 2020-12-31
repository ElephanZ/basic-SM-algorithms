#pragma once

void rabinKarp_preprocessing(string P, string T, size_t M, uint &hash, uint &t_hash, uint &p_hash)
{
   for (size_t i = 1; i < M; i++) hash = (hash << 1);
   for (size_t i = 0; i < M; i++)
      p_hash = ((p_hash << 1) + (uint)P[i]),
      t_hash = ((t_hash << 1) + (uint)T[i]);
}

uint rabinKarp(string T, size_t N, string P, size_t M)
{
   uint h = 1, hp = 0, ht = 0, cnt = 0;

   auto check = [=](size_t s)
   {
      size_t j = 0;
      while (j < M && T[s + j] == P[j]) j++;
      return j >= M;
   };
   auto rehash = [&](size_t s)
   {
      return ((ht - T[s]*h) << 1) + T[M+s];
   };

   rabinKarp_preprocessing(P, T, M, h, ht, hp);

   for (size_t i = 0; i <= N - M; ht = rehash(i), i++)
      if (ht == hp && check(i)) cnt++;
   
   return cnt;
}

