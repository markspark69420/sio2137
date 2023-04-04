#include<iostream>
#include<algorithm>

using namespace std;

int tree[2000010];
int len;

void change(int start, int end){
    start = len + start - 1;
    end = len + end + 1;
    while(start/2 != end/2){
        if(start%2==0){
            tree[start+1] ^= 1;
        }
        if(end%2==1){
            tree[end-1] ^= 1;
        }
        start/=2;
        end/=2;
    }
}

bool query(int indx){
    indx += len;
    bool res = tree[indx];
    indx/=2;
    while(indx>0){
        res ^= tree[indx];
        indx/=2;
    }
    return res;
}

/*void find(int indx){
    if((indx*2+1)<=len){
        find(indx*2);
    }
    if((indx*2+1)<len){
        find(indx*2+1);
    }
    tree[indx] = tree[indx*2] ^ tree[indx*2 + 1];
}*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int a,b;
    int q;
    cin >> len >> q;
    char temp;
    for(int i=len; i<len*2; i++){
        cin >> temp;
        tree[i] = temp=='o';
    }
    for(int i=0; i<q; i++){
        cin >> temp;
        if(temp=='Q'){
            cin >> a;
            cout << (query(a-1)? "ON\n":"OFF\n");
        }else{
            cin >> a >> b;
            change(a-1,b-1);
        }
    }
}