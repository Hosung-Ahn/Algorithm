#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> U(3,vector<char>(3,'w'));
vector<vector<char>> D(3,vector<char>(3,'y'));
vector<vector<char>> F(3,vector<char>(3,'r'));
vector<vector<char>> B(3,vector<char>(3,'o'));
vector<vector<char>> L(3,vector<char>(3,'g'));
vector<vector<char>> R(3,vector<char>(3,'b'));

void clear() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            U[i][j] = 'w';
            D[i][j] = 'y';
            F[i][j] = 'r';
            B[i][j] = 'o';
            L[i][j] = 'g';
            R[i][j] = 'b';
        }
    }
}

void U_right() {
    char c1,c2,d0,d1,d2, tc1,tc2, td0,td1,td2;
    c1 = U[0][1]; c2 = U[0][2];
    d0 = B[0][0]; d1 = B[0][1]; d2 = B[0][2];

    U[0][2] = U[0][0];
    B[0][2] = L[0][0];
    
    U[0][1] = U[1][0];
    B[0][1] = L[0][1];

    U[0][0] = U[2][0];
    B[0][0] = L[0][2];

    // 바꿀값
    tc1 = U[1][2]; tc2 = U[2][2]; td0 = R[0][0]; td1 = R[0][1]; td2 = R[0][2];
    U[2][2] = c2; U[1][2] = c1;
    R[0][2] = d2; R[0][1] = d1; R[0][0] = d0;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc2 = U[2][0]; tc1 = U[2][1]; td0 = F[0][2]; td1 = F[0][1]; td2 = F[0][0];
    U[2][0] = c2; U[2][1] = c1;
    F[0][2] = d0; F[0][1] = d1; F[0][0] = d2;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc1 = U[1][0]; td0 = L[0][2]; td1 = L[0][1]; td2 = L[0][0];
    U[1][0] = c1;
    L[0][2] = d0; L[0][1] = d1; L[0][0] = d2;
}

void F_right() {
    char c1,c2,d0,d1,d2, tc1,tc2, td0,td1,td2;
    c1 = F[0][1]; c2 = F[0][2];
    d0 = U[2][0]; d1 = U[2][1]; d2 = U[2][2];

    F[0][2] = F[0][0];
    U[2][2] = L[0][2];
    
    F[0][1] = F[1][0];
    U[2][1] = L[1][2];

    F[0][0] = F[2][0];
    U[2][0] = L[2][2];

    // 바꿀값
    tc1 = F[1][2]; tc2 = F[2][2]; td0 = R[0][2]; td1 = R[1][2]; td2 = R[2][2];
    F[2][2] = c2; F[1][2] = c1;
    R[2][2] = d2; R[1][2] = d1; R[0][2] = d0;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc2 = F[2][0]; tc1 = F[2][1]; td0 = D[2][2]; td1 = D[2][1]; td2 = D[2][0];
    F[2][0] = c2; F[2][1] = c1;
    D[2][2] = d0; D[2][1] = d1; D[2][0] = d2;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc1 = F[1][0]; td0 = L[2][2]; td1 = L[1][2]; td2 = L[0][2];
    F[1][0] = c1;
    L[2][2] = d0; L[1][2] = d1; L[0][2] = d2;
}

void L_right() {
    char c1,c2,d0,d1,d2, tc1,tc2, td0,td1,td2;
    c1 = L[0][1]; c2 = L[0][2];
    d0 = U[0][0]; d1 = U[1][0]; d2 = U[2][0];

    L[0][2] = L[0][0];
    U[2][0] = B[0][0];
    
    L[0][1] = L[1][0];
    U[1][0] = B[1][0];

    L[0][0] = L[2][0];
    U[0][0] = B[2][0];

    // 바꿀값
    tc1 = L[1][2]; tc2 = L[2][2]; td0 = F[0][0]; td1 = F[1][0]; td2 = F[2][0];
    L[2][2] = c2; L[1][2] = c1;
    F[2][0] = d2; F[1][0] = d1; F[0][0] = d0;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc2 = L[2][0]; tc1 = L[2][1]; td0 = D[2][0]; td1 = D[1][0]; td2 = D[0][0];
    L[2][0] = c2; L[2][1] = c1;
    D[2][0] = d0; D[1][0] = d1; D[0][0] = d2;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc1 = L[1][0]; td0 = B[2][0]; td1 = B[1][0]; td2 = B[0][0];
    L[1][0] = c1;
    B[2][0] = d0; B[1][0] = d1; B[0][0] = d2;
}

void B_left() {
    char c1,c2,d0,d1,d2, tc1,tc2, td0,td1,td2;
    c1 = B[0][1]; c2 = B[0][2];
    d0 = U[0][0]; d1 = U[0][1]; d2 = U[0][2];

    B[0][2] = B[0][0];
    U[0][2] = L[0][0];
    
    B[0][1] = B[1][0];
    U[0][1] = L[1][0];

    B[0][0] = B[2][0];
    U[0][0] = L[2][0];

    // 바꿀값
    tc1 = B[1][2]; tc2 = B[2][2]; td0 = R[0][0]; td1 = R[1][0]; td2 = R[2][0];
    B[2][2] = c2; B[1][2] = c1;
    R[2][0] = d2; R[1][0] = d1; R[0][0] = d0;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc2 = B[2][0]; tc1 = B[2][1]; td0 = D[0][2]; td1 = D[0][1]; td2 = D[0][0];
    B[2][0] = c2; B[2][1] = c1;
    D[0][2] = d0; D[0][1] = d1; D[0][0] = d2;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc1 = B[1][0]; td0 = L[2][0]; td1 = L[1][0]; td2 = L[0][0];
    B[1][0] = c1;
    L[2][0] = d0; L[1][0] = d1; L[0][0] = d2;
}

void R_left() {
    char c1,c2,d0,d1,d2, tc1,tc2, td0,td1,td2;
    c1 = R[0][1]; c2 = R[0][2];
    d0 = U[0][2]; d1 = U[1][2]; d2 = U[2][2];

    R[0][2] = R[0][0];
    U[0][2] = B[2][2];
    
    R[0][1] = R[1][0];
    U[1][2] = B[1][2];

    R[0][0] = R[2][0];
    U[2][2] = B[0][2];

    // 바꿀값
    tc1 = R[1][2]; tc2 = R[2][2]; td0 = F[0][2]; td1 = F[1][2]; td2 = F[2][2];
    R[2][2] = c2; R[1][2] = c1;
    F[2][2] = d2; F[1][2] = d1; F[0][2] = d0;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc2 = R[2][0]; tc1 = R[2][1]; td0 = D[2][2]; td1 = D[1][2]; td2 = D[0][2];
    R[2][0] = c2; R[2][1] = c1;
    D[2][2] = d0; D[1][2] = d1; D[0][2] = d2;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc1 = R[1][0]; td0 = B[2][2]; td1 = B[1][2]; td2 = B[0][2];
    R[1][0] = c1;
    B[2][2] = d0; B[1][2] = d1; B[0][2] = d2;
}

void D_left() {
    char c1,c2,d0,d1,d2, tc1,tc2, td0,td1,td2;
    c1 = D[0][1]; c2 = D[0][2];
    d0 = B[2][0]; d1 = B[2][1]; d2 = B[2][2];

    D[0][2] = D[0][0];
    B[2][0] = L[2][2];
    
    D[0][1] = D[1][0];
    B[2][1] = L[2][1];

    D[0][0] = D[2][0];
    B[2][2] = L[2][0];

    // 바꿀값
    tc1 = D[1][2]; tc2 = D[2][2]; td0 = R[2][0]; td1 = R[2][1]; td2 = R[2][2];
    D[2][2] = c2; D[1][2] = c1;
    R[2][2] = d2; R[2][1] = d1; R[2][0] = d0;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc2 = D[2][0]; tc1 = D[2][1]; td0 = F[2][2]; td1 = F[2][1]; td2 = F[2][0];
    D[2][0] = c2; D[2][1] = c1;
    F[2][2] = d0; F[2][1] = d1; F[2][0] = d2;
    c2 = tc2; c1 = tc1; d0 = td0; d1 = td1; d2 = td2;

    tc1 = D[1][0]; td0 = L[2][2]; td1 = L[2][1]; td2 = L[2][0];
    D[1][0] = c1;
    L[2][2] = d0; L[2][1] = d1; L[2][0] = d2;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            string op; cin >> op;
            switch (op[0]) {
                case 'L' :
                    if (op[1] == '+') L_right();
                    else {
                        for (int j = 0; j < 3; j++)
                            L_right();
                    }
                break;

                case 'R' :
                    if (op[1] == '-') R_left();
                    else {
                        for (int j = 0; j < 3; j++) 
                            R_left();
                    }
                break;

                case 'U' :
                    if (op[1] == '+') U_right();
                    else {
                        for (int j = 0; j < 3; j++)
                            U_right();
                    }
                break;

                case 'D' :
                    if (op[1] == '-') D_left();
                    else {
                        for (int j = 0; j < 3; j++)
                            D_left();
                    }
                break;

                case 'B' :
                    if (op[1] == '-') B_left();
                    else {
                        for (int j = 0; j < 3; j++) 
                            B_left();
                    }
                break;

                case 'F' :
                    if (op[1] == '+') F_right();
                    else {
                        for (int j = 0; j < 3; j++) 
                            F_right();
                    }
                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << U[i][j];
            }
            cout << endl;
        }
        clear();
    }
}