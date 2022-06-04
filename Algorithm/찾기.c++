#include <iostream>
#include <string>
#include <vector>
using namespace std;

//이해안감
vector<int> getPartialMatch(const string &P) {
    int p = P.size();
    vector<int> pi(p,0);

    int begin = 1, matched = 0;

    while (begin + matched < p) {
        if (P[begin + matched] == P[matched]) {
            matched++;
            pi[begin + matched -1] = matched;
        }
        else {
            if (matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> kmpSearch(const string &T, const string &P) {
    int t = T.size();
    int p = P.size();
    vector<int> pi = getPartialMatch(P);
    vector<int> ret;
    int begin = 0, matched = 0;
    while (begin <= t-p) {
        // matched < p 라는 조건부를 줌으로써 다 찾았을 경우 else문으로 넘어가게 한다.
        if (matched < p && T[begin+matched] == P[matched]) {
            matched++;
            if (matched == p) ret.push_back(begin);
        }
        else {
            if (matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int main() {
    string T,P;
    getline(cin, T);
    getline(cin, P);
    vector<int> result = kmpSearch(T,P);
    cout << result.size() << endl;
    for (int x : result) {
        cout << x+1 << " ";
    }
}