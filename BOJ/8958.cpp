#include <iostream>

main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		char str[80];
		scanf("%80s", str);
		
		int streak = 0, score = 0;
		
		for (char c : str)
		{
            if (!c)
                break;
            
			if (c == 'O')
				score += ++streak;
			else if (c == 'X')
				streak = 0;
		}
		
		printf("%d\n", score);
	}
}