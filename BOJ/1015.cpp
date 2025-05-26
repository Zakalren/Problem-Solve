#include <bits/stdc++.h>

using namespace std;

int freq[1001];

int get_index(vector<int>& v, int node) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == node) return i;
    }

    return -1;
}

int freq_count(vector<int>& v, int node) {
    int res = 0;

    for (int& num : v) {
        if (num == node) res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N), ans(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());

    for (int& num : v) {
        int index = get_index(sorted, num) + (freq[num]++);

        ans.push_back(index);
    }

    for (int& num : ans) {
        cout << num << " ";
    }

    return 0;
}