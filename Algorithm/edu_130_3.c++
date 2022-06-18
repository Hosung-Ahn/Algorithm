#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> visited;
int N;
string s1,s2;
bool result = false;

void swap(int i) {
    char tmp = s1[i];
    s1[i] = s1[i+1];
    s1[i+1] = tmp;
}

void dfs() {
    if (visited[s1]) return;
    visited[s1] = 1;
    if (s1 == s2) {
        result = true;
        return;
    }

    for (int i = 0; i < N-1; i++) {
        if (s1[i] == 'a' && s1[i+1] == 'b') {
            swap(i);
            dfs();
            swap(i);
        }
        if (s1[i] == 'b' && s1[i+1] == 'c') {
            swap(i);
            dfs();
            swap(i);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        result = false;
        cin >> N >> s1 >> s2;
        dfs();
        if (result) cout << "YES\n";
        else cout << "NO\n";
        visited.clear();
    }
}
