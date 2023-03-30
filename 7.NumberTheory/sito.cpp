#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

void sito(long long n){
    bool tab[n+1];
    long long indx;
    fill(tab,tab+n,1);
    for(int i=2;i<n;i++){
        if(tab[i]){
            cout<<i<<'\n';
            indx=i;
            while(indx<n){
                tab[indx]=0;
                indx+=i;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    long long a;
    cin >> a;
    long long x = a/log(a/2);
    sito(x);
}