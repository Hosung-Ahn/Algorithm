# include <iostream>
using namespace std;

# define MAX 501
int board[MAX][MAX] = {0,};
int horizontal[MAX][MAX] = {0,};
int vertical[MAX][MAX] = {0,};
int N,M;

int result = 0;

void type1() {
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= M-3 ; j++) {
            int cur = horizontal[i][j+3] - horizontal[i][j-1];
            if (cur > result) {
                result = cur;
            }
        }
    }
}

void type2() {
    for (int i = 1; i <= N-3; i++) {
        for (int j = 1; j <= M; j++) {
            int cur = vertical[i+3][j] - vertical[i-1][j];
            if (cur > result) {
                result = cur;
            }
        }
    }
}

void type3() {
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-1; j++) {
            int cur = horizontal[i][j+1] - horizontal[i][j-1] 
                    + horizontal[i+1][j+1] - horizontal[i+1][j-1];
            if (cur > result) {
                result = cur;
            }
        }
    }
}


int sub4(int i, int j) {
    return board[i][j] + board[i][j+1];
}
int sub5(int i, int j) {
    return board[i][j+1] + board[i][j+2];
}
int sub6(int i, int j) {
    return board[i][j] + board[i][j+2];
}
int sub7(int i, int j) {
    return board[i+1][j] + board[i+1][j+2];
}
int sub8(int i, int j) {
    return board[i][j+2] + board[i+1][j];
}
int sub9(int i, int j) {
    return board[i][j] + board[i+1][j+2];
}
int sub10(int i, int j) {
    return board[i+1][j] + board[i+1][j+1];
}
int sub11(int i, int j) {
    return board[i+1][j+1] + board[i+1][j+2];
}
int (*sub4_to_11[])(int, int) = {sub4, sub5, sub6, sub7, sub8, sub9, sub10 ,sub11};


int sub12(int i, int j) {
    return board[i][j+1] + board[i+1][j+1];
}
int sub13(int i, int j) {
    return board[i+1][j] + board[i+2][j];
}
int sub14(int i, int j) {
    return board[i][j+1] + board[i+2][j+1];
}
int sub15(int i, int j) {
    return board[i][j] + board[i+2][j];
}
int sub16(int i, int j) {
    return board[i][j+1] + board[i+2][j];
}
int sub17(int i, int j) {
    return board[i+1][j+1] + board[i+2][j+1];
}
int sub18(int i, int j) {
    return board[i][j] + board[i+1][j];
}
int sub19(int i, int j) {
    return board[i][j] + board[i+2][j+1];
}

int (*sub12_to_19[])(int, int) = {sub12, sub13, sub14, sub15, sub16
                                  , sub17, sub18, sub19};

void type4_to_11() {
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            int sum6 = horizontal[i][j+2] - horizontal[i][j-1]
                     + horizontal[i+1][j+2] - horizontal[i+1][j-1];

            for (int k = 0; k < 8; k++) {
                int cur = sum6 - sub4_to_11[k](i,j);
                if (cur > result) {
                result = cur;
                }
            }
        }
    }
}

void type12_to_19() {
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            int sum6 = vertical[i+2][j] - vertical[i-1][j]
                     + vertical[i+2][j+1] - vertical[i-1][j+1];
            for (int k = 0; k < 8; k++) {
                int cur = sum6 - sub12_to_19[k](i,j);
                if (cur > result)
                    result = cur;
            }
        }
    }
}


int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        int sum_horizontal = 0;
        for (int j = 1; j <= M; j++) { 
            sum_horizontal += board[i][j];
            horizontal[i][j] = sum_horizontal;
        }
    }

    for (int j = 1; j <= M; j++) {
        int sum_vertical = 0;
        for (int i = 1; i <= N; i++) {
            sum_vertical += board[i][j];
            vertical[i][j] = sum_vertical;
        }
    }   

    type1();
    type2();
    type3();
    type4_to_11();
    type12_to_19();

    cout << result;
}