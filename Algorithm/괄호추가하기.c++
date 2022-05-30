#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int N;
string S;
int result = INT32_MIN;

bool in_range(int idx) {
    if(idx < 0 || idx >= N) return false;
    return true;
}

bool can_bracket(vector<bool> bracket, int idx) {
    if (!in_range(idx-2) && !in_range(idx+2)) return !bracket[idx];
    else if (!in_range(idx-2)) {
        return !bracket[idx+2] && !bracket[idx]; 
    }
    else if (!in_range(idx+2)) {
        return !bracket[idx-2] && !bracket[idx]; 
    }
    else {
        return !bracket[idx-2] && !bracket[idx] && !bracket[idx+2];
    }
}

int cal(int a, char m, int b) {
    switch(m) {
        case '+' :
            return a + b;
        case '-' :
            return a - b;
        case '*' :
            return a * b;
    }
    return 0;
}

int cal(vector<bool>bracket) {
    int ret;
    ret = S[0]-'0';

    for (int i = 0; i < N-2; i += 2) {
        if (bracket[i+2]) {
            ret = cal(ret, S[i+1], cal(S[i+2]-'0', S[i+3], S[i+4]-'0'));
            i += 2;
        }
        else {
            ret = cal(ret, S[i+1], S[i+2]-'0');
        }
    }
    return ret;
}

void dfs(vector<bool> bracket, int depth) {
    result = max(result, cal(bracket));
    if (depth == (N+1)/4 ) return;
    for (int i = 0; i < N-2; i+=2) {
        if (can_bracket(bracket, i)) {
            bracket[i] = true;
            dfs(bracket, depth+1);
            bracket[i] = false;
        }
    }
}





int main() {
    cin >> N >> S;
    vector<bool> bracket(N,0);
    dfs(bracket, 0);
    cout << result; 
}