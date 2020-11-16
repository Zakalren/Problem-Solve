#include <iostream>
#include <cmath>

main()
{
    int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int product = a * b * c;
	int length = log10(product) + 1;
	
	int count[10] = { 0 };
	
	for (int i = 0; i < length; i++)
	{
		int num = (int) (product / pow(10, i)) % 10;
		count[num]++;
	}
	
	for (int i = 0; i < 10; i++)
		printf("%d\n", count[i]);
}