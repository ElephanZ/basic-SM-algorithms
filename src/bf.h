#pragma once

uint bruteForce(string T, uint N, string P, uint M)
{
    uint cnt = 0;

    auto check = [=](uint s)
    {
        uint j = 0;
        while (j < M && T[s + j] == P[j]) j++;
        return j >= M;
    };

    for (uint i = 0; i <= N - M; i++)
        if (check(i)) cnt++;

    return cnt;
}
