#include <iostream>

typedef long long int lli;

int T, N;
lli num[101];

lli solve(int n)
{
    if (n <= 3)
        return 1;
    
    if (num[n])
        return num[n];

    return num[n] = solve(n-2) + solve(n-3);
}

main()
{
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &N);
        printf("%lld\n", solve(N));
    }
}