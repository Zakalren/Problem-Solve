#include <iostream>

main()
{
	int T, N, left, right, P[10001] = { 0, 1 };
	scanf("%d", &T);
	
	for (int i = 2; i*i <= 10000; i++)
		if (!P[i])
			for (int j = i*i; j <= 10000; j += i)
				P[j] = 1;
	
	while (T--)
	{
		scanf("%d", &N);
		
		for (int i = 2; i <= N/2; i++)
		{
			if (P[i] || P[N-i])
				continue;
			
			left = i;
			right = N-i;
		}
		
		printf("%d %d\n", left, right);
	}
}