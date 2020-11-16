#include <iostream>
#include <algorithm>

main()
{
	char ca[1000000];
	int blank = 0;
	scanf("%[^\n]%*c", &ca);
	
	std::string str(ca);

	if (str.front() == ' ')
		blank--;
	if (str.back() == ' ')
		blank--;

	int count = std::count(str.begin(), str.end(), ' ') + 1;

	printf("%d", count + blank);
}