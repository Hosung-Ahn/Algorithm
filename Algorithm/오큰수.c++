# include <iostream> 
# include <vector>
# include <string.h>
using namespace std;

# define MAX 1000000

int arr[MAX];
int asw[MAX];
int N; 
vector<int> stack;

void pop(int idx) {
    while (!stack.empty() && arr[stack.back()] < arr[idx]) {
        asw[stack.back()] = arr[idx];
        stack.pop_back();
    }
} 

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    memset(asw, -1, sizeof(int)*MAX);

    for (int i = 0; i < N; i++) {
        pop(i);
        stack.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        cout << asw[i] << " ";
    }
}