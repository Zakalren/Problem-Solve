#include <bits/stdc++.h>

using namespace std;

int heights[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int ans = 0;

        int t;
        cin >> t;

        vector<int> v;

        int h;
        for (int i = 0; i < 20; i++) {
            cin >> h;

            int offset = v.size();
            for (int j = 0; j < v.size(); j++) {
                if (v[j] > h) {
                    ans += v.size() - j;
                    offset = j;
                    break;
                }
            }

            v.insert(v.begin() + offset, h);   
        }

        cout << t << " " << ans << "\n";
    }

    return 0;
}