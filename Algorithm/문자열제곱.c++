#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPartialMatch(const string &N) {
    int n = N.size();
    vector<int> ret(n,0);
    int begin = 1, matched = 0;

    while(begin + matched < n) {
        if (N[begin + matched] == N[matched]) {
            matched++;
            ret[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) begin++;
            else {
                begin += matched - ret[matched-1];
                matched = ret[matched-1];
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(1) {
        string s; cin >> s;
        if (s == ".") break;
        vector<int> pi = getPartialMatch(s);
        int div = s.size() - pi[s.size()-1];
        cout << (s.size() % div == 0 ? s.size()/div : 1) << "\n";
    }
}
