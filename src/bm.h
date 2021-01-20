#pragma once

void suffixes(const string P, const uint M, int* s)
{
   s[M - 1] = M;
   for (int i = M - 2, g = M - 1, f; i >= 0; i--)
   {
      if (i > g && s[i + M - f - 1] < i - g) s[i] = s[i + M - f - 1];
      else
      {
         f = i, g = (i < g ? i : g);
         while (g >= 0 && P[g] == P[g + M - f - 1]) g--;
         s[i] = f - g;
      }
   }
}

void goodSuffix(const string P, const uint M, uint *gs)
{
   int *s = new int[M];

   suffixes(P, M, s);
   for (uint i = 0; i < M; i++) gs[i] = M;
   
   for (int i = M - 1; i >= 0; i--)
      if (s[i] == i + 1)
         for (uint j = 0; j < M - i - 1; j++)
            if (gs[j] == M) gs[j] = M - i - 1;

   for (uint i = 0; i <= M - 2; i++) gs[M - s[i] - 1] = M - i - 1;
   
   delete[] s;
}

void badCharacter(const string P, const uint M, uint *bc)
{
   for (uint i = 0; i < SIGMA_SIZE; i++) bc[i] = M;
   for (uint i = 0; i < M - 1; i++) bc[(uint)P[i]] = M - i - 1;
}

uint boyerMoore(const string T, const uint N, const string P, const uint M)
{
   uint i = 0, cnt = 0;
   uint *gs = new uint[M + 1], *bc = new uint[SIGMA_SIZE];
   int j = M - 1;

   goodSuffix(P, M, gs);
   badCharacter(P, M, bc);

   while (i <= N - M)
   {
      for (j = M - 1; j >= 0 && P[j] == T[i + j]; j--);
      if (j >= 0) i += max( gs[j], bc[(uint)T[i + j]] - M + j + 1 );
      else cnt++, i += gs[0];  
   }
   
   delete[] gs;
   delete[] bc;
   
   return cnt;
}
