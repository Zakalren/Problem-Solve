#include <iostream>
#include <cmath>

main()
{
	int T, X1, Y1, R1, X2, Y2, R2, d;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d %d %d %d %d %d", &X1, &Y1, &R1, &X2, &Y2, &R2);
        
		d = (X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2);
		
        if (X1==X2 && Y1==Y2 && R1==R2)
            printf("-1\n");
        else if (sqrt(d) > R1+R2)
            printf("0\n");
        else if (sqrt(d) == R1+R2)
            printf("1\n");
        else if (d > (R1-R2)*(R1-R2))
            printf("2\n");
        else if (d == (R1-R2)*(R1-R2))
            printf("1\n");
        else
            printf("0\n");
    }
}