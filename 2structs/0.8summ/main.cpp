#include <bits/stdc++.h>   

using namespace std;   

long long* arr;
long long *arrSize;

void buildFenvicTree(long long n, long long* arr);
void add(long long number, long long value, long long n);
long long PrefixSumm(long long a);

int main() {   
   
    // ifstream fin("input.txt");  
    // ofstream fout("output.txt");  
    
    long long n;
    cin >> n;
    arr = new long long[n];
    arrSize = new long long[n];
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
        arrSize[i] = 1;
    }


    buildFenvicTree(n, arr);
    buildFenvicTree(n, arrSize);

    // for(long long i = 0; i < n; i++){
    //     cout << arr[i] << endl;
    // }

    // cout << PrefixSumm(5) << endl;
    // cout << PrefixSumm(16) << endl;
    // cout << PrefixSumm(15) << endl;
    // cout << PrefixSumm(19) << endl;
    // cout << PrefixSumm(0) << endl;
    // cout << PrefixSumm(1) << endl;
    long long q;
    cin >> q;
    long long a, b;
    while(q--){
        string s;
        cin >> s >> a >> b;
        if(s == "Add"){
            add(a, b, n);
        }
        if(s == "FindSum"){
            // cout << "summ" << b << " "<< a << endl;
            cout << PrefixSumm(b-1) -  PrefixSumm(a-1) << endl;
        }
    }
}   


void buildFenvicTree(long long n, long long* arr){
    long long m;
    long long a;
    for(long long i = 0; i < n; i++){
        a = 1;
        m = i;
        while(1&m){
            m /= 2;
            arr[i] += arr[i-a];
            a*=2;
        }
    }
    return ;
}


long long PrefixSumm(long long a){
    if(a == -1)
        return 0;
    long long ans = 0;
    while(a!=-1){
        ans += arr[a];
        a-= arrSize[a];
    }
    return ans;
}


void add(long long number, long long value, long long n)
{
    while (number < n){
       arr[number] += value;
       number = number | (number + 1);
    }
    return;
}
