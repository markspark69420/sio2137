#include<iostream>
#include<map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<int, int> accounts;
    int il;
    cin >> il;

    int curr;
    int amount;
    for(int i=0; i<il; i++){
        cin >> curr >> amount;
        if(accounts[curr]+amount >= 0){
            accounts[curr]+=amount;
            cout<<accounts[curr]<<'\n';
        }
        else{
            cout<<"NIE\n";
        }
    }
}