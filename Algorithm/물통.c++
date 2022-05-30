#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
# define MAX 201

bool visited[MAX][MAX][MAX] = {0,};
int water[3] = {0,};
int max_water[3];
vector<int> ret;

void pour(int i, int j, int x){
    water[i] -= x;
    water[j] += x;
}

int pouring_water(int i, int j) {
    int X = max_water[j] - water[j];
    return min(X, water[i]);
}

void dfs() {
    if (visited[water[0]][water[1]][water[2]]) return;
    visited[water[0]][water[1]][water[2]] = true;
    if (water[0] == 0) {
        ret.push_back(water[2]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i==j) continue;
            int x = pouring_water(i,j);
            pour(i,j,x);
            dfs();
            pour(j,i,x);
        }
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> max_water[i];
    }
    water[2] = max_water[2];
    dfs();

    sort(ret.begin(), ret.end());

    for (int x : ret) {
        cout << x << " ";
    }
}