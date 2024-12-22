#include <bits/stdc++.h>   
#define ll long long
using namespace std;   

int main() {   
   
    ifstream fin("huffman.in");  
    ofstream fout("huffman.out");  
    
    int n; 
    fin >> n; 
    ll* a = new ll[n+1];
    ll* b = new ll[n];
    for(int i = 0; i < n; i++){
        fin >> a[i];
        b[i] = 922337203685477580;
    }
    a[n] = b[0];

    int x = 0;
    int y = 0;
    ll ans = 0;
    ll d, e, f;
    for(int i = 0; i < n-1; i++){
        d = a[x] + a[x+1];
        e = a[x] + b[y];
        f = b[y] + b[y+1];

        if(d <= e && d<= f){
            b[i] = d;
            ans+=b[i];
            x ++;
            x ++;
            continue;
        }
        if(e<=f && e<=d){
            b[i] = e;
            ans+=b[i];
            x++;
            y++;
            continue;
        }
            b[i] = f;
            ans+=b[i];
            y++;
            y++;
    }
    fout << ans << endl;
}