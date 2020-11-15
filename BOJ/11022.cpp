#include <iostream>

main()
{
    int num;
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
    }
}
