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

void postorder(Node* root){
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
     std::cout<<root->value<<" ";
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

   
    std::cout << "Postorder Traversal: ";
    postorder(root);
    std::cout << std::endl;

    return 0;
}