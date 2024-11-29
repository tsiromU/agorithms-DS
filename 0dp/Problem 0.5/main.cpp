#include <bits/stdc++.h>

using namespace std;


int n;
int a[1000];
int b[1000];
int ans[1003][1003];

void calc(int i, int j);

int main() { 

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    ans[0][0] = 0;
    for(int i = 1; i < n; i++){
        ans[i][0] = ans[0][i] = 0;
        for(int j = 1; j < n; j++ )
            ans[i][j] = -1;
    }
    calc(n, n);
    cout << ans[n][n] << endl;
}

void calc(int i, int j){
    if(a[i] == b[j]){
        if(ans[i-1][j-1] == -1)
            calc(i-1, j-1);
        ans[i][j] = ans[i-1][j-1] + 1;
        return;
    }
    if(ans[i-1][j] == -1)
        calc(i-1, j);
    if(ans[i][j-1] == -1)
        calc(i, j-1);
    ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
}

// string recreatePolinom(int a, int b){
//     int len = ans[a][b];
//     string result(len, ' ');
//     int currPos = 0;
//     while(true){
//         if(s[a] == s[b] && ans[a][b] == 2){
//             result[currPos] = s[a];
//             result[len - currPos - 1] = s[a];
//             return result;
//         }
//         if(a == b){
//             result[currPos] = s[a] ;
//             return result;
//         }
//         if(a == b-1){
//             result[currPos] = s[a];
//             result[len - currPos - 1] = s[a];
//             return result;
//         }
    
//         if(ans[a][b] == ans[a+1][b]){
//             a++;
//             continue;
//         }
//         if(ans[a][b] == ans[a+1][b-1]){
//             a++;
//             b--;
//             continue;
//         }
//         if(ans[a][b] == ans[a][b-1]){
//             b--;
//             continue;
//         }
//         if(ans[a][b] == ans[a+1][b-1] + 2){
//             result[currPos++]  = s[a];
//             result[len - currPos]  = s[a]; //за что я так с читабельностью?
//             a++;
//             b--;
//             continue;
//         }
        
//         cout << a << " " << b << " " << "kaput" << endl;
//         break;
//     }
//     return result;
// };