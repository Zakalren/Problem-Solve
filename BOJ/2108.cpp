#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

main()
{
    int N, total = 0, mode, count = 0;
    std::map<int, int> counts;
    scanf("%d", &N);
    
    int num[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        
        total += num[i];
        counts[num[i]]++;
    }
    
    std::sort(num, num+N);
    
    for (int i = -4000; i <= 4000; i++)
    {
        if (!counts[i])
            continue;
        
        if (counts[i] == counts[mode] && count == 0)
        {
            mode = i;
            count = 1;
        }
        
        if (counts[i] > counts[mode] || !mode)
        {
            mode = i;
            count = 0;
        }
    }
   
    printf("%d\n%d\n%d\n%d", (int)round((double)total/N), num[(N-1)/2], mode, num[N-1]-num[0]);
}