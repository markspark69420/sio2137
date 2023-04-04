#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    unsigned int liczby[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> liczby[i][j];
        }
    }

    long long suma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            suma += liczby[i][j];
        }
        cout<<suma<<' ';
        suma = 0;
    }
    cout<<'\n';
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            suma += liczby[j][i];
        }
        cout<<suma<<' ';
        suma = 0;
    }
}