#include <iostream>

int fibonacci(int N)
{
    if (N <= 1)
        return N;
    
    return fibonacci(N-1) + fibonacci(N-2);
}

main()
{
    int N;
    scanf("%d", &N);
    
    printf("%d", fibonacci(N));
}