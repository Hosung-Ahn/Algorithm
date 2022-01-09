# include <iostream>
# include <string>
using namespace std;

string str;

int find_open(int s, int e) {
    for (int i = s; i < e; i++) {
        if (str[i] == '(') return i+1;
    }
    return -1;
}

int find_close(int s, int e) {
    int open = 1, close = 0;
    for (int i = s; i < e; i++) {
        if (str[i] == '(') open++;
        else if (str[i] == ')') close++;

        if (open == close) return i;
    }
    return -1;
}

int string_len(int s, int e) {
    int ns = find_open(s,e);
    if ( ns == -1 ) return e-s;
    else {
        int ne = find_close(ns, e);
        cout << ns << " " << ne << endl;
        return (str[ns-2] - '0') * string_len(ns,ne) + e-s - (ne-ns) + 2;
    }
}

int main() {
    cin >> str;
    cout << string_len(0,str.size());
}
