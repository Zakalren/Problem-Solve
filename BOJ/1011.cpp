#include <iostream>
#include <cmath>

main()
{
    int T, X, Y, d, r;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d %d", &X, &Y);
        
        d = Y - X;
        r = (int) sqrt(d);
        
        if (d == r*r)
            printf("%d\n", r*2-1);
        else if (d > r*r && d <= r*r+r)
            printf("%d\n", r*2);
        else
            printf("%d\n", r*2+1);
    }
}