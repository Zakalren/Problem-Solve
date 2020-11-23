#include <iostream>
#include <algorithm>

int N, score[300], sum[300];

void solve()
{
    sum[0] = score[0];
    sum[1] = score[0] + score[1];
    sum[2] = std::max(score[0], score[1]) + score[2];

    for (int i = 3; i < N; i++)
        sum[i] = std::max(score[i-1] + sum[i-3], sum[i-2]) + score[i];
}

main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &score[i]);

    solve();

    printf("%d", sum[N-1]);
}