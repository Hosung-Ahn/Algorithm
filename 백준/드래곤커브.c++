# include <iostream>
# include <vector>
using namespace std;

bool board[101][101] = {0,};

void find_cur(vector<int> &arr, int g) {
    for (int i = 0; i < g; i++) {
        for (int j = arr.size()-1; j >= 0; j--) {
            arr.push_back((arr[j]+1)%4);
        }
    }
}

void next_point(int &x, int &y, int d) {
    switch(d) {
        case 0 :
            x+=1;
        break;
        case 1 : 
            y-=1;
        break;
        case 2 :
            x-=1;
        break;
        case 3 : 
            y+=1;
        break;
    }
}

void dot(int x, int y, const vector<int> &arr) {
    board[x][y] = true;
    for (int d : arr) {
        next_point(x,y,d);
        board[x][y] = true;
    }
}

bool is_square(int x, int y) {
    if (!board[x][y] || !board[x][y+1] || !board[x+1][y] || !board[x+1][y+1]) return false;
    return true;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x,y,d,g; cin >> x >> y >> d >> g;
        vector<int> arr;
        arr.push_back(d);
        find_cur(arr,g);
        dot(x,y,arr);
    }

    int result = 0;
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (is_square(x,y)) result++;
        }
    }

    cout << result;
}