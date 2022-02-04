# include <iostream>
# include <string>
# include <cstdio>

using namespace std;

string s1,s2; 

void print_result() {
    int cnt = 0;
    if (s1.size() != s2.size()) {
        cout << cnt;
        return;
    }

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) break;
        if (s1[i] == '8') cnt++;
    }
    cout << cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> s1 >> s2;
    print_result();
    
}
