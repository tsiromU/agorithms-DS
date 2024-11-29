#include <bits/stdc++.h>   
#define ull unsigned long long

using namespace std;   

const int BITSET_SIZE = 500;
int Mtr[4][32][32];
bool ActuralMatrics    = 0;// поидее лучше int
bool ActuralAnsMatrics = 0;// поидее лучше int
int c[5];
int M;

constexpr void createIdentityMatrix(int a);
void squareMatrix();
void multipMatrix();
int main() {   
    createIdentityMatrix(2);
    createIdentityMatrix(3);

    ifstream fin("input.txt");  
    ofstream fout("output.txt");  

    int m;
    string s;
    fin >> s >> m;

    if(s == "1"){
        cout << (1 << m);
        return 0;
    }
    M = 1 << m;
    int a, b, d;
    // считаем матрицу оператора шага рекурсии
    for (int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            d =1;
            for (int k = 0; k < m; k++){
                a = i&d;
                b = j&d;
                if(a != b){
                    c[k] = -1;
                }
                else c[k] = (bool)a;
                d *=2;
            }
            int ans = 1;
            for(int l = 1; l <  m; l++){
                if(c[l] == c[l-1]){
                    if(c[l] != -1)
                        ans = 0;
                }
            }
            Mtr[0][i][j] = ans;
        }
    }
    //s = s-1;
    int i = s.size() - 1;
    while (true) {
        if (s[i] > '0') {  
            s[i]--;        
            break;
        } else {                
            s[i] = '9';   
            i--;
        }
    }
    // раскладываем s в двоичную запись, находим длину в 2 записи
    bitset<BITSET_SIZE> bits;
    int pos = 0;
    while (!s.empty() && pos < BITSET_SIZE) {
        unsigned long long remainder = 0;
        string nextTemp;
        // s/=2, remainder = s%2;
        for (char digit : s) {
            remainder = remainder * 10 + (digit - '0');
            if (!nextTemp.empty() || remainder / 2 > 0) {
                nextTemp += (remainder / 2) + '0';
            }
            remainder %= 2;
        }

        bits[pos++] = remainder;
        s.swap(nextTemp);
    }
    // считает n=ную степень матрицы
    int currPos = 0;
    while(currPos < pos){
        if(bits[currPos])
            multipMatrix();
        squareMatrix();
        currPos++;
    }

    //сумма всех элементов матрицы
    int ans = 0; 
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            ans += Mtr[2+ActuralAnsMatrics][i][j];
            ans %= 10000;
        }
    } 
    fout << ans << endl;
}   

void squareMatrix(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            int summ = 0;
            for(int l = 0; l < M; l++){
                summ += Mtr[ActuralMatrics][i][l]*Mtr[ActuralMatrics][l][j];
                summ %= 10000;
        }
        Mtr[1-ActuralMatrics][i][j] =  summ;
        }             
    }
    ActuralMatrics = 1-ActuralMatrics;
};
void multipMatrix(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            int summ = 0;
            for(int l = 0; l < M; l++){
                summ += Mtr[ActuralMatrics][i][l]*Mtr[2+ActuralAnsMatrics][l][j];
                summ %= 10000;
            }
                
        Mtr[3-ActuralAnsMatrics][i][j] =  summ;
        }             
    }
    ActuralAnsMatrics = 1-ActuralAnsMatrics;
}


constexpr void createIdentityMatrix(int a){
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            if(i == j){
                Mtr[a][i][j] = 1;
            } else {
                Mtr[a][i][j] = 0;
            }

        }
    }
};
