#pragma once

void getSuffixes(string P, size_t M, int *s)
{
   int f, g = M - 1;
   s[M - 1] = M;

   for (int i = M - 2; i >= 0; i--)
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

void goodSuffix(string P, size_t M, uint *gs)
{
   int *s = new int[M + 1];
   size_t j = 0;

   getSuffixes(P, M, s);
   for (size_t i = 0; i < M; i++) gs[i] = M;
   
   for (int i = M - 1; i >= 0; i--)
      if (s[i] == i + 1)
         for (; j < M - i - 1; j++)
            if (gs[j] == M) gs[j] = M - i - 1;

   for (size_t i = 0; i <= M - 2; i++) gs[M - s[i] - 1] = M - i - 1;
}

void badCharacter(string P, size_t M, uint *bc)
{
   for (size_t i = 0; i < SIGMA_SIZE; i++) bc[i] = M;
   for (size_t i = 0; i < M - 1; i++) bc[(size_t)P[i]] = M - i - 1;
}

uint boyerMoore(string T, size_t N, string P, size_t M)
{
   uint i = 0, cnt = 0;
   uint *gs = new uint[M + 1], *bc = new uint[SIGMA_SIZE];
   int j = M - 1;

   goodSuffix(P, M, gs);
   badCharacter(P, M, bc);

   while (i <= N - M)
   {
      for (j = M - 1; j >= 0 && P[j] == T[i + j]; j--);
      if (j >= 0) i += max( gs[j], bc[(size_t)T[i + j]] - M + j + 1 );
      else cnt++, i += gs[0];  
   }

   return cnt;
}

