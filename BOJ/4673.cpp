#include <iostream>
#include <cmath>
#include <set>

int d(int n)
{
    int count = log10(n) + 1, result = n;
	
    int arr[count];
    
    for (int i = 0; i < count; i++)
    {
        result += n % 10;
        n /= 10;
    }
    
    return result;
}

main()
{
    std::set<int> set;
    
    for (int i = 1; i <= 10000; i++)
    {   
        int n = d(i);
        
        if (n > 10000)
            continue;
        
        set.insert(n);
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (set.find(i) == set.end())
            printf("%d\n", i);
    }
}