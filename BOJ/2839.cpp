#include <iostream>

main()
{
    int N, count = 0;
    scanf("%d", &N);
    
    while (1)
    {
        if (N < 0)
        {
            printf("-1");
            break;
        }
        
        if (N % 5 == 0)
        {
            count += N / 5;
            printf("%d", count);
            break;
        }
        
        N -= 3;
        count++;
    }
}