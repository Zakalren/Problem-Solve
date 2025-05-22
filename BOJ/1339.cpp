#include <bits/stdc++.h>

using namespace std;

map<char, int> score_map;
map<char, int> rank_map;

string lines[10];

bool compare(pair<char, int> a,
             pair<char, int> b) {  // pair.second 내림차순 정렬
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        score_map[ch] = 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> lines[i];

        // 자리수 별 가중치를 둬서 합하고, 합이 높은 알파벳 순서대로 9, 8, 7 ...
        // 부여하기
        for (int j = 0; j < lines[i].size(); j++) {
            score_map[lines[i][j]] += pow(10, lines[i].size() - j - 1);
        }
    }

    vector<pair<char, int>> v(score_map.begin(), score_map.end());
    sort(v.begin(), v.end(), compare);

    int rank = 9;
    for (auto& pair : v) {
        char ch = pair.first;
        rank_map[ch] = rank;
        rank--;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        string line = lines[i];

        int temp_sum = 0;
        for (int j = 0; j < line.size(); j++) {
            temp_sum *= 10;
            temp_sum += rank_map[line[j]];
        }

        sum += temp_sum;
    }

    cout << sum;

    // sort(score, score+26, greater<int>()); // 내림차순 정렬

    return 0;
}