#include<bits/stdc++.h>

using namespace std;

long long tree[2000000];
int len;

void add(int beg, int end, int val){
    beg += len-1;
    end += len+1;
    while(beg/2 != end/2){
        if(beg%2 == 0){
            tree[beg+1] += val;
        }
        if(end%2 == 1){
            tree[end-1] += val;
        }
        beg/=2;
        end/=2;
    }
}

long long read(int indx){
    indx += len;
    long long res = 0;
    while(indx > 0){
        res += tree[indx];
        indx /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; 
    cin >> len >> q;
    char op;
    int a, b, curr;
    for(int i=0; i<q; i++){
        cin >> op;
        if(op == '+'){
            cin >> a >> b >> curr;
            add(a, b, curr);
        }
        else{
            cin >> curr;
            cout << read(curr) << '\n';
        }
    }
}