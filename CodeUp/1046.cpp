#include <iostream>

typedef long long int lli;

main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%lld\n%.1f", (lli) A+B+C, (float) ((lli)A+B+C) / 3);
}