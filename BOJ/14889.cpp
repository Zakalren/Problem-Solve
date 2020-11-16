#include <iostream>
#include <vector>
#include <algorithm>

int N, num[20][20], team[20], diff = 100000000;

void solve(int idx, int cnt)
{
    if (idx == N)
        return;

    if (cnt == N/2)
    {
        int S1 = 0, S2 = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (team[i] && team[j]) S1 += num[i][j];
                if (!team[i] && !team[j]) S2 += num[i][j];
            }

        diff = std::min(diff, abs(S1 - S2));
        return;        
    }

    team[idx] = 1;
    solve(idx+1, cnt+1);
    team[idx] = 0;
    solve(idx+1, cnt);
}

main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &num[i][j]);

    solve(0, 0);
    printf("%d", diff);
}