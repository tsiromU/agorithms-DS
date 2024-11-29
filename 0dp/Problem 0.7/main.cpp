#include <bits/stdc++.h>   

using namespace std;   

const int N = 700007;
int a[N];
int b[N];
int ans = 0;

void newElem(int k);

int main() {   

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n; 
    for(int i = 0; i < n; i++)
        fin >> b[i];
    
    for(int i = 0; i < n; i++)
        newElem(b[i]);
  
    fout << ans << endl;
}

void newElem(int k){
    int lh = 0, rh = ans;
    int d;
    while(lh < rh){
        d = (rh + lh)>>1;
        if(a[d] >= k)
            rh = d;
        else
            lh = d+1;           
    }

    a[lh] = k;
    if(lh == ans)
        ans++;
}