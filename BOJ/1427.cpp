#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

main()
{
    int N, count;
    scanf("%d", &N);
    count = (int)log10(N)+1;
    int arr[count];
    
    count = 0;
    while (N)
    {
        arr[count] = N % 10;
        N /= 10;
        count++;
    }
    
    std::sort(arr, arr+count, std::greater<int>());
    
    for (int i : arr)
        printf("%d", i);
}