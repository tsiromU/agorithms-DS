#include <bits/stdc++.h>
using namespace std;

// Структура узла бинарного дерева
struct Node {
    int data;              // Значение узла
    Node* left;            // Указатель на левое поддерево
    Node* right;           // Указатель на правое поддерево

    // Конструктор узла
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева
class BinaryTree {
public:
    Node* root;            // Корень дерева

    BinaryTree() : root(nullptr) {}

    Node* findFatherOfCentralChild(int amontOfChildren){

    }

    Node* find(int value){
        return findRec(root, value);
    }
    
    void insert(int value) {
        if(find(value) == nullptr)
            root = insertRec(root, value);
    }

    void remove(int value) {
        root = removeRec(root, value);
    }

    void calcLeaves(int& ans){
        ans = 0;
        calcLeavesRec(root, ans);
    }

    void preOrderTraversal() {
        preOrderTraversalRec(root);
        cout << endl;
    }


private:

    Node* findRec(Node* node, int value){
        if(node == nullptr)
            return nullptr;
        Node *currNode = node;
        if(currNode->data == value)
            return currNode;
        if(currNode->data > value){
            if(currNode->left != nullptr)
                return findRec(node->left, value);
        }
        if(currNode->data < value){
            if(currNode->right != nullptr)
                return findRec(node->right, value);
        }
        return nullptr;
    }

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    Node* removeRec(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = removeRec(node->left, value);
        } else if (value > node->data) {
            node->right = removeRec(node->right, value);
        } else {
            // Узел с одним или без поддеревьев
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Узел с двумя поддеревьями: получаем минимальное значение в правом поддереве
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeRec(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void calcLeavesRec(Node* node, int& ans){
        bool a = true;
        if(node->right != nullptr){
            a = false;
            calcLeavesRec(node->right, ans);
        }
        if(node->left != nullptr){
            a = false;
            calcLeavesRec(node->left, ans);
        }
        if(a)
            ans++;
    }

    void preOrderTraversalRec(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderTraversalRec(node->left);
        preOrderTraversalRec(node->right);
    }

};

int main() {
    BinaryTree tree;

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    

    int a;
    while(!fin.eof()){
        fin >> a;
        tree.insert(a);
    }   

    tree.calcLeaves(a);
    
    if(a%2){
        
    }
    tree.preOrderTraversal();

    return 0;
}
