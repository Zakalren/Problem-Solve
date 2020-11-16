#include <iostream>

main()
{
	int N, M, result = 0;
	scanf("%d %d", &N, &M);
	int num[N];
	
	for (int i = 0; i < N; i++)
		scanf("%d", num+i);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N-1; j++)
			for (int k = 0; k < N-2; k++)
			{
				if (i == j+1 || i == k+2 || j+1 == k+2)
					continue;
				
				int sum = num[i] + num[j+1] + num[k+2];
				
				if (sum > result && sum <= M)
					result = sum;
			}
	
	printf("%d", result);
}