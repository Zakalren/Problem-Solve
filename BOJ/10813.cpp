#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int balls[101];
    for (int i = 1; i <= N; i++) {
        balls[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        swap(balls[a], balls[b]);
    }

    for (int i = 1; i <= N; i++) {
        cout << balls[i];
        if (i != N) {
            cout << ' ';
        }
    }

    return 0;
}