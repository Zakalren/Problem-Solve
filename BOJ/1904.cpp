#include <iostream>

int N, num[1000001];

int solve(int n)
{
    if (n <= 3)
        return n;

    if (num[n])
        return num[n];

    return num[n] = (solve(n-1) + solve(n-2)) % 15746;
}

main()
{
    scanf("%d", &N);
    printf("%d", solve(N));
}