#include <iostream>
#include <cstring>

main()
{
    int num, total;
    scanf("%d", &num);
	total = num;
	
    while (num--)
    {
        char str[101];
        int chr[26] = { 0 };
        scanf("%s", str);
        
        for (int i = 0; i < strlen(str); i++)
        {
			char c = str[i];
			
			int index = c - 'a';
			
			if (chr[index] != 0)
			{
				total--;
				break;
			}

			if (c != str[i+1])
        		chr[index]++;
        }
    } 
	
	printf("%d", total);
}