#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 10001

struct Node {
    string num;
    int mod;
    Node(string num, int mod) : num(num), mod(mod) {}
};

void solve(){
    string d; int n,m;
    cin >> d >> n >> m;
    sort(d.begin(), d.end());

    queue<Node> q;
    bool visited[MAX][2] = {0,};

    for(char c : d) {
        string num = "";
        num.push_back(c);
        int mod = (c-'0')%n;
        bool up = stoi(num)>=n+m;

        if (visited[mod][up]) continue;
        q.push(Node(num,mod));
        visited[mod][up] = true;
    }

    while(!q.empty()) {
        string cur_num = q.front().num;
        int cur_mod = q.front().mod;
        bool cur_up;
        if (cur_num.size()>=6) cur_up = true;
        else cur_up = stoi(cur_num)>=n+m;
        q.pop();

        if (cur_mod == m && cur_up) {
            cout << cur_num << "\n";
            return;
        }

        for(char c : d) {
            string next_num = cur_num + c;
            int next_mod = (cur_mod*10 + c-'0')%n;
            bool next_up;
            if (next_num.size() >= 6) next_up = true;
            else next_up = stoi(next_num)>=n+m;
            
            if(visited[next_mod][next_up]) continue;
            visited[next_mod][next_up] = true;
            q.push(Node(next_num, next_mod));
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    int T; cin >> T;
    while(T--) {
        solve();
    }
}