# include <iostream>
using namespace std;

# define MAX 21

int arr[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX] = {0,};

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;

    if (a > 20 || b > 20 || c > 20) return w(20,20,20);

    if (visited[a][b][c]) return arr[a][b][c];

    if (a < b && b < c) {
        arr[a][b][c] =  w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        visited[a][b][c] = true;
    }

    else {
        arr[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) 
                       + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        visited[a][b][c] = true;
    }

    return arr[a][b][c];
}

int main() {
    int a,b,c;

    while (1) {
        scanf("%d %d %d", &a,&b,&c);
        if (a == -1 && b == -1 && c == -1) break;

        printf("w(%d, %d, %d) = %d\n", a,b,c,w(a,b,c));
    }
}