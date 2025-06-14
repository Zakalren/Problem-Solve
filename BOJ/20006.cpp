#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<vector<pair<string, int>>> room(N);

    for (int i = 0; i < N; i++) {
        int level;
        string name;
        cin >> level >> name;

        for (auto& list : room) {
            if (list.empty()) {
                list.push_back({name, level});
                break;
            } else {
                if (list.size() >= M) continue;

                if (abs(level - list.front().second) <= 10) {
                    list.push_back({name, level});
                    break;
                }
            }
        }
    }

    for (auto& list : room) {
        if (list.empty()) continue;

        sort(list.begin(), list.end());

        if (list.size() >= M) {
            cout << "Started!\n";
        } else {
            cout << "Waiting!\n";
        }

        for (const auto& pair : list) {
            cout << pair.second << " " << pair.first << "\n";
        }
    }

    return 0;
}