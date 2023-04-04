#include<iostream>
#include<algorithm>

using namespace std;

int tree[1000010];
int len;

int query(int start, int end){
    start = len + start - 1;
    end = len + end + 1;
    int res=0;
    while(start/2 != end/2){
        if(start%2==0){
            res ^= tree[start+1];
        }
        if(end%2==1){
            res ^= tree[end-1];
        }
        start/=2;
        end/=2;
    }
    return res;
}

void change(int indx, int x){
    indx += len;
    tree[indx] = x;
    indx/=2;
    while(indx>0){
        tree[indx] = tree[indx*2] ^ tree[indx*2+1];
        indx/=2;
    }
}

void find(int indx){
    if((indx*2+1)<=len){
        find(indx*2);
    }
    if((indx*2+1)<len){
        find(indx*2+1);
    }
    tree[indx] = tree[indx*2] ^ tree[indx*2 + 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int a,b;
    int q;
    cin >> len >> q;
    for(int i=0; i<len; i++){
        cin >> tree[len+i];
    }
    find(1);
    string t;
    int temp;
    for(int i=0; i<q; i++){
        cin >> t >> a >> b;
        if(t[0]=='c'){
            cout << query(a-1, b-1) << '\n';
        }else{
            temp = tree[len+a-1];
            change(a-1, tree[len+b-1]);
            change(b-1, temp);
        }
    }
}