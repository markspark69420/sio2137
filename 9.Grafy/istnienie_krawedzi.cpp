#include<iostream>

using namespace std;

bool tab[1001][1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    int w, k;
    cin >> w >> k;
    int i1, i2;

    for(int i=0; i<k; i++){
        cin >> i1 >> i2;
        tab[i1][i2] = true;
        tab[i2][i1] = true;
    }
    
    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        cin >> i1 >> i2;
        if(tab[i1][i2] == true){
            cout << "TAK\n";
        }
        else{
            cout << "NIE\n";
        }
    }
}