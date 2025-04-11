#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);

    vector<string> chunks;

    int tag_start_pos = -1;
    string chunk = "";
    for (int i = 0; i < line.length(); i++) {
        char c = line.at(i);

        if (c == ' ') continue;

        if (c == '<') {
            while (line.at(i) != '>') {
                chunk += line.at(i);
                i++;
            }
            chunk += line.at(i);
            chunks.push_back(chunk);
            chunk.clear();
            continue;
        }

        chunk += c;

        if (i == line.length() - 1 || line.at(i + 1) == ' ' ||
            line.at(i + 1) == '<') {
            string temp = "";
            auto iter = chunk.rbegin();
            while (iter != chunk.rend()) {
                temp += (*iter);
                iter++;
            }

            if (i != line.length() - 1 && line.at(i + 1) != '<') temp += ' ';

            // cout << "chunk: " << chunk << "\ntemp: " << temp << '\n' << '\n';

            chunks.push_back(temp);
            chunk.clear();
        }
    }

    for (auto chunk : chunks) {
        cout << chunk;
    }

    return 0;
}