#include <iostream>

main()
{
	int N;
	scanf("%d", &N);
	
	int i = 665;
	
	while (N)
	{
		i++;
		int tmp = i;
		
		while (tmp)
		{
			if (tmp % 1000 == 666)
			{
				N--;
				break;
			}
			
			tmp /= 10;
		}
	}
	
	printf("%d", i);
}