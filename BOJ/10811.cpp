#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for (int i = 0; i <= N; i++) {
        v.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if (a == b) continue;

        reverse(v.begin() + a, v.begin() + b + 1);
    }

    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}