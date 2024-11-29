#include <bits/stdc++.h>

using namespace std;


int n;
string s;
int ans[7003][7003];

void calc(int a, int b);
string recreatePolinom(int a, int b);

int main() { 


    ofstream fout("output.txt"); 
    ifstream fin("input.txt");
    fin >> s;
    n = s.length();

    for(int i = 0; i < n; i++)
        for(int  j = 0; j+i < n; j++){
            calc(j, j+i);
            //recreatePolinom(j, j+i);
            }
    fout << ans[0][n-1] << endl;
    fout << recreatePolinom(0, n-1) << endl;
}

void calc(int a, int b){
    if(a == b){
        ans[a][a] = 1;
        return;
    }
    if(b-a ==1){
        if(s[a] == s[b]){
            ans[a][b] = 2;
        } else {
            ans[a][b] = 1;
        }
        return;
    }
    if(s[a] == s[b]){
        ans[a][b] = ans[a+1][b-1] + 2;
        return;
    }
    if(ans[a+1][b] > ans[a][b-1]){
        ans[a][b] = ans[a+1][b];
    } else
        ans[a][b] = ans[a][b-1];
    
}

string recreatePolinom(int a, int b){
    int len = ans[a][b];
    string result(len, ' ');
    int currPos = 0;
    while(true){
        if(s[a] == s[b] && ans[a][b] == 2){
            result[currPos] = s[a];
            result[len - currPos - 1] = s[a];
            return result;
        }
        if(a == b){
            result[currPos] = s[a] ;
            return result;
        }
        if(a == b-1){
            result[currPos] = s[a];
            result[len - currPos - 1] = s[a];
            return result;
        }
    
        if(ans[a][b] == ans[a+1][b]){
            a++;
            continue;
        }
        if(ans[a][b] == ans[a+1][b-1]){
            a++;
            b--;
            continue;
        }
        if(ans[a][b] == ans[a][b-1]){
            b--;
            continue;
        }
        if(ans[a][b] == ans[a+1][b-1] + 2){
            result[currPos++]  = s[a];
            result[len - currPos]  = s[a]; //за что я так с читабельностью?
            a++;
            b--;
            continue;
        }
        
        cout << a << " " << b << " " << "kaput" << endl;
        break;
    }
    return result;
};