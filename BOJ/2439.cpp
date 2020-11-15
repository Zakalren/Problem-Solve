#include <iostream>
#include <string>

main()
{
    int num;
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++)
        std::cout << std::string(num - i, ' ').append(i, '*') << "\n";
}
