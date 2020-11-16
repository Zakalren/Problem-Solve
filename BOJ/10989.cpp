#include <iostream>

main()
{
    int N, count[10001] = { 0 }, temp, max;
    scanf("%d", &N);
    
    while (N--)
    {
        scanf("%d", &temp);
        count[temp]++;
        
        if (temp > max)
            max = temp;
    }
    
    for (int i = 0; i <= max; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%d\n", i);
}