#include <iostream>
#include <algorithm>

int N, cost[1000][3], num[1000][3];

main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    
    num[0][0] = cost[0][0];
    num[0][1] = cost[0][1];
    num[0][2] = cost[0][2];
    
    for (int i = 1; i < N; i++)
    {
        num[i][0] = std::min(num[i-1][1], num[i-1][2]) + cost[i][0];
        num[i][1] = std::min(num[i-1][0], num[i-1][2]) + cost[i][1];
        num[i][2] = std::min(num[i-1][0], num[i-1][1]) + cost[i][2];
    }
    
    printf("%d", std::min(std::min(num[N-1][0], num[N-1][1]), num[N-1][2]));
}