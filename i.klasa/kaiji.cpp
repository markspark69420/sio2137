#include<bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    int diff=0;
    cin >> a >> b;
    for(int i=0; i<a.length(); i+=2){
        if(a[i]=='8' && b[i]=='[')
            diff++;
        else if(a[i]=='8' && b[i]=='(')
            diff--;
        else if(a[i]=='[' && b[i]=='(')
            diff++;
        else if(a[i]=='(' && b[i]=='[')
            diff--;
        else if(a[i]=='(' && b[i]=='8')
            diff++;
        else if(a[i]=='[' && b[i]=='8')
            diff--;
    }
    if(diff == 0)
        cout << "REMIS\n";
    if(diff < 0)
        cout << "PRZEGRANA\n";
    if(diff > 0)
        cout << "WYGRANA\n";
}