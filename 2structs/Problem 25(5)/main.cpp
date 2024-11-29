#include <bits/stdc++.h>   

using namespace std;   

int main() {   

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    if(!fin.is_open()) {
        cout << "inputFileError" << endl;
    }


    char currentSymbol;
    stack<char> brackets;
    int ans = 0;

    auto eof = ifstream::traits_type::eof();
    
    while(true){
        auto symbol = fin.peek();
            if (symbol == eof)
                break;

        fin.get(currentSymbol);

        switch (currentSymbol)
        {
        case '{': 
        case '[': 
        case '(': 
            brackets.push(currentSymbol);
            ans++;
            break;
        case '}': 
            if(brackets.empty() || brackets.top() != '{'){
                fout << "NO" << endl;
                fout << ans << endl;
                return 0; 
            }
            ans++;
            brackets.pop();
            break;
        case ']': 
            if(brackets.empty() || brackets.top() != '['){
                fout << "NO" << endl;
                fout << ans << endl;
                return 0; 
            }
            ans++;
            brackets.pop();
            break;
        case ')': 
            if(brackets.empty() || brackets.top() != '('){
                fout << "NO" << endl;
                fout << ans << endl;
                return 0; 
            }
            ans++;
            brackets.pop();
            break;
        
        default:
            // fout << "NO" << endl;
            // fout << ans+brackets.size();
            break;
        }
    }
    if(brackets.empty()){
        fout << "YES" << endl;
        return 0;
    }

    fout << "NO" << endl;
    fout << ans;
}
