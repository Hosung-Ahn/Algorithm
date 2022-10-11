#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 101
bool board[MAX][MAX][3] = {0,};
int N;

struct Node {
    int x,y,a;
    Node(int x, int y, int a) : x(x), y(y), a(a) {}

    bool operator<(const Node &other) {
        if (x == other.x) {
            if (y == other.y) {
                return a > other.a;
            }
            return y < other.y;
        }
        return x < other.x;
    }
};

bool can_build_1(int r, int c) {
    if (r==0) return true;
    if (board[r][c][2]) return true;
    if (c>0 && board[r][c-1][2]) return true;
    if (r>0 && board[r-1][c][1]) return true;
    return false;
}

bool can_build_2(int r, int c) {
    if (r>0 && board[r-1][c][1]) return true;
    if (r>0 && c<N && board[r-1][c+1][1]) return true;
    if (c>0 && c<N-1 && board[r][c-1][2] && board[r][c+1][2]) return true;
    return false;
}

bool can_delete_1(int r, int c) {
    bool ret = true;
    board[r][c][1] = false;
    if (board[r+1][c][1] && !can_build_1(r+1,c)) ret = false;
    if (board[r+1][c][2] && !can_build_2(r+1,c)) ret = false;
    if (c>0 && board[r+1][c-1][2] && !can_build_2(r+1,c-1)) ret = false;
    board[r][c][1] = true;
    return ret;
}

bool can_delete_2(int r, int c) {
    bool ret = true;
    board[r][c][2] = false;
    if (board[r][c][1] && !can_build_1(r,c)) ret = false;
    if (board[r][c+1][1] && !can_build_1(r,c+1)) ret = false;
    if (board[r][c+1][2] && !can_build_2(r,c+1)) ret = false;
    if (c>0 && board[r][c-1][2] && !can_build_2(r,c-1)) ret = false;
    board[r][c][2] = true;
    return ret;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for(int i=0;i<build_frame.size();i++) {
        int r = build_frame[i][1];
        int c = build_frame[i][0];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        if (b==1) {
            if (a==0 && can_build_1(r,c)) board[r][c][1] = true;
            if (a==1 && can_build_2(r,c)) board[r][c][2] = true;
        }
        else {
            if (a==0 && can_delete_1(r,c)) board[r][c][1] = false;
            if (a==1 && can_delete_2(r,c)) board[r][c][2] = false;
        }
    }
    vector<Node> arr;
    for(int r=0;r<=N;r++) for(int c=0;c<=N;c++) for(int i=1;i<3;i++) {
        if (board[r][c][i]) arr.push_back(Node(c,r,i-1));
    }
    sort(arr.begin(), arr.end());
    for(Node node : arr) {
        vector<int> ans;
        ans.push_back(node.x);
        ans.push_back(node.y);
        ans.push_back(node.a);
        answer.push_back(ans);
    }
    return answer;
}
