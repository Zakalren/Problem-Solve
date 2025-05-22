#include <bits/stdc++.h>

using namespace std;

// int scores[101];

set<int> scores[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 19:20 ~ 19:57

    int N, E;
    cin >> N >> E;

    vector<vector<int>> v(E);

    // 1번 등장 횟수만큼 점수 부여하고
    // 1번이 등장했을때는 모두 점수 +1
    // 1번 등장 안했을때는 모두 다 최대점수인사람으로 설정

    for (int i = 0; i < E; i++) {
        int nums;
        cin >> nums;

        v[i].resize(nums);
        for (int j = 0; j < nums; j++) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());  // 오름차순 정렬 (1 있는지 찾기 쉽게)
    }

    int song_index = 0;
    for (auto& freq : v) {
        if (freq[0] == 1) {  // 선영이 있을경우
            for (int& person : freq) {
                scores[person].insert(song_index);
                // scores[person]++;
            }
            song_index++;
        }

        else {  // 선영이 없는경우
            set<int> unionSet;
            for (int& person : freq) {
                unionSet.insert(scores[person].begin(), scores[person].end());
            }

            for (int& person : freq) {
                scores[person] = unionSet;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (scores[i].size() == scores[1].size()) {
            cout << i << "\n";
        }
    }

    return 0;
}