#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> U(3,vector<char>(3,'w'));
vector<vector<char>> D(3,vector<char>(3,'y'));
vector<vector<char>> F(3,vector<char>(3,'r'));
vector<vector<char>> B(3,vector<char>(3,'o'));
vector<vector<char>> L(3,vector<char>(3,'g'));
vector<vector<char>> R(3,vector<char>(3,'b'));
vector<char> arr;

void change(vector<vector<char>> &A) {
    vector<char> arr;
    int r = 0, c = 0;
    int ri = 0, ci = 1;
    do {
        arr.push_back(A[r][c]);
        cout << r << " " << c << endl;
        r += ri;
        c += ci;
        if (c > 2) {
            c -= 1;
            r += 1;
            ri = 1;
            ci = 0;
        }
        if (r > 2) {
            r -= 1;
            c -= 1;
            ri = 0;
            ci = -1; 
        }
        if (c < 0) {
            r -= 1;
            c += 1;
            ri = -1;
            ci = 0;
        }
    } while(r != 0 || c != 0);
}

int main() {
    change(B);
}
