#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int a;
    int l;
    cin >> a >> l;
    int tab[a];
    for(int i = 0; i < a; i++){
        cin>>tab[i];
    }
    long long pre[a+1];
    pre[0]=0;
    for(int i = 1; i < (a+1); i++) {
        pre[i] =pre[i-1]+tab[i-1];
    }
    long long mini= 100000000001;
    for (int i =l;i<(a+1);i++){
        if((pre[i]-pre[i-l])<mini) mini=pre[i]-pre[i-l];
    }
    cout<<mini;
}