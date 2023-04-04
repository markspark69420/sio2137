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
    int res;
    int curr;
    cin>>res>>res;
    while(cin>>curr){
        res = nwd(res,curr);
    }
    cout<<res;

}