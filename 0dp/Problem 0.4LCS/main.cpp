#include <bits/stdc++.h>

using namespace std;

int* A;
int* B;
int* ansA;
int* ansB;
int* ansWorld;
int curr;

int** ans;


int recCalc(int a, int b);
void recRebuild(int a, int b);

int main(){

    int n;
    cin >> n;
    curr = n;

    A = new int[n+1];
    B = new int[n+1];
    for(int i = 1; i <= n; i++)
        cin >> A[i];

    for(int i = 1; i <= n; i++)
        cin >> B[i];


    ans = new int*[n+1];
    for(int i= 0; i <=n; i++){
        ans[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            ans[i][j] = (i*j)==0 ? 0 : -1;
        }
    }

    
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) 
            ans[i][j] = recCalc(i, j);

    int ansLen = ans[n][n];
    if(!ansLen){
        cout << 0;
        return;
    }
    ansWorld = new int[ansLen];
    ansA = new int[ansLen];
    ansB = new int[ansLen];
    cout << ansLen << endl;

    curr = ansLen;
    recRebuild(n, n);

    for(int i = 0; i < ansLen; i++){
        cout << ansA[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < ansLen; i++){
        cout << ansB[i] << " ";
    }




    cout << endl;
}



int recCalc(int a, int b){
    // cout << a << b << endl;
    if(ans[a][b] != -1)
        return ans[a][b];
    if(A[a] == B[b]){
        return ans[a][b] = 1+ ans[a-1][b-1];
    }
    
    return ans[a][b] = max(ans[a][b-1], ans[a-1][b]);
}



void recRebuild(int a, int b){
    int x = ans[a][b];
    int y = ans[a-1][b];
    int z = ans[a][b-1];
    if(x == y)
        return recRebuild(a-1, b);
    if(x == z)
        return recRebuild(a, b-1);
    
    // cout << curr << endl;
    ansWorld[--curr] = A[a];
    ansA [curr] = a-1;
    ansB [curr] = b-1;
    if(curr)
        return recRebuild(a-1, b-1);
}
