#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 50

int N,M,K;
int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

struct Fire {
    int r,c,m,s,d;
    Fire(int r, int c, int m, int s, int d) : r(r), c(c), m(m), s(s), d(d) { }
    void move() {
        r += dr[d]*s;
        r %= N;
        if(r < 0) r+=N;
        c += dc[d]*s;
        c %= N;
        if(c < 0) c+=N;
    }
};


bool cmp(const Fire &a, const Fire &b) {
    if (a.r == b.r) return a.c < b.c;
    return a.r < b.r;
}

vector<Fire> arr,tmp;

void oneTime() {
    for (Fire &f : arr) {
        f.move();
    }
    sort(arr.begin(), arr.end(), cmp);
    
    int sumM = 0, sumS = 0, sumD = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        sumM += arr[i].m;
        sumS += arr[i].s;
        sumD += arr[i].d % 2;
        cnt++;
        if (i+1 == arr.size() || arr[i].r != arr[i+1].r || arr[i].c != arr[i+1].c) {
            if (cnt > 1) {
                int k = (sumD != 0 && sumD != cnt);
                for (int j = 0; j < 4; j++) {
                    if (sumM/5 == 0) break; 
                    tmp.push_back(Fire(arr[i].r, arr[i].c, sumM/5, sumS/cnt, 2*j+k));
                }
            }
            else {
                tmp.push_back(arr[i]);
            }
            sumM = 0;
            sumS = 0;
            sumD = 0;
            cnt = 0;
        }
    }
    arr = tmp;
    tmp.clear();
}


int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        arr.push_back(Fire(r-1,c-1,m,s,d));
    }

    while(K--) {
        oneTime();
    }

    int result = 0;
    for (Fire &f : arr) {
        result += f.m;
    }
    cout << result;
}