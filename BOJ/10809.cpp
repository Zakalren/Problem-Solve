#include <iostream>

main()
{
    char str[100];
    int arr[26];
    scanf("%s", &str);

    for (int i = 0; i < 26; i++)
        arr[i] = -1;
    
    for (int i = 0; i < 100; i++)
    {
        if (!str[i]) break;
        
        int ascii = str[i] - 97;
        
        if (arr[ascii] == -1)
            arr[ascii] = i;
    }
    
    for (int i = 0; i < 26; i++)
        printf("%d ", arr[i]);
}