#include <bits/stdc++.h>

using namespace std;

int N, M;

char letters[15];
char arr[15];

bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dfs(int depth, int start) {
    if (depth == N) {
        int vowel_count = 0, consonant_count = 0;
        for (int i = 0; i < N; i++) {
            if (is_vowel(arr[i]))
                vowel_count++;
            else
                consonant_count++;
        }

        if (vowel_count >= 1 && consonant_count >= 2) {
            for (int i = 0; i < N; i++) {
                cout << arr[i];
            }
            cout << "\n";
        }
    }

    else {
        for (int i = start; i < M; i++) {
            arr[depth] = letters[i];
            dfs(depth + 1, i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> letters[i];
    }

    sort(letters, letters + M);
    dfs(0, 0);

    return 0;
}