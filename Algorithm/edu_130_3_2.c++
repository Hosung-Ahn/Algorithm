#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> visited;
int N;
string s1,s2;

void swap(int i, int j) {
    char tmp = s1[i];
    s1[i] = s1[j];
    s1[j] = tmp;
}

void solution() {
    for (int i = 0; i < N; i++) {
        if (s1[i] == s2[i]) continue;
        
        bool find = false;
        if (s2[i] == 'b') {
            for (int j = i; j < N; j++) {
                if (s1[j] == 'a') continue;
                if (s1[j] == 'b') {
                    swap(i, j);
                    find = true;
                    break;
                }
                else {
                    cout << "NO\n";
                    return;
                }
            }
        }
        else if (s2[i] == 'c') {
            for (int j = i; j < N; j++) {
                if (s1[j] == 'b') continue;
                if (s1[j] == 'c') {
                    swap(i, j);
                    find = true;
                    break;
                }
                else {
                    cout << "NO\n";
                    return;
                }
            }
        }
        if (!find) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        cin >> N >> s1 >> s2;
        solution();
    }
}
