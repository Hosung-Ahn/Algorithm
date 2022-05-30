#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
# define MAX 50

struct Node {
    int r,c,s;
    Node(int r, int c, int s) : r(r), c(c), s(s) {}
};

int board[MAX][MAX];
int board_copy[MAX][MAX];
vector<int> choice;
vector<Node> arr;
int N,M,K;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};


void rotation_n(int r, int c, int n) {
    int sr = r - n;
    int sc = c - n;
    int last = board_copy[sr][sc];

    for (int i = 0; i < 4; i++) { 
        for (int j = 1; j < 2*n+1; j++) {
            sr += dr[i];
            sc += dc[i];
            int tmp = board_copy[sr][sc];
            board_copy[sr][sc] = last;
            last = tmp;
        }
    }
}

int cal_value() {
    int ret = 987564321;
    for (int r = 0; r < N; r++) {
        int tmp = 0;
        for (int c = 0; c < M; c++) {
            tmp += board_copy[r][c];
        }
        ret = min(ret, tmp);
    }
    return ret;
}

void rotation(int r, int c, int s) {
    for (int n = 1; n <= s; n++) {
        rotation_n(r,c,n);
    }
}

void solution() {
    int result = 987564321;
    do {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board_copy[i][j] = board[i][j];
            }
        }
        for (int i : choice) {
            rotation(arr[i].r -1, arr[i].c -1, arr[i].s);
        }
        result = min(result, cal_value());
    } while(next_permutation(choice.begin(), choice.end()));

    cout << result;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int r,c,s; cin >> r >> c >> s;
        choice.push_back(i);
        arr.push_back(Node(r,c,s));
    }

    solution();
    
}