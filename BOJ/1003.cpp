#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N, T;
pair<int, int> cnt[41];

pair<int, int> count_fibo(int n)
{
    if (n == 0)
        return make_pair(1, 0);
    if (n == 1)
        return make_pair(0, 1);

    if (cnt[n].first || cnt[n].second)
        return cnt[n];

    pair<int, int> last = count_fibo(n-1);
    pair<int, int> secondLast = count_fibo(n-2);

    return cnt[n] = make_pair(last.first+secondLast.first, last.second+secondLast.second);
}

main()
{
    scanf("%d", &N);

    while (N--)
    {
        scanf("%d", &T);
        pair<int, int> p = count_fibo(T);
        printf("%d %d\n", p.first, p.second);
    }
}