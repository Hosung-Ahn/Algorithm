# include <iostream>
# include <map>
# include <string>
# include <vector>
using namespace std;

map<string,int> cache;
vector<string> board;

int count(const string &s) {
    int ret = 0;
    for (char x : s) {
        if (x == '0') ret++;
    }   
    return ret;
}


int main() {
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    int K; cin >> K;

    int result = 0;
    for (string s : board) {
        int cnt = count(s);
        if (cnt % 2 == K % 2 && cnt <= K) {
            cache[s]++;
            result = max(result, cache[s]);
        }
    }

    cout << result;
}

