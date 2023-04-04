#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

const int MAX = 1000001;

int tab[MAX];

void sito(){
    int indx;
    for(int i=2; i<MAX; i++){
        if(tab[i] == 0){
            tab[i] = i;
            indx = 2*i;
            while(indx<MAX){
                tab[indx] = i;
                indx += i;
            }
        }
    }
}

void factorize(int x){
    int temp[20];
    int i = 19; 
    while(x!=1){
        temp[i] = tab[x];
        x /= tab[x];
        i--;
    }
    for(int j=i+1; j<20; j++){
        cout<<temp[j]<<' ';
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z,x;
    cin>>z;
    sito();
    for(int i=0;i<z;i++){
        cin>>x;
        factorize(x);
    }
}