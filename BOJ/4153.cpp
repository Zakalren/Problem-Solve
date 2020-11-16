#include <iostream>

main()
{
	int A, B, C, TMP;
	
	while (1)
	{
		scanf("%d %d %d", &A, &B, &C);
		
		if (A == 0)
			break;
		
		if (A > C)
		{
			TMP = C;
			C = A;
			A = TMP;
		}
		if (B > C)
		{
			TMP = C;
			C = B;
			B = TMP;
		}
		
		if (C*C == A*A + B*B)
			printf("right\n");
		else
			printf("wrong\n");
	}
}