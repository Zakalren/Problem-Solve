#include <bits/stdc++.h>

using namespace std;

string N;
set<string> s;

void solve(int left, int right, string cur, string path) {
    if (cur.size() == N.size()) {
        s.insert(path);
        return;
    }

    if (left > 0) {
        string nxt = N[left - 1] + cur;
        solve(left - 1, right, nxt, path + nxt);
    }

    if (right < N.size() - 1) {
        string nxt = cur + N[right + 1];
        solve(left, right + 1, nxt, path + nxt);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N.size(); i++) {
        string start = string(1, N[i]);
        solve(i, i, start, start);
    }

    cout << s.size();

    return 0;
}