#include <iostream>
using namespace std;

struct Node {
    int x;
    Node(int x) : x(x) { }

    Node& operator++(int) {
        x++;
        return *this;
    }
};

int main() {
    Node node(2);
    Node node2 = node++;
    
    cout << node.x << endl;
    cout << node2.x << endl;

    node.x = 5;

    cout << node.x << endl;
    cout << node2.x << endl;
}