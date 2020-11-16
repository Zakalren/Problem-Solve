#include <iostream>

main()
{
    int origin, num, count;
    scanf("%d", &origin);

    num = origin;
    count = 0;
    
    do
    {
        int left, right, sum;
        left = (num / 10) % 10;
        right = num % 10;
        
        sum = left + right;
        
        if (sum < 10)
            num = (right * 10) + sum;
        else
            num = (right * 10) + (sum % 10);
        
        count++;
    }
    while (origin != num);
    
    printf("%d", count);
}