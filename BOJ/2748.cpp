#include <iostream>

typedef long long int lli;

lli num[91];

lli fibo(int n)
{
    if (n <= 1)
        return n;

    if (num[n])
        return num[n];

    return num[n] = fibo(n-1) + fibo(n-2);
}

main()
{
    int N;
    scanf("%d", &N);

    printf("%lld", fibo(N));
}