#include <bits/stdc++.h>

using namespace std;

pair<int, int> jewels[300000];
int bags[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long ans = 0;

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> jewels[i].first >>
            jewels[i].second;  // first: 무게, second: 가치
    }

    for (int i = 0; i < K; i++) {
        cin >> bags[i];
    }

    // 무게 오름차순으로 보석 정렬, 가방도 용량 오름차순으로 정렬
    // 이렇게 하면 i번째 가방에 들어갈 수 있는 보석은 i+1번째 가방에도 들어갈 수
    // 있기 때문에 생각하기 편함

    sort(jewels, jewels + N);
    sort(bags, bags + K);

    priority_queue<int> pq;

    int j = 0;
    for (int i = 0; i < K; i++) {
        while (j < N && jewels[j].first <= bags[i]) {
            pq.push(jewels[j].second);
            j++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}