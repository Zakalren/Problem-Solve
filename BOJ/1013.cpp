#include <bits/stdc++.h>

using namespace std;

bool solve(string str) {
    regex pattern("^(100+1+|01)+$");
    return regex_match(str, pattern);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        bool success = solve(line);
        cout << (success ? "YES" : "NO") << "\n";
    }

    return 0;
}