#include <bits/stdc++.h>   

using namespace std;   

const int N = 100002;
int A[N];

int main() {   

    for(int i = 0; i < N; i++)
        A[i] = 0;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    if(!fin.is_open()) {
        cout << "inputFileError" << endl;
    }
    int m, n;
    fin >> m;
    n = m;
    int a, b;
    while(m--)  {
        fin >> a >> b;
        A[b] = a;
    }
    for(int i = 1; i <=n; i++){
        fout << A[i] << " ";
    }

}
