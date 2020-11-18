#include <iostream>
#include <algorithm>

int N, num[500][500], max = -1000000000;

void solve()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
        {
            if (j == 0) num[i][j] += num[i-1][j];
            else if (j == i) num[i][j] += num[i-1][j-1];
            else num[i][j] += std::max(num[i-1][j-1], num[i-1][j]);
        }

    for (int i = 0; i < N; i++)
        max = std::max(max, num[N-1][i]);
}

main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            scanf("%d", &num[i][j]);

    solve();
    printf("%d", max);
}