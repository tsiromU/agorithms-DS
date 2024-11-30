#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* rch = nullptr;
    Node* lch = nullptr;
    bool isValid = true;

    Node(int a) : data(a){};


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
        if(isValid)
            out << data << endl;
        if(lch != nullptr)
            lch->leftPreOrderTraversal(out);
        if(rch != nullptr)
            rch->leftPreOrderTraversal(out);
    }

    Node* findMin(){
        return lch == nullptr ? this : lch->findMin();
    }

    Node* findNode(int d){
        if(d == data){
            return this;
        }
        if(d < data){
            if(lch == nullptr)
                throw 1;
            return lch->findNode(d);
        }
        if(rch == nullptr)
            throw 1;
        return rch->findNode(d);
    }

    
    int deleteNodeRight(Node* a){
        int ans = a->data;
        if(a->rch == nullptr && a->lch == nullptr){
            a->isValid = false;
            return ans;
        }
        if(a->lch == nullptr){
            a->data = a->rch->data;
            a->lch  = a->rch->lch;
            a->rch  = a->rch->rch;
            return ans;
        }
        if(a->rch == nullptr){
            a->data = a->lch->data;
            a->rch  = a->lch->rch;
            a->lch  = a->lch->lch;
            return ans;
        }
        a->data =  this->deleteNodeRight(a->rch->findMin());

        return ans;
    }
};


int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int a, d;
    fin >> d;
    fin >> a;
    Node binTree(a);
    while(!fin.eof()){
        fin >> a;
        binTree.addNode(a);
    }
    Node* node;
    try 
    {
        node = binTree.findNode(d);
    } catch(int err){
        binTree.leftPreOrderTraversal(fout);
        return 0;
    };
    binTree.deleteNodeRight(node);
    binTree.leftPreOrderTraversal(fout);
}

