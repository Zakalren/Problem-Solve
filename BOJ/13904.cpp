#include <bits/stdc++.h>

using namespace std;

pair<int, int> scores[1001];
int parent[1001];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a != b) parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, ans = 0;
    cin >> N;

    // 4 60
    // 2 50
    // 4 40
    // 3 30
    // 1 20
    // 4 10
    // 6 5

    // pair 다 넣고 해당 날의 인덱스에 다른 점수가 있으면 인덱스- 해서 넣을 수
    // 있는 날짜 있는지 알아보기

    int max_deadline = 0;
    for (int i = 0; i < N; i++) {
        cin >> scores[i].second >> scores[i].first;  // 점수, 마감기한 순서
        max_deadline = max(max_deadline, scores[i].second);
    }

    for (int i = 1; i <= max_deadline; i++) {
        parent[i] = i;
    }

    sort(scores, scores + N, greater<pair<int, int>>());  // 점수 내림차순 정렬

    for (int i = 0; i < N; i++) {
        int score = scores[i].first;
        int deadline = scores[i].second;

        int day = find_parent(deadline);
        if (day == 0) continue;

        ans += score;
        union_parent(day, day - 1);
    }

    cout << ans;

    return 0;
}