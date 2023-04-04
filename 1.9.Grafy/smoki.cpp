#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, t;
    cin >> m >> n >> t;
    int dist[m+2][n+2];
    char temp[n];
    if(t>=(m+n-2)){
        for(int i=0; i<m; i++){
            cin >> temp;
            for(unsigned int j=0; j<n; j++){
                if(temp[j]=='x'){
                    cout << n*m << '\n';
                    for(int x=1; x<m+1; x++){
                        for(int d=1; d<n+1; d++){
                            cout << x << ' ' << d << '\n';
                        }
                    }
                    return 0;
                }
            }
        }
    }
    //fill( &dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(dist[0][0]) , -1);
    queue<int> q;

    for(int i=1; i<m+1; i++){
        cin >> temp;
        for(int j=1; j<n+1; j++){
            if(temp[j-1]=='x'){
                dist[i][j] = 0;
            }else{
                dist[i][j] = -1;
            }
        }
    }
    for(int i =1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            cout << ((dist[i][j]!=-1)?'x':'.');
        }
        cout << '\n';
    }
}