#include <bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node* rch = nullptr;
    Node* lch = nullptr;

    

    Node(int a) : data(a){};
    Node(Node* right, Node* left, int a):rch(right), lch(left), data(a){};


    void addNode(int a){
        if(a == data)
            return;
        if(a < data){
            if(lch == nullptr)
                lch = new Node(a);
            else
                lch->addNode(a);
            return;
        }
        if(a > data){
            if(rch == nullptr){
                rch = new Node(a);
            }
            else
                rch->addNode(a);
            return;
        }
    }

    void leftPreOrderTraversal(ostream& out){
        out << data << endl;
        if(lch != nullptr)
            lch->leftPreOrderTraversal(out);
        if(rch != nullptr)
            rch->leftPreOrderTraversal(out);
    }
    // ostream& operator << (ostream& out, Node& a){
    //     a.leftPreOrderTraversal(out);
    //     return out;
    // }
};


int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int a;
    fin >> a;
    Node binTree(a);
    while(!fin.eof()){
        fin >> a;
        binTree.addNode(a);
    }
    binTree.leftPreOrderTraversal(fout);
}

