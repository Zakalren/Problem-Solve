#include <iostream>
#include <algorithm>
#include <array>

main()
{
    int num[9];
    
    for (int i = 0; i < 9; i++)
        scanf("%d", &num[i]);
    
    int max;
	
	auto it = std::max_element(num, num+9);
	max = *it;
	
	printf("%d\n%d", max, it - std::begin(num) + 1);
}