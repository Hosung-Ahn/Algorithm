# include <iostream>
# include <string>
using namespace std;

string str;

int find_open(int s, int e) {
    for (int i = s; i <= e; i++) {
        if (str[i] == '(') return i;
    }
    return -1;
}

int find_end(int s, int e) {
    int cnt = 1;
    for (int i = s; i <= e; i++) {
        if (str[i] == '(') cnt++;
        else if (str[i] == ')') cnt--;

        if (cnt == 0) return i;
    }
    return -1;
}

int str_len(int s, int e) {
    int ns = find_open(s,e) + 1;
    if (ns == 0) return e - s + 1;
    else {
        int ne = find_end(ns, e) - 1;
        return str_len(s, ns-3) + (str[ns-2] - '0') * str_len(ns,ne) + str_len(ne+2, e);
    }

}

int main(){
    cin >> str;
    cout << str_len(0,str.size()-1);
}