#include <iostream>

main()
{
    long long N, range = 1;
    scanf("%lld", &N);
    
    int count = 1;
    
    while (1)
    {
        if (range >= N)
            break;
            
        range += 6 * (count++);
    }
    
    printf("%d", count);
}