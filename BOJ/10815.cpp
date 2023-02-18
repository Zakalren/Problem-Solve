#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, temp;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> temp;
        v.push_back(temp); 
    }
    sort(v.begin(), v.end());

    cin >> M;
    while (M--) {
        cin >> temp;
        cout << binary_search(v.begin(), v.end(), temp) << ' ';
    }

    return 0;
}