#include <bits/stdc++.h>

using namespace std;

set<int> nums;
set<vector<int>> s;
int N, M;

bool alreadyExists(vector<int> v) {
    vector<int> v1 = vector<int>(v);
    sort(v1.begin(), v1.end());

    return s.find(v1) != s.end();
}

void dfs(vector<int> v) {
    if (v.size() == M) {
        if (!alreadyExists(v)) s.insert(v);

        return;
    }

    for (int n : nums) {
        vector<int> v1 = vector<int>(v);
        v1.push_back(n);
        dfs(v1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        nums.insert(n);
    }

    dfs(vector<int>());

    for (auto v : s) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}