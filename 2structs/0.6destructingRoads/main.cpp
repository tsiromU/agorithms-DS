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

    void showArr(int n){
        for(int i = 0; i < n; i ++){
            cout << parent[i];
        }
        cout << endl;
    }
};

int main() {   
   
    ifstream fin("input.txt");  
    ofstream fout("output.txt");  
    int n, m, q;
    fin >> n >> m >> q;
    Union solution(n);
    int a, b;
    int* x = new int[m];
    int* y = new int[m];
    int* z = new int[m]; 
    int* k = new int[q]; 
    for(int  i = 0; i < m; i++){
        fin >> x[i] >> y[i];
        z[i] = 1;
    }

    for(int i = 0; i < q; i++){
        fin >> k[i];
        k[i]--;
        z[k[i]] = 0;
    }
    for(int  i = 0; i < m; i++){
        if(z[i]){
            solution.join(x[i], y[i]);
        }
    }
    int d = q-1;
    for(int i = 0; i < q; i++){
        if(solution.getComponents() == 1){
            d = q-i;
            break;
            }
        solution.join(x[k[q-1-i]], y[k[q-1-i]]);
    }
    for(int i = 0; i < d; i++){
        fout << 1; 
    }
    for(int i = d; i < q; i++)
        fout << 0; 
    fout << endl;
}