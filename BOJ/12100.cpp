#include <bits/stdc++.h>

using namespace std;

int N;

vector<vector<int>> graph;
int memo[5][4];

int ans;

int find_max(const vector<vector<int>>& v) {
    int ret = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ret = max(ret, v[i][j]);
        }
    }

    return ret;
}

void merge_blocks(vector<vector<int>>& v, int direction) {
    // left
    if (direction == 0) {
        for (int i = 0; i < N; i++) {
            vector<int> v1;

            for (int j = 0; j < N; j++) {
                if (v[i][j] != 0) v1.push_back(v[i][j]);
            }

            for (int j = 0; j < (int)v1.size() - 1; j++) {
                if (v1[j] == v1[j + 1]) {
                    v1[j] *= 2;
                    v1.erase(v1.begin() + j + 1);
                }
            }

            for (int j = 0; j < N; j++) {
                if (j < v1.size())
                    v[i][j] = v1[j];
                else
                    v[i][j] = 0;
            }
        }
    }

    // right
    else if (direction == 1) {
        for (int i = 0; i < N; i++) {
            vector<int> v1;

            for (int j = N - 1; j >= 0; j--) {
                if (v[i][j] != 0) v1.push_back(v[i][j]);
            }

            for (int j = 0; j < (int)v1.size() - 1; j++) {
                if (v1[j] == v1[j + 1]) {
                    v1[j] *= 2;
                    v1.erase(v1.begin() + j + 1);
                }
            }

            for (int j = 0; j < N; j++) {
                if (j < v1.size())
                    v[i][N - 1 - j] = v1[j];
                else
                    v[i][N - 1 - j] = 0;
            }
        }
    }

    // up
    else if (direction == 2) {
        for (int i = 0; i < N; i++) {
            vector<int> v1;

            for (int j = 0; j < N; j++) {
                if (v[j][i] != 0) v1.push_back(v[j][i]);
            }

            for (int j = 0; j < (int)v1.size() - 1; j++) {
                if (v1[j] == v1[j + 1]) {
                    v1[j] *= 2;
                    v1.erase(v1.begin() + j + 1);
                }
            }

            for (int j = 0; j < N; j++) {
                if (j < v1.size())
                    v[j][i] = v1[j];
                else
                    v[j][i] = 0;
            }
        }
    }

    // down
    else if (direction == 3) {
        for (int i = 0; i < N; i++) {
            vector<int> v1;

            for (int j = N - 1; j >= 0; j--) {
                if (v[j][i] != 0) v1.push_back(v[j][i]);
            }

            for (int j = 0; j < (int)v1.size() - 1; j++) {
                if (v1[j] == v1[j + 1]) {
                    v1[j] *= 2;
                    v1.erase(v1.begin() + j + 1);
                }
            }

            for (int j = 0; j < N; j++) {
                if (j < v1.size())
                    v[N - 1 - j][i] = v1[j];
                else
                    v[N - 1 - j][i] = 0;
            }
        }
    }
}

// direction: 0: left, 1: right, 2: up, 3: down
void solve(vector<vector<int>> v, int depth) {
    ans = max(ans, find_max(v));

    if (depth == 5) return;

    for (int i = 0; i < 4; i++) {
        vector<vector<int>> next = v;
        merge_blocks(next, i);
        solve(next, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    graph.resize(N);

    for (int i = 0; i < N; i++) {
        graph[i].resize(N);

        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    solve(graph, 0);

    cout << ans << '\n';

    return 0;
}