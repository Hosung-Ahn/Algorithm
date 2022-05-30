# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

# define MAX 11
int food[MAX][MAX];
int food_cage[MAX][MAX];
vector<int> alive[MAX][MAX];
vector<int> died[MAX][MAX];
int dr[] = {0,1,1,1,0,-1,-1,-1};
int dc[] = {1,1,0,-1,-1,-1,0,1};
int N,M,K;


bool in_range(int r, int c) {
    if (r < 1 || r > N || c < 1 || c > N) return false;
    return true;
}

void spring_summer(int r, int c) {
    int del = 0;
    bool end = false;
    for (int &age : alive[r][c]) {
        if (food[r][c] >= age && !end) {
            food[r][c]-= age;
            age++;
        }
        else {
            end = true;
            food[r][c] += age/2;
            del++;
        }
    }

    for (int i = 0; i < del; i++) {
        alive[r][c].pop_back();
    }
}

void fall(int r, int c) {
    for (int age : alive[r][c]) {
        if (age % 5 == 0) {
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!in_range(nr,nc)) continue;
                alive[nr][nc].push_back(1);
            }
        }
    }
}

void winter(int r, int c) {
    food[r][c] += food_cage[r][c];
}

void sort_alive(int r, int c) {
    sort(alive[r][c].begin(), alive[r][c].end());
}

void (*fp[])(int,int) = {sort_alive,spring_summer, fall, winter};

void one_year() {
    for (int i = 0; i < 4; i++) {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                fp[i](r,c);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            food[r][c] = 5;
            cin >> food_cage[r][c];
        }
    }

    for (int i = 0; i < M; i++) {
        int r, c, age; cin >> r >> c >> age;
        alive[r][c].push_back(age);
    }

    for (int i = 0; i < K; i++) {
        // cout << i << endl;
        one_year();
    }

    int result = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            result += alive[r][c].size();
        }   
    }

    cout << result;
}