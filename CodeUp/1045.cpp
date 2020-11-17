#include <iostream>

main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n%d\n%d\n%d\n%d\n%.2f", A+B, A-B, A*B, A/B, A%B, (float)A/B);
}