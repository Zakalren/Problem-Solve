#include <iostream>
#include <cmath>

main()
{
	int N, result = 0;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
	{
		int k = i, sum = i;
		
		while (k)
		{
			sum += k % 10;
			k /= 10;
		}
		
		if (sum == N)
		{
			result = i;
			break;
		}
	}
	
	printf("%d", result);
}