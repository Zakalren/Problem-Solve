#include <iostream>
#include <utility>
#include <algorithm>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}

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
    
    std::sort(v, v+N, cmp);
    
    for (int i = 0; i < N; i++)
        printf("%d %d\n", v[i].first, v[i].second);
}