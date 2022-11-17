#include <iostream>
#include <string> 
using namespace std;
#define INF 987654321
int N, ans = INF;
string s1,s2;

void greedy(string s, int tmp) {
    int len = s.size();
    for(int i=1;i<len;i++) {
        if (s[i-1] == s2[i-1]) continue;
        for (int j=i-1;j<min(len, i+2);j++) {
            if (s[j]=='0') s[j]='1';
            else s[j]='0';
        }
        tmp++;
    }
    if(s.back() == s2.back()) {
        ans = min(ans, tmp);
    }
}

void solve() {
    greedy(s1, 0);
    for(int i=0;i<2;i++) {
        if (s1[i] == '0') s1[i]='1';
        else s1[i]='0';
    } 
    greedy(s1, 1);
    cout << (ans == INF ? -1 : ans);
}

int main() {
    cin >> N; 
    cin >> s1 >> s2;
    solve();
}