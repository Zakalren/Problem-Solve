#include <bits/stdc++.h>

using namespace std;

int counts[26][200000];

void countAlphabets(string& str) {
    counts[str[0] - 'a'][0]++;

    for (int i = 1; i < str.size(); i++) {
        for (int j = 0; j < 26; j++) {
            counts[j][i] = counts[j][i - 1];
        }
        counts[str[i] - 'a'][i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;

    countAlphabets(line);

    int N;
    cin >> N;

    char alphabet;
    int l, r;
    while (N--) {
        cin >> alphabet >> l >> r;

        int ans = 0;

        if (l == 0)
            ans = counts[alphabet - 'a'][r];
        else
            ans = counts[alphabet - 'a'][r] - counts[alphabet - 'a'][l - 1];

        cout << ans << "\n";
    }

    return 0;
}