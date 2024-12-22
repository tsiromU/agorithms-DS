#include <bits/stdc++.h>   

using namespace std;   

int main() {   

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    if(!fin.is_open()) {
        cout << "inputFileError" << endl;
    }

    int m, n;
    fin >> n >> m;
    pair<int, int>* graph = new pair<int, int> [m];
    int* amountOfAdjasent =  new int[n+1];
    for(int i = 0; i <= n; i++){
        amountOfAdjasent[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        graph[i] = pair<int, int>(a, b);
        amountOfAdjasent[a]++;
        amountOfAdjasent[b]++;
    }

    int** listOfAdjasent = new int*[n];
    for(int i = 1; i <= n; i++){
        listOfAdjasent[i] = new int[amountOfAdjasent[i]+1];
        listOfAdjasent[i][0] = 0;
    }

    for(int i = 0; i < m; i++){
        listOfAdjasent[graph[i].first][0]++;
        listOfAdjasent[graph[i].first][listOfAdjasent[graph[i].first][0]] = graph[i].second;

        listOfAdjasent[graph[i].second][0]++;
        listOfAdjasent[graph[i].second][listOfAdjasent[graph[i].second][0]] = graph[i].first;
    };

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= listOfAdjasent[i][0]; j++){
            fout << listOfAdjasent[i][j] << ' ';
        }
        fout << endl;
    }  

}
