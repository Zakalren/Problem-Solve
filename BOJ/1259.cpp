#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    while (1) {
        cin >> N;

        if (!N) break;

        string line = to_string(N);

        bool success = true;
        for (int i = 0; i < line.size() / 2; i++) {
            if (line[i] != line[line.size() - i - 1]) success = false;
        }

        if (success)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}