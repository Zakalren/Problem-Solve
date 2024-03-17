#include <bits/stdc++.h>

using namespace std;

int N, tmp;
vector<int> children[51];

int dfs(int idx) {
    if (children[idx].empty()) 
        return 1;

    vector<int> v;
    for (int i = 0; i < children[idx].size(); i++) {
        v.push_back(dfs(children[idx][i]));
    }
    sort(v.begin(), v.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans = max(ans, v[i]+i);
    }

    return ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> tmp;
    for (int i = 1; i < N; i++) {
        cin >> tmp;
        children[tmp].push_back(i);
    }

    cout << dfs(0) - 1;

    return 0;
}