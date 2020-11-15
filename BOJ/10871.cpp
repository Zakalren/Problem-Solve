#include <iostream>

main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        
        if (k < x)
			printf("%d ", k);
    }
}
