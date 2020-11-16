#include <iostream>

void printStar(int X, int Y, int N)
{
    if ((X/N)%3 == 1 && (Y/N)%3 == 1)
        printf(" ");
    else
    {
        if (N/3 == 0)
            printf("*");
        else
            printStar(X, Y, N/3);
    }
}

main()
{
    int N;
    scanf("%d", &N);
    
    for (int Y = 0; Y < N; Y++)
    {
        for (int X = 0; X < N; X++)
            printStar(Y, X, N);
        
        printf("\n");
    }
}