# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    vector<int> arr;
    for (int i = 1; i <= 4; i++)
        arr.push_back(i);

    
    vector<int>::iterator iter1, iter2;
    iter1 = lower_bound(arr.begin(), arr.end(), 3);
    iter2 = arr.begin();

    cout << iter1 - iter2;

}