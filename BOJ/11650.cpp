#include <iostream>
#include <utility>
#include <algorithm>

main()
{
    int N, tmp;
    scanf("%d", &N);
    tmp = N;
    
    std::pair<int, int> v[N];
    
    while (tmp--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        
        v[tmp] = std::make_pair(x, y);
    }
    
    std::sort(v, v+N);
    
    for (int i = 0; i < N; i++)
        printf("%d %d\n", v[i].first, v[i].second);
}