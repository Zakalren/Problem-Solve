#include <iostream>

using namespace std;

int N, A[1000001], B, C;
long long int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        A[i] -= B;
        ans++;
        if (A[i] > 0) {
            ans += A[i] / C;
            if (A[i] % C != 0) ans++;
        }
    }

    cout << ans;

    return 0;
}