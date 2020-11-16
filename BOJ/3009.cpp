#include <iostream>

main()
{
	int X[3], Y[3], X_POS = 0, Y_POS = 0;
	
	scanf("%d %d %d %d %d %d", &X[0], &Y[0], &X[1], &Y[1], &X[2], &Y[2]);
	
	if (X[0] == X[1])
		X_POS = X[2];
	else if (X[1] == X[2])
		X_POS = X[0];
	else if (X[0] == X[2])
		X_POS = X[1];

	if (Y[0] == Y[1])
		Y_POS = Y[2];
	else if (Y[1] == Y[2])
		Y_POS = Y[0];
	else if (Y[0] == Y[2])
		Y_POS = Y[1];
	
	printf("%d %d", X_POS, Y_POS);
}