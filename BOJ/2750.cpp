#include <iostream>
#include <algorithm>

main()
{
    int N;
    scanf("%d", &N);
    int num[N+1];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    
    for (int i = 0; i < N-1; i++)
    {
        int tmp = i;
        for (int j = i+1; j < N; j++)
            if (num[tmp] >= num[j])
                tmp = j;
        
        std::swap(num[i], num[tmp]);
    }
    
    for (int i = 0; i < N; i++)
        printf("%d\n", num[i]);
}