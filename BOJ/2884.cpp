#include <iostream>

main()
{
    int h, m;
    scanf("%d %d", &h, &m);
    
    if (m >= 45)
        printf("%d %d", h, m-45);
    else
        printf("%d %d", h == 0 ? 23 : (h - 1), 60+(m-45));
}
