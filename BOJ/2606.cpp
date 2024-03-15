#include <bits/stdc++.h>

using namespace std;

int N, M, v[101], cnt = 0;
vector<int> arr[101]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int i, j;
    for (int k = 0; k < M; k++) {
        cin >> i >> j;
        arr[i].push_back(j);
        arr[j].push_back(i);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        v[num] = 1;
        
        for (int i = 0; i < arr[num].size(); i++) {
            if (!v[arr[num][i]]) {
                v[arr[num][i]] = 1;
                q.push(arr[num][i]);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}