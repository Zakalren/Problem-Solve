#include <iostream>
#include <cmath>

main()
{
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	
	double result = (double) (V - A) / (A - B);
	
	printf("%d", (int)ceil(result) + 1);
}