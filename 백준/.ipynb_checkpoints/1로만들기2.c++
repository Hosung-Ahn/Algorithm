# include <iostream>
# include <queue>
# include <vector>
using namespace std;

# define MAX 1000001

int N; 
int visited[MAX] ={0, };

int find_bfs() {
    queue<pair<int,int>> bfs;
    bfs.push(make_pair(1,0));
    
    while (!bfs.empty()) {
        int cur = bfs.front().first;
        int cur_cnt = bfs.front().second;
        bfs.pop();

        if (cur == N) return cur_cnt;

        if (cur + 1 <= N && visited[cur+1] == 0 ) {
            visited[cur+1] = cur_cnt + 1;
            bfs.push(make_pair(cur+1, cur_cnt + 1));
        }

        for (int i = 2; i <= 3; i++) { 
            if (cur * i <= N && visited[cur * i] == 0 ) {
                visited[cur*i] = cur_cnt + 1;
                bfs.push(make_pair(cur*i, cur_cnt + 1));
            }
        }
    }

    return 0; 
}

void print_visited() {
    int cnt = visited[N];
    int num = N;

    while (cnt != 0) {
        cout << num << " ";
        if (visited[num-1] == cnt-1) {
            num--;
            cnt--;
        }
        else if (num % 2 == 0 && visited[num / 2] == cnt - 1) { 
            num /= 2;
            cnt--;
        }
        else if (num % 3 == 0 && visited[num / 3] == cnt - 1) {
            num /= 3;
            cnt--;
        }
    }
    cout << 1;
}

int main() {
    cin >> N;

    cout << find_bfs() << endl;

    print_visited();
    
}