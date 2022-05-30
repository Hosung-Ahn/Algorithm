#include <iostream>
#include <stack>
#include <string>
using namespace std;

const string opening = "([{", closing = ")]}";
string s; 

void solution() {
    stack<int> Pair;
    for (int i = 0; i < s.size(); i++) {
        int idx = opening.find(s[i]);
        if (idx >= 0 && idx <= 2) {
            Pair.push(idx);
        }
        else {
            if (Pair.empty()) {
                cout << "NO\n";
                return;
            }
            idx = closing.find(s[i]);
            if (Pair.top() != idx) {
                cout << "NO\n";
                return;
            }
            else {
                Pair.pop();
            }
        }
    }
    if (!Pair.empty()) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> s;
        solution();
    }

}