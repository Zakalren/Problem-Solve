#include <iostream>
#include <algorithm>

main()
{
	int N, M, B, W, result = 100;
	scanf("%d %d", &N, &M);
	
	char board[N][M];
	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);
	
	for (int i = 0; i < N-7; i++)
		for (int j = 0; j < M-7; j++)
		{
			B = 0, W = 0;
			
			for (int k = i; k < i+8; k++)
			{
				for (int l = j; l < j+8; l++)
				{
					if ((k + l) % 2 == 0)
					{
						if (board[k][l] == 'B')
							W++;
						else
							B++;
					}
					else
					{
						if (board[k][l] == 'B')
							B++;
						else
							W++;
					}
				}
			}

			result = std::min(result, std::min(B, W));
		}

	printf("%d", result);
}