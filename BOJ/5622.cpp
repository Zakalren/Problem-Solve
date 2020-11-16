#include <iostream>

main()
{
	int result = 0, arr[26] = { 3, 3, 3, 
							   4, 4, 4,
							   5, 5, 5,
							   6, 6, 6,
							   7, 7, 7,
							   8, 8, 8, 8,
							   9, 9, 9,
							   10, 10, 10, 10 };
	
	char str[16];
	scanf("%s", &str);
	
	for (char c : str)
	{
		if (!c) break;

		result += arr[c - 65];
	}
	
	printf("%d", result);
}