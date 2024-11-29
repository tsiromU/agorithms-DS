#include <bits/stdc++.h>   

using namespace std;   

const int N = 3*100002;
int a[N];


int main() {   
   
    // ifstream fin("input");  
    // ofstream fout("output");  
    
    int n, rh, lh;
    cin >> n; 
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int t;
    cin >> t;
    while(t--){
        int k, d;
        cin >> k;
        lh = 0; 
        rh = n;
        while(lh < rh){
            d = (rh + lh)/2;
            if(a[d] >= k){
                rh = d;
            } else
                lh = d+1;           
        }
        if(t == n)
            cout << 0 << " " << t << " ";
        else     
            cout << 1 << " " << t << " ";
        lh = 0;
        rh = n;
        while(rh > lh){
            d = (lh + rh)/2;
            if( k < a[d])
                rh = d;
            else 
                lh = d+1;
        }
        cout << lh << endl;
    }      

}   



// def UpperBound(a, x):
// l = 0, r = len(a)
// while l < r:
// k = (l + r) // 2
// if x < a[k]:
// r = k
// else: # x >= a[k]
// l = k + 1
// return l