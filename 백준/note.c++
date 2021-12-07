# include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data) : data(data) {
        left = nullptr;
        right = nullptr;
    }
};

int main() { 
    Node* node(0);
    Node* left = new Node(3);

    node->left = left;

    cout << node->left->data << endl;
}