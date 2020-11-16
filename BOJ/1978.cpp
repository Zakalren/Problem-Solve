#include <iostream>
#include <cmath>

main()
{
    int N, num, i, count = 0;
    scanf("%d", &N);
    
    while (N--)
    {
        scanf("%d", &num);
        
        if (num == 1)
            continue;
        
        for (i = 2; i < num; i++)
            if (num % i == 0)
                break;
        
        if (i == num)
            count++;
    }
    
    printf("%d", count);
}