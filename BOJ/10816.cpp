#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> cards;
int N, M, tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        cards.push_back(tmp);
    }

    sort(cards.begin(), cards.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        cout << upper_bound(cards.begin(), cards.end(), tmp) -
                    lower_bound(cards.begin(), cards.end(), tmp)
             << " ";
    }

    return 0;
}