#include <iostream>

main()
{
    int min, max, j, total = 0, least = -1;
    scanf("%d %d", &min, &max);
    
    for (int i = min; i <= max; i++)
    {
        if (i == 1)
            continue;
        
        for (j = 2; j < i; j++)
            if (i%j == 0)
                break;
        
        if (i==j)
        {
            total += i;
            
            if (least == -1)
                least = i;
        }    
    }
    
    if (total == 0)
        printf("-1");
    else
        printf("%d\n%d", total, least);
}


