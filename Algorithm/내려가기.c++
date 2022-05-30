# include <iostream>
# include <vector>
# include <cstdio>
using namespace std;


int main() { 
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    int max_n1,max_n2,max_n3;
    int min_n1,min_n2,min_n3;
    max_n1 = max_n2 = max_n3 = 0;
    min_n1 = min_n2 = min_n3 = 0;
    int n1,n2,n3, c1,c2,c3;
    for (int i = 0; i < n; i++) {
        cin >> n1 >> n2 >> n3;

        c1 = n1;
        c2 = n2;
        c3 = n3;

        c1 += max_n1;
        c2 += max_n2;
        c3 += max_n3;

        max_n1 = max(c1, c2);
        max_n2 = max(c1, max(c2,c3));
        max_n3 = max(c2,c3);

        c1 = n1;
        c2 = n2;
        c3 = n3;

        c1 += min_n1;
        c2 += min_n2;
        c3 += min_n3;

        min_n1 = min(c1,c2);
        min_n2 = min(c1,min(c2,c3));
        min_n3 = min(c2,c3);
    }

    cout << max_n2 << " " << min_n2 << endl;
}