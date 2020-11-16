#include <iostream>

int factorial(int N)
{
    if (N == 0) return 1;
    
    return N * factorial(N-1);
}

main()
{
    int N;
    scanf("%d", &N);
    
    printf("%d", factorial(N));
}