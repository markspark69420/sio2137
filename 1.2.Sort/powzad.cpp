#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int a;
    cin >> a;
    int tab[a];
    for(int i=0; i<a; i++){
        cin >> tab[i];
    }
    sort(tab,tab+a);
    int cur = 0;
    int count = 0;
    bool found = true;
    for(int i=0; i<a; i++){
        if(tab[i]==cur){
            count++;
        } else if(cur!=count){
            found = false;
            break;
        } else{
            cur=tab[i];
            count=1;
        }
        if(cur<count){
            found = false;
            break;
        }
    }
    cout<<(found?"TAK":"NIE");

}