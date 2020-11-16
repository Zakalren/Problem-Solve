#include <iostream>

main()
{
    char str[1000000], ch;
    int num[26] = { 0 }, largest = 0, secondLargest = 0;
    scanf("%s", &str);
    
    for (char c : str)
    {
		if (!c) break;
		
        num[toupper(c) - 65]++;
    }
    
    for (int i = 0; i < 26; i++)
    {	
        if (num[i] >= largest)
        {
            secondLargest = largest;
            largest = num[i];
            ch = (char) i + 65;
        }
    }
    
    if (largest == secondLargest)
        printf("?");
    else
        printf("%c", ch);
}