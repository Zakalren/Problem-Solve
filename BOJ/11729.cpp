#include <iostream>
#include <cmath>

void hanoi(int N, int start, int end, int mid)
{
    if (N == 1)
        printf("%d %d\n", start, end);
    else
    {
        hanoi(N-1, start, mid, end);
        printf("%d %d\n", start, end);
        hanoi(N-1, mid, end, start);
    }
}

main()
{
    int N;
    scanf("%d", &N);
    
    printf("%d\n", (int)pow(2, N)-1);
    hanoi(N, 1, 3, 2);
}