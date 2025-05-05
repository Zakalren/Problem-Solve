#include <bits/stdc++.h>

using namespace std;

pair<int, int> pairs[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> pairs[i].second >> pairs[i].first;
    }

    sort(pairs, pairs + N);

    int count = 1, last = 0;
    for (int i = 1; i < N; i++) {
        if (pairs[i].second >= pairs[last].first) {
            last = i;
            ++count;
        }
    }

    cout << count;

    return 0;
}