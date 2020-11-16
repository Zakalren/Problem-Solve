#include <iostream>
#include <algorithm>

main()
{
    int N;
    scanf("%d", &N);
    
    int num[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    
    std::sort(num, num+N);
    
    for (int i = 0; i < N; i++)
        printf("%d\n", num[i]);
}