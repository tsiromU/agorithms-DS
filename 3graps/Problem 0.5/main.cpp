#include <bits/stdc++.h>   

using namespace std;   

int Index = 1;
int** a;
int* marks;
list<int> listic;

void startBSF(int currPos, int n);

int main() {   

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int n;
    fin >> n;

    a = new int*[n+1];

    for(int i = 1; i <= n; i++){
        a[i] = new int[n+1];
        for(int j = 1; j <= n;j++)
            fin >> a[i][j];
    }

    marks = new int[n+1];
    for(int i = 1; i <=n; i++)
        marks[i] = 0;

    for(int i = 1; i <= n; i++){
        if(marks[i] == 0){
            marks[i] = Index++;
            startBSF(i, n);
        }
    }

    for(int i = 1; i <= n; i++)
        fout << marks[i] << endl;

}

void startBSF(int currPos, int n)
{

    
    for(int i = currPos+1; i <= n; i++)
        if(a[currPos][i] && marks[i] == 0){
            marks[i] = Index++;
            listic.push_back(i);
        }
        
    if(!listic.empty()){
        int d = listic.front();
        listic.pop_front();
        startBSF(d, n);
    }
}
