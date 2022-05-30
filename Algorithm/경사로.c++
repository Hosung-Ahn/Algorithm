# include <iostream>
# include <vector>
using namespace std;
# define MAX 100
int N,L;
int Data[MAX][MAX] = {0,};

vector<vector<pair<int,int>>> rows(MAX, vector<pair<int,int>>()),
                              columns(MAX, vector<pair<int,int>>());

int result = 0; 
void count_result(vector<vector<pair<int,int>>> &line) {
    for (int i = 0; i < N; i++) {
        bool is_line = true;

        for (int j = 1; j < line[i].size(); j++) {
            int diff = line[i][j-1].first - line[i][j].first;

            if (diff == 1) {
                if (line[i][j].second < L) {
                    is_line = false; 
                    break;
                }
                line[i][j].second -= L;
            }
            else if (diff == -1) {
                if (line[i][j-1].second < L) {
                    is_line = false; 
                    break;
                }
                line[i][j-1].second -= L;
            }
            else {
                is_line = false; 
                break;
            }
        }
        if (is_line) {
            // cout << i << endl;
            result++;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> L;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> Data[r][c];
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int cur = Data[r][c];
            int cnt = 1;
            while(c+1 < N && Data[r][c+1] == cur) {
                c++;
                cnt++;
            }
            rows[r].push_back({cur,cnt});
        }
    }

    for (int c = 0; c < N; c++) {
        for (int r = 0; r < N; r++) {
            int cur = Data[r][c];
            int cnt = 1;
            while (r+1 < N && Data[r+1][c] == cur) {
                r++;
                cnt++;
            }
            columns[c].push_back({cur,cnt});
        }
    }

    count_result(rows);
    count_result(columns);

    cout << result;

}