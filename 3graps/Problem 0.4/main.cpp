#include <bits/stdc++.h>   

using namespace std;   

const int N = 101;
int A[N][N];
int B[N];

int main() {   

    for(int i = 0; i < N; i++){
        B[i] = 0;
    }
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    if(!fin.is_open()) {
        cout << "inputFileError" << endl;
    }
    int n;
    fin >> n;

    int a;

    for(int i = 1; i <=n; i++)
        for(int j = 1; j <= n; j++){
            fin >> a;
            if(a)
                B[j] = i;
        }

    for(int i = 1; i <= n; i++){
        fout << B[i] << " ";
    }
    fout << endl;
}
