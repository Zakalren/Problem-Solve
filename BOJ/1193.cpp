#include <iostream>

main()
{
    int X, count = 0;
    scanf("%d", &X);
    
    while (X > 0)
        X -= ++count;

    int i = 1;
    
    for (;i < count + 1; i++)
        if (X++ == 0)
            break;
	
	if (count % 2 == 0)
		printf("%d/%d", count - i + 1, i);
	
	else
		printf("%d/%d", i, count - i + 1);
}