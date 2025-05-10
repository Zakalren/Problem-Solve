#include <bits/stdc++.h>

using namespace std;

long long dist[100000];
long long costs[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }

    // 여태 방문한 도시 중에 가장 싼 기름값을 기준으로 다음 행선지에 갈 수
    // 있을만큼의 기름을 구매함
    // 마지막 도시는 어차피 종점이므로 기름 구매 필요 X

    long long total = 0;
    long long min_cost = costs[0];

    for (int i = 0; i < N - 1; i++) {
        min_cost = min(min_cost, costs[i]);
        total += min_cost * dist[i];
    }

    cout << total;

    return 0;
}