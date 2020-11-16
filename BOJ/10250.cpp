#include <iostream>

main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		
		int A = N % H == 0 ? H : N % H,
			B = N % H == 0 ? N / H : (N / H) + 1;

		if (B >= 10)
			printf("%d%d\n", A, B);
		else
			printf("%d0%d\n", A, B);
	}
}