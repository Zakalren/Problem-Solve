#include <iostream>
#include <algorithm>

main()
{
	int X, Y, W, H, M1, M2;
	scanf("%d %d %d %d", &X, &Y, &W, &H);
	
	M1 = std::min(X, Y);
	M2 = std::min(W-X, H-Y);
	
	printf("%d", std::min(M1, M2));
}