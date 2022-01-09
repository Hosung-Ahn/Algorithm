# include <iostream>
# include <vector>
using namespace std;

# define MAX 101

int board[MAX][MAX] = {0,};
vector<pair<int,int>> move_lst;
vector<pair<int,char>> turn;
int N;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void move_1s(int &direction, int &r, int &c){
    direction %= 4;
    if (direction < 0) direction += 4;
    r += dr[direction];
    c += dc[direction];
}

bool is_eat_myself(int r,int c, int length) {
    int last_idx = move_lst.size() - length;
    for (int i = last_idx; i < move_lst.size(); i++) {
        if (move_lst[i].first == r && move_lst[i].second == c)
            return true;
    }
    return false;
}

bool is_game_over(int r,int c, int length) {
    if (r < 1 || r > N || c < 1 || c > N) return true;
    if (length > 1 && is_eat_myself(r,c,length)) return true; 
    return false;
}

int main() {
    cin >> N;
    
    int K,L;
    
    cin >> K;
    int r,c;
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &r, &c);
        board[r][c] = 1;
    }

    cin >> L;
    int t;
    char d;
    for (int i = 0; i < L; i++) {
        scanf("%d %c", &t, &d);
        turn.push_back(make_pair(t,d));
    }

    int direction = 1, time = 0, length = 1;
    r = 1; c = 1;

    int idx = 0; 

    while(1) {
        time++;
        move_1s(direction, r,c);
        // printf("r = %d, c = %d, dir = %d, time = %d, len = %d\n", r,c,direction,time,length);
        if (is_game_over(r,c,length)) {
            cout << time;
            break;
        }
        move_lst.push_back(make_pair(r,c));

        if (board[r][c] == 1) {
            length++;
            board[r][c] = 0;
        }

        if (idx < turn.size() && turn[idx].first == time) {
            if (turn[idx].second == 'D') direction++;
            else direction--;
            idx++;
        }
    }
}