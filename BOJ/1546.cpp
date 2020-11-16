#include <iostream>
#include <algorithm>

main()
{
    int num;
    scanf("%d", &num);
    
    int score[num];
    
    for (int i = 0; i < num; i++)
    {
        int n;
        scanf("%d", &n);
        
        score[i] = n;
    }
    
    int max = *std::max_element(score, score+num);
	
    double result = 0;
    
    for (int i = 0; i < num; i++)
        result += (score[i] / (double) max) * 100.0;
	    
    printf("%lf", result / num);
}