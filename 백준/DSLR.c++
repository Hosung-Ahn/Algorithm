# include <iostream>
# include <string>
# include <string.h>
# include <queue>
# include <vector>
# include <cstdio>
using namespace std;

# define MAX 10000

int cnt[MAX];

void set_four(string &s) {
    while (s.size() < 4) {
        s.insert(s.begin(), '0');
    }
}

string D(string s) {
    int si = stoi(s);
    si *= 2;
    si %= MAX;
    
    string ret = to_string(si);
    set_four(ret);
    return ret;
}

string D_inverse(string s, bool plus_10000 = false) {
    int si = stoi(s);
    if (plus_10000) si += 10000;
    si /= 2;
    string ret = to_string(si);
    set_four(ret);
    return ret;
}

string S(string s) {
    int si = stoi(s);
    if (si == 0) return "9999";
    
    si -= 1;

    string ret = to_string(si);
    set_four(ret);
    return ret;
}

string S_inverse(string s) {
    int si = stoi(s);
    if (si == 9999) return "0000";

    si += 1;

    string ret = to_string(si);
    set_four(ret);
    return ret;
}

string R(string s) {
    s.insert(s.begin(), s.back());
    s.pop_back();
    return s;
}

string L(string s) {
    s.push_back(s.front());
    s.erase(s.begin());
    return s;
}

string (*funcptr[])(string) = { D, S, R, L};
vector<char> result;

int bfs(string start, string end) {
    cnt[stoi(start)] = 0;
    queue<string> q;
    q.push(start);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        
        if (cur == end) {
            return cnt[stoi(cur)];
        }
        for (int i = 0; i < 4; i++) {
            string next = (*funcptr[i])(cur);
            if (cnt[stoi(next)] != -1) continue;
            cnt[stoi(next)] = cnt[stoi(cur)] + 1;
            q.push(next);
        }

    }
    return 0;
}

void print_inverse(string last, int cur_cnt) {
    if (cur_cnt == 0) return;

    string next = L(last);
    if (cnt[stoi(next)] == cur_cnt-1) {
        result.push_back('R');
        return print_inverse(next, cur_cnt-1);
    }

    next = R(last);
    if (cnt[stoi(next)] == cur_cnt-1) {
        result.push_back('L');
        return print_inverse(next, cur_cnt-1);
    }

    next = S_inverse(last);
    if (cnt[stoi(next)] == cur_cnt-1) {
        result.push_back('S');
        return print_inverse(next, cur_cnt-1);
    }

    if (stoi(last) % 2 == 0) {
        next = D_inverse(last);
        if (cnt[stoi(next)] == cur_cnt-1) {
            result.push_back('D');
            return print_inverse(next, cur_cnt-1);
        }
        next = D_inverse(last, true);
        if (cnt[stoi(next)] == cur_cnt-1) {
            result.push_back('D');
            return print_inverse(next, cur_cnt-1);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;

    for (int t = 0; t < T; t++) {

        result.clear();
        memset(cnt, -1, sizeof(int)*MAX);
        string start, end; cin >> start >> end;
        set_four(start);
        set_four(end);
        
        int last_cnt = bfs(start, end);

        print_inverse(end, last_cnt);

        vector<char>::reverse_iterator iter;

        for (iter = result.rbegin(); iter != result.rend(); iter++) 
            cout << *iter;
        cout << "\n";

    }
}