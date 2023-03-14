#include <iostream>
#include <set>

using namespace std;

set<int> s;
int N, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        s.insert(temp);
    }

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << ' ';
    }

    return 0;
}