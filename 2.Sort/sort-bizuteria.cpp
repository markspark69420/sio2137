#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool compare(string a, string b){
    if (a.length() != b.length()){
        return a.length() < b.length();
    }
    else{
        for(unsigned int i=0; i<a.length(); i++){
            if(a[i] != b[i]){
                return a[i] < b[i];
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int il;
    cin >> il;
    string str[il];
    for(int i=0; i<il; i++){
        cin >> str[i];
    }
    sort(str,str+il,compare);

    for(int i=0; i<il; i++){
        cout<<str[i]<<'\n';
    }
}