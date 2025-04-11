#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < (int)ceil((double)N / 4); i++) {
        cout << "long ";
    }
    cout << "int";

    return 0;
}