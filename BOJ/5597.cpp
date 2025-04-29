#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nums[31] = {0};
    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        nums[n] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        if (!nums[i]) cout << i << '\n';
    }

    return 0;
}