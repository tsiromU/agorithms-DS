#include <bits/stdc++.h>

using namespace std;

const int N = 300000;
int a[N];
int c[N];

int main() {
    c[2] = -200000;
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i]; 
    c[1] = a[1];
    c[3] = a[3] + a[1];
    c[4] = a[4] + a[1];
    c[5] = c[3] + a[5];
    if(n == 2){
        cout << -1;
        return 0;
    }
    if(n <= 5){
    cout << c[n] << endl;
    } else {
        for(int i = 6; i <= n; i++){
            c[i] = max(c[i-2],c[i-3])+a[i];
        }
        cout << c[n] << endl;
    }
    int d = n;
    vector<int> vec;
    vec.push_back(n);
    while(d-1){
        if(c[d]-c[d-2]==a[d]){
            d-=2;
            vec.push_back(d);
            continue;
        }if(c[d]-c[d-3]==a[d]){
            d-=3;
            vec.push_back(d);
        }
    }
    while(!vec.empty()){  
        cout << vec.back()<< " ";
        vec.pop_back();
    }
        return 0;
}