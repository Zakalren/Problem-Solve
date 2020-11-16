#include <iostream>

main()
{
	int T, resident[15][14];
	
	for (int i = 0; i < 14; i++)
	{
		resident[0][i] = i+1;
		resident[i+1][0] = 1;
	}
	
	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 14; j++)
			resident[i][j] = resident[i-1][j] + resident[i][j-1];
	
	scanf("%d", &T);
	
	while (T--)
	{
		int K, N;
		scanf("%d%d", &K, &N);
		
		printf("%d\n", resident[K][N-1]);
	}
}