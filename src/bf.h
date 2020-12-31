#pragma once

uint bruteForce(string T, size_t N, string P, size_t M)
{
    uint cnt = 0;

    auto check = [=](size_t s) {
        size_t j = 0;
        while (j < M && T[s + j] == P[j]) j++;
        return j >= M;
    };

    for (size_t i = 0; i <= N - M; i++)
        if (check(i)) cnt++;

    return cnt;
}

