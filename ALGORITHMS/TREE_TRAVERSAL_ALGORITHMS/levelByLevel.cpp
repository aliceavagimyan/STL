#include <iostream>
#include <queue>

class Node{
    public:
    int value;
    Node* right;
    Node* left;

    Node(int value){
        this->value=value;
        left=right=nullptr;
    }
};

void levelByLevel(Node* root) {
    if (root == nullptr) return;

    std::queue<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        Node* current = nodes.front();
        nodes.pop();
        std::cout << current->value << " ";

        if (current->left != nullptr) nodes.push(current->left);
        if (current->right != nullptr) nodes.push(current->right);
    }
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    std::cout << "Level By level Traversal: ";
    levelByLevel(root);
    std::cout << std::endl;

    return 0;
}