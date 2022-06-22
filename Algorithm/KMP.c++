#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> getPartialMatch(const string &N) {
    int n = N.size();
    vector<int> ret(n,0);
    int begin = 1, matched = 0;
    while (begin + matched < n) {
        if (N[begin+matched] == N[matched]) {
            matched++;
        }
    }
}

vector<int> KMP(const string &H, const string &N) {
    int h = H.size();
    int n = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;

    while(begin <= h-n) {
        if (matched < n && H[begin + matched] == N[matched]) {
            matched++;
            if (matched == n) ret.push_back(begin);
        }
        // 현재 matched 는 일치한 마지막 index가 아니라
        // 마지막 index의 한칸 뒤로 처음으로 일치하지 않은 index를 가리킨다.
        else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

}

int main() {

}
