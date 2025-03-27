#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool comparator(pii p1, pii p2) { return p1.first < p2.first; }

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<pii> v;
        int N, a, b;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            pii applicant(a, b);
            v.push_back(applicant);
        }

        sort(v.begin(), v.end(), comparator);

        int res = 0, count = 0;
        for (auto p = v.begin(); p != v.end() - 1; p++) {
            cout << "first: " << (*p).second
                 << ", second: " << (*(p + 1)).second << '\n';
            if ((*p).second >= (*(p + 1)).second) {
                count++;
            } else {
                res = max(res, count + 1);
                count = 0;
            }
        }

        cout << res << '\n';
    }

    return 0;
}