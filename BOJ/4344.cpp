#include <iostream>

main()
{
    int num;
    scanf("%d", &num);
    
    while (num--)
    {
        int n, sum = 0, cnt = 0;
        scanf("%d", &n);
        
        int arr[n];
        
        for (int k = 0; k < n; k++)
        {
            scanf("%d", &arr[k]);
            sum += arr[k];
        }
        
        for (int k = 0; k < n; k++)
        {
            if (arr[k] > sum / n)
                cnt++;
        }

        printf("%.3lf%%\n", (double) cnt * 100 / n);
    }
}