#include <iostream>

main()
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        int num;
		char str[20];
        scanf("%d %s", &num, &str);

        for (int i = 0; i < 20; i++)
        {
            if (!str[i]) break;
            
            char c = str[i];
            std::cout << std::string(num, c);
        }
        
        printf("\n");
    }
}