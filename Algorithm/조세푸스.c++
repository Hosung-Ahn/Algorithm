#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N,K; 
        list<int> lst;
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            lst.push_back(i);
        }
        list<int>::iterator iter = lst.begin();
        while(lst.size() > 2) {
            iter = lst.erase(iter);
            if (iter == lst.end()) iter++;
            for (int i = 0; i < K-1; i++) {
                iter++;
                if (iter == lst.end()) iter++;
            }
        }
        int a = lst.front(), b = lst.back();
        if (a < b) cout << a << " " << b << "\n";
        else cout << b << " " << a << "\n";
    }
}