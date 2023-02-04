#include <iostream>
#include <cmath>

/*  
Input Example
2
-5 1 12 1
7
1 1 8
-3 -1 1
2 2 2
5 5 1
-4 5 1
12 1 1
12 1 2
-5 1 5 1
1
0 0 2
*/

/*
Output Example
3
0
*/

int T, N, x, y, r, x1, x2, y3, y2, result;

int main() {
    scanf("%d", &T);
    while (T--) {
        result = 0;
        scanf("%d %d %d %d", &x1, &y3, &x2, &y2);
        scanf("%d", &N);

        while (N--) {
            scanf("%d %d %d", &x, &y, &r);

            int distance1 = pow(x - x1, 2) + pow(y - y3, 2);
            int distance2 = pow(x - x2, 2) + pow(y - y2, 2);
            int radiusSquared = pow(r, 2);

            if (distance1 > radiusSquared && distance2 < radiusSquared) 
                result++;
            if (distance1 < radiusSquared && distance2 > radiusSquared) 
                result++;
        }
        printf("%d\n", result);
    }

    return 0;
}