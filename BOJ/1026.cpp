#include <algorithm>
#include <iostream>

using namespace std;

int N, sum, A[50], B[50];

bool great(int a, int b) { return a > b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N, great);

    for (int i = 0; i < N; i++) {
        sum += A[i] * B[i];
    }

    cout << sum;

    return 0;
}