#include <iostream>

main()
{
	int n;
	scanf("%d", &n);
	
	int result;
	
	for (int i = 1; i <= n; i++)
	{
		if (i < 100)
			result = i;
		
		else if (i == 1000)
			break;
		
		else
		{
			int arr[3];
			int k = i, j = 0;
			
			while (k > 0)
			{
				arr[j] = k % 10;
				k /= 10;
				j++;
			}
			
			if (arr[0] - arr[1] == arr[1] - arr[2])
				result++;
		}
	}
	
	printf("%d", result);
}