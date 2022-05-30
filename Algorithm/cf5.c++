#include <iostream>
#include <vector>
using namespace std;
# define MAX 100000
pair<int,int> Up[MAX][2];

int dr[] = {1,0};
int dc[] = {0,1};

int cal(int sr, int sc, int er, int ec) {
    int sl = max(sr,sc);
    int el = max(er,ec);
    if (sr == er && sc == ec) return 0;
    else if (sr == er) return abs(sc-ec);
    else if (sc == ec) return abs(sr-er);
    else return abs(sr-sl) + abs(sc-sl) + abs(er-el) + abs(ec-el);
}

int find(int sr, int sc, int er, int ec) {
    int sl = max(sr,sc);
    int el = max(er,ec);
    if (sl == el) return cal(sr,sc,er,ec);
    int row = 1 + cal(sr,sc, Up[sl][0].first, Up[sl][0].second) 
              + find(Up[sl][0].first + dr[0], Up[sl][0].second + dc[0], er,ec);
    int col = 1 + cal(sr,sc, Up[sl][1].first, Up[sl][1].second) 
              + find(Up[sl][1].first + dr[1], Up[sl][1].second + dc[1], er,ec);

    return min(row,col);
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        Up[i][0] = make_pair(a-1,b-1);
        Up[i][1] = make_pair(c-1,d-1);
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        int sl = max(a,b);
        int el = max(c,d);
        if(sl > el) {
            swap(a,c);
            swap(b,d);
        }
        cout << find(a-1,b-1,c-1,d-1) << "\n";
    }
}
