#include <iostream>
#include <algorithm>
#include <cmath>

main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	std::string astr = std::to_string(a); 
	std::string bstr = std::to_string(b);
	
	std::reverse(astr.begin(), astr.end());
	std::reverse(bstr.begin(), bstr.end());
	
	int max = std::max(std::stoi(astr), std::stoi(bstr));

	printf("%d", max);
}