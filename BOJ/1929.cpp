#include <iostream>

main()
{
    int N, M, j;
    scanf("%d %d", &N, &M);
    int prime[M+1] = { 0, 1, };
    
    for (int i = 2; i * i <= M; i++)
    {
		if (prime[i] == 0)
			for (int j = i * i; j <= M; j += i)
				prime[j] = 1;
    }
	
	for (int i = N; i <= M; i++)
		if (prime[i] == 0)
			printf("%d\n", i);
}