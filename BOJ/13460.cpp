// Unsolved yet

#include <iostream>

using namespace std;

struct Step {
    int red_x, red_y;
    int blue_x, blue_y;
    int count;
};

int N, M;

char map[11][11];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void solve(Step step) {

}

void move(int dx, int dy) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    Step step;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'R') {
                step.red_x = i;
                step.red_y = j;
            }

            if (map[i][j] == 'B') {
                step.blue_x = i;
                step.blue_y = j;
            }
        }
    }

    solve(step);
}