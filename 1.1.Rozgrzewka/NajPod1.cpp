#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    int len = 0;
    int cur = 0;
    for (unsigned int i = 0; i<s.length(); i++){
        if (s[i] == 'a'){
            cur++;

        } 
        else {
            if (len<cur) {
                len = cur;
            }
            cur = 0;
        }
    }
    if (len<cur) {
        len = cur;
    }
    for (int j = 0; j<len; j++){
        cout << 'a';
    }
    if (len == 0) cout<<"BRAK";
}