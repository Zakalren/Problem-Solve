#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    string line;
    cin >> line;

    int a_count = count(line.begin(), line.end(), 'a');
    
    string composed = line + line;

    int b_count = 0;
    for (int i = 0; i < a_count; i++) {
        if (composed[i] == 'b') b_count++;
    }
    ans = b_count;

    for (int i = 1; i < line.size(); i++) {
        if (composed[i - 1] == 'b') b_count--;
        if (composed[i + a_count - 1] == 'b') b_count++;

        ans = min(ans, b_count);
    }

    cout << ans;

    return 0;
}