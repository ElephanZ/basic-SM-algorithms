#pragma once

void rabinKarp_preprocessing(const string P, const string T, const uint M, uint &hash, uint &t_hash, uint &p_hash)
{
   for (uint i = 1; i < M; i++, hash <<= 1);
   for (uint i = 0; i < M; i++)
      p_hash = ((p_hash << 1) + (uint)P[i]),
      t_hash = ((t_hash << 1) + (uint)T[i]);
}

uint rabinKarp(string T, uint N, string P, uint M)
{
   uint h = 1, hp = 0, ht = 0, cnt = 0;

   auto rehash_t = [&](uint s) { return ((ht - T[s]*h) << 1) + T[M + s]; };
   auto check = [=](uint s)
   {
      uint j = 0;
      while (j < M && T[s + j] == P[j]) j++;
      return j >= M;
   };

   rabinKarp_preprocessing(P, T, M, h, ht, hp);

   for (uint i = 0; i <= N - M; ht = rehash_t(i), i++)
      if (ht == hp && check(i)) cnt++;
   
   return cnt;
}
