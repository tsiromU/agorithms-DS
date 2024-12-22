#include <bits/stdc++.h>   

using namespace std;   

class Union{
    int* size;
    int* parent;
    int components;

public:
    Union(int n){
        size = new int[n+1];
        parent = new int[n+1];
        for(int i = 0; i < n; i++){
            size[i] = 1;
            parent[i] = i;
        }
        components = n;
    }

    int find (int x){
        if(parent[x] == x)
            return x;
        return find(parent[x]);
    }

    void join(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a == b){
            return;
        }
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[x] += size[y];
        components--;
    }
    int getComponents(){
        return components;
    }
};

int main() {   
   
    ifstream fin("input.txt");  
    ofstream fout("output.txt");  
    
    int n, q;
    fin >> n >> q;
    Union solultion(n);
    int a, b;
    while(q--){
        fin >> a >> b;
        solultion.join(a, b);
        fout << solultion.getComponents() << endl;
    }
}   
