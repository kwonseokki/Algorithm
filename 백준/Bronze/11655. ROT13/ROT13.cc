#include<bits/stdc++.h>
using namespace std;
string s;

void rot13(char c){
     if(c >= 65 && c <= 90){
            if(c + 13 > 90){
                c = 65 + c - 91;
            }
        }
        else if(c >= 97 && c <= 122){
            if(c + 13 > 122){
                c = 97 + c - 123;
            }
        }
        else {
            cout << c;
            return;
        }
        cout << (char) (c + 13);
}

int main(){
    getline(cin, s);
    for(char c : s) rot13(c);
    cout << "\n";
    return 0;
}