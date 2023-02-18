#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, temp;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());    

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << binary_search(v.begin(), v.end(), temp) << '\n';
    }

    return 0;
}