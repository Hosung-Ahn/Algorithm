#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 987654321; 
int ans = INF;

int solution(int n, vector<int> weak, vector<int> dist) {
    int W = weak.size();
    for(int i=0;i<W;i++) {
        weak.push_back(weak[i]+n);
    }
    sort(dist.begin(), dist.end());

    do {
        for (int i=0;i<W;i++) {
            int start = weak[i];
            int end = weak[i+W-1];

            for(int j=0;j<dist.size();j++) {
                start += dist[j];
                if (start >= end) {
                    ans = min(ans, j+1);
                    break;
                }
                start = *upper_bound(weak.begin(), weak.end(), start);
            }
        }
    }while(next_permutation(dist.begin(), dist.end()));

    return ans == INF ? -1 : ans;
}