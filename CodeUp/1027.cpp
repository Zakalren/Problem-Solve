#include <iostream>

main()
{
    int Y, M, D;
    scanf("%d.%d.%d", &Y, &M, &D);
    printf("%02d-%02d-%04d", D, M, Y);
}