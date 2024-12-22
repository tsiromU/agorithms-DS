#include <bits/stdc++.h>   

using namespace std;   

int Index = 1;
int** a;
int* marks;
stack<int> myStack;

void startDSF(int currPos, int n);

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
            myStack.push(i);
            while (!myStack.empty())
            {
                int d = myStack.top();
                bool isAdded = 0;
                while(++a[d][0] <= n){
                    if(a[d][a[d][0]] == 1 && marks[a[d][0]] == 0){
                        marks[a[d][0]] = Index++;
                        myStack.push(i);
                        isAdded = 1;
                        break;
                    }
                    cout << a[d][a[d][0]] << " " << a[d][0] << " " << endl;
                }
                if(!isAdded)
                    myStack.pop();
            }
            
        }
    }



    for(int i = 1; i <= n; i++)
        fout << marks[i] << endl;

}



void startDSF(int currPos, int n){

};