#include <iostream>
#include <list>
#include <string>

using namespace std;

string input, str;
int M;
char temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    list<char> l(input.begin(), input.end());
    auto cursor = l.end();

    cin >> M;
    while (M--) {
        cin >> str;
        if (str == "L") {
            if (cursor != l.begin()) {
                cursor--;
            }
        }

        else if (str == "D") {
            if (cursor != l.end()) {
                cursor++;
            }
        }

        else if (str == "B") {
            if (cursor != l.begin()) {
                cursor = l.erase(--cursor);
            }
        }

        else if (str == "P") {
            cin >> temp;
            l.insert(cursor, temp);
        }
    }

    for (cursor = l.begin(); cursor != l.end(); cursor++) {
        cout << *cursor;
    }

    return 0;
}