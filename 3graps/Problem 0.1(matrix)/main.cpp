#include <bits/stdc++.h>   

using namespace std;   

const int N = 101;
int A[N][N];

int main() {   

    for(int i = 0; i < N; i++){
        for(int j =0; j < N; j++)
            A[i][j] = 0;
    }
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    if(!fin.is_open()) {
        cout << "inputFileError" << endl;
    }
    int n, m;
    fin >> n >> m;
    int a, b;
    while(m--)  {
        fin >> a >> b;
        A[a][b] = A[b][a] = 1;
    }
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++)
            fout << A[i][j] << " ";
        fout << endl;
    }

}
