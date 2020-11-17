#include <iostream>

main()
{
    char str[20];
    scanf("%s", &str);
    
    for (int i = 0; i < 20; i++)
    {
        if (!str[i])
            break;
            
        printf("\'%c\'\n", str[i]);
    }
}