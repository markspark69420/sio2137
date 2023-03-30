#include<iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il;
    int t;
    double plus;
    cin >> il >> t >> plus;
    double sum = 0;
    double len;
    double vel;
    for(int i = 0; i < il; i++){
        cin >> len >> vel;
        sum += len/(plus+vel);
        if(sum>t){
            break;
        }
    }
    if(sum>t){
        cout<< "NIE";
    }
    else{
        cout<< "TAK";
    }
}