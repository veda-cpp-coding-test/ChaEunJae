// 백준 문제 : 이진 검색 트리

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void postorderTraversal() const {
        postorderRecursive(root);
    }


private:
    Node* root;

    // --- 재귀적 헬퍼 함수들 ---

    // 삽입
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    void postorderRecursive(Node* node) const {
        if(node != nullptr){
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << "\n";
        }
    }

    // 트리 전체 해제
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int input;
    BinarySearchTree bst;
    while(cin >> input){
        bst.insert(input);
    }

    bst.postorderTraversal();
}
