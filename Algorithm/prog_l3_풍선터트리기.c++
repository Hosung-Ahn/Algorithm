#include <string>
#include <vector>

using namespace std;
#define MAX 1000001

int solution(vector<int> a) {
    int left_min[MAX] = {0,};
    int right_min[MAX] = {0,};

    int minN = 9876543210;
    for (int i=0;i<a.size();i++) {
        left_min[i] = minN;
        minN = min(minN, a[i]);
    }
    minN = 9876543210;
    for (int i=a.size()-1;i>=0;i--) {
        right_min[i] = minN;
        minN = min(minN, a[i]);
    }

    int ans = 0;
    for (int i=0;i<a.size();i++) {
        int cnt = 0;
        if (left_min[i] > a[i]) cnt++;
        if (right_min[i] > a[i]) cnt++;

        if (cnt > 0) ans++; 
    }
    return ans;
}