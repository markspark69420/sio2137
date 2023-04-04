#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int nwd(int x, int y){
    while(x!=0){
        swap(x, y);
        
        x%=y;
    }
    return max(x, y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int iter;
    cin >> iter;
    int a,b;
    for(int i = 0; i < iter;i++){
        cin >> a >> b;
        cout<<a/nwd(a,b)<<'\n';
    }
}