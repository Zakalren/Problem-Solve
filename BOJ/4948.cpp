#include <iostream>

main()
{
	int N, count, P[123456 * 2 + 1] = { 0, 1 };
	
	while (1)
	{
		scanf("%d", &N);
		
		if (!N)
			break;
		
		count = 0;
		
		for (int i = 2; i*i <= N*2; i++)
			if (!P[i])
				for (int j = i*i; j <= N*2; j += i)
					P[j] = 1;
		
		for (int i = N+1; i <= N*2; i++)
			if (!P[i])
				count++;
		
		printf("%d\n", count);
	}
}