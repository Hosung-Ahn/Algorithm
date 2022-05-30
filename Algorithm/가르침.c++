# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <map>
using namespace std;

vector<string> strs;
int N,M;
map<int,int> choice;
int result = 0;

void count() {
    int tmp = 0;
    for (string s : strs) {
        bool ok = true;
        for (int i = 4; i < s.size()-4; i++) {
            if (!choice[s[i]-'a']) {
                ok = false;
                break;
            }
        }
        if (ok) tmp++;
    }
    result = max(result, tmp);
}

bool already_choosed(int i) {
    char c = i+'a';
    if (c == 'a' || c == 'c' || c == 't' || c == 'i' || c == 'n') return true;
    return false;
}

void solution(int cnt, int idx) {
    if (cnt + 5 == M) {
        count();
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (already_choosed(i)) continue;
        choice[i] = 1;
        solution(cnt+1,i+1);
        choice[i] = 0;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        strs.push_back(s);
    }
    choice['a'-'a'] = 1;
    choice['c'-'a'] = 1;
    choice['t'-'a'] = 1;
    choice['i'-'a'] = 1;
    choice['n'-'a'] = 1;
    
    if (M < 5) cout << 0;
    else {
        solution(0,0);
        cout << result;
    }
    

}