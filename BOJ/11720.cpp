#include <iostream>

main()
{
    int n;
    scanf("%d", &n);
    
    char str[n];
    scanf("%s", &str);
    
    int result = 0;
    
    for (char c : str)
        result += c - 48;
    
    printf("%d", result);
}