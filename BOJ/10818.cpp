#include <iostream>
#include <algorithm>

main()
{
    int n;
    
    scanf("%d", &n);
    
    int* num = new int[n];
    
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    
    int min, max;
	
	min = *std::min_element(num, num+n);
	max = *std::max_element(num, num+n);
	
	printf("%d %d", min, max);
}