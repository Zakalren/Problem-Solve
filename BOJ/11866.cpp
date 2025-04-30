#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    queue<int> ans;

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    cout << "<";
    int index = 0;
    while (!v.empty()) {
        index = (index + K - 1) % v.size();
        cout << v[index];
        v.erase(v.begin() + index);
        if (!v.empty()) cout << ", ";
    }
    cout << ">";

    return 0;
}