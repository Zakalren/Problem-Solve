#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[100], answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int v;
    cin >> v;

    for (int i = 0; i < N; i++) {
        if (v == arr[i]) {
            answer += 1;
        }
    }

    cout << answer;

    return 0;
}