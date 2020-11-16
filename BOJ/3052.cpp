#include <iostream>

main()
{
	int n[42] = { 0 };
	int num, count = 0;
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		
		if (!n[num % 42])
		{
			n[num % 42]++;
			count++;
		}
	}
	
	printf("%d", count);
}