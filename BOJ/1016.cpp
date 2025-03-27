#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<ll> num_list;
    ll m, M;
    cin >> m >> M;

    for (ll i = m; i <= M; i++) {
        num_list.insert(i);
    }

    for (int i = 2; i <= sqrt(M); i++) {
        ll powered = (ll)i * i;
        ll coef = 0;

        if (m % powered == 0) {
            coef = m / powered;
        } else {
            coef = (m / powered) + 1;
        }

        for (ll s = powered * coef; s <= M; s += powered) {
            num_list.erase(s);
        }
    }

    cout << num_list.size();

    return 0;
}