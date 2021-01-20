#pragma once

uint bruteForce(const string T, const uint N, const string P, const uint M)
{
    uint cnt = 0;

    auto check = [=](const uint s)
    {
        uint j = 0;
        while (j < M && T[s + j] == P[j]) j++;
        return j >= M;
    };

    for (uint i = 0; i <= N - M; i++)
        if (check(i)) cnt++;

    return cnt;
}
