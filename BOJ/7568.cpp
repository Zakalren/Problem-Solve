#include <iostream>

main()
{
	int N;
	scanf("%d", &N);
	int H[N], W[N];
	
	for (int i = 0; i < N; i++)
		scanf("%d %d", &H[i], &W[i]);
	
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		
		for (int j = 0; j < N; j++)
			if (H[i] < H[j] && W[i] < W[j])
				count++;
		
		printf("%d ", count+1);
	}
}