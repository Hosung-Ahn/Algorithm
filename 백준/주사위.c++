# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define INF 50
# define ll long long

int dice[6] = {0,};

int find_1() {
    int min_num = INF;
    for (int i = 0; i < 6; i++) {
        min_num = min(min_num, dice[i]);
    }
    return min_num;
}

int find_2() {
    int min_num = INF*2;
    for (int i = 0; i < 6; i++) {
        for (int j = i+1; j < 6; j++) {
            if ( (i == 0 && j == 5) 
                 || (i == 1 && j == 4)
                 || (i == 2 && j == 3))
                continue;
            
            min_num = min(min_num, dice[i] + dice[j]);
        }
    }
    return min_num;
}

int find_3() {
    vector<int> arr;
    arr.push_back(dice[0]+dice[1]+dice[3]);
    arr.push_back(dice[0]+dice[3]+dice[4]);
    arr.push_back(dice[0]+dice[4]+dice[2]);
    arr.push_back(dice[0]+dice[2]+dice[1]);
    arr.push_back(dice[5]+dice[1]+dice[3]);
    arr.push_back(dice[5]+dice[3]+dice[4]);
    arr.push_back(dice[5]+dice[4]+dice[2]);
    arr.push_back(dice[5]+dice[2]+dice[1]);

    return *min_element(arr.begin(), arr.end());
}

int main() {
    ll N; cin >> N;
    for (int i = 0; i < 6; i++)
        scanf("%d", &dice[i]);

    ll result = 0;
    if (N == 1) {
        int max_num = 0;
        for (int i = 0; i < 6; i++) {
            max_num = max(max_num, dice[i]);
            result += dice[i];
        }
        cout << result - max_num;
    }
    else {
        int num1 = find_1();
        int num2 = find_2();
        int num3 = find_3();

        result += num2 * 4;
        result += num3 * 4;
        result += num2 * ((N-2)*8);
        result += num1 * ((N-2)*(N-2) + (N-1)*(N-2)*4);

        cout << result;
    }
}