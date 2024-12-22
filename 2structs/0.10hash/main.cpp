#include <bits/stdc++.h>   

using namespace std;   

int main() {   
   
    ifstream fin("input.txt");  
    ofstream fout("output.txt");  
    
    int m, c, n;
    fin >> m >> c >> n;
    int* hash = new int[m];
    for(int i = 0; i < m; i++){
        hash[i] = -1;
    }
    int a;
    while(n--){
        fin >> a;
        int b = a;
        while(true){
            a %= m;
            if(hash[a] == -1){
                hash[a] = b;
                break;
            }
            if(hash[a] == b)
                break;
            a+=c;
        }
    }
    for(int i = 0; i < m; i++){
        cout << hash[i] << endl;
    }
}   

