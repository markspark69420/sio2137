#include<bits/stdc++.h>

using namespace std;

int len;
int mod2[200010],mod3[200010],mod4[200010],mod5[200010], baskets[100000];

void add(int indx, int x){
    baskets[indx] += x;
    baskets[indx] %= 60;
    int v = indx + len;
    mod2[v] = baskets[indx]%2==0;
    mod3[v] = baskets[indx]%3==0;
    mod4[v] = baskets[indx]%4==0;
    mod5[v] = baskets[indx]%5==0;
    v/=2;
    while(v>0){
        mod2[v] = mod2[2*v] + mod2[2*v+1];
        mod3[v] = mod3[2*v] + mod3[2*v+1];
        mod4[v] = mod4[2*v] + mod4[2*v+1];
        mod5[v] = mod5[2*v] + mod5[2*v+1];
        v/=2;
    }
}

int query(int start, int end, int mod){
    int res=0;
    start += len-1;
    end += len+1;
    switch (mod)
    {
    case 1:
        return end-start-1;
    case 2:
        if(start==end){
            return mod2[len+start];
        }
        while(start/2 != end/2){
            if(start%2==0){
                res+= mod2[start+1];
            }
            if(end%2==1){
                res+= mod2[end-1];
            }
            start/=2;
            end/=2;
        }
        return res;
    case 3:
        if(start==end){
            return mod3[len+start];
        }
        while(start/2 != end/2){
            if(start%2==0){
                res+= mod3[start+1];
            }
            if(end%2==1){
                res+= mod3[end-1];
            }
            start/=2;
            end/=2;
        }
        return res;
    case 4:
        if(start==end){
            return mod4[len+start];
        }
        while(start/2 != end/2){
            if(start%2==0){
                res+= mod4[start+1];
            }
            if(end%2==1){
                res+= mod4[end-1];
            }
            start/=2;
            end/=2;
        }
        return res;
    case 5:
        if(start==end){
            return mod5[len+start];
        }
        while(start/2 != end/2){
            if(start%2==0){
                res+= mod5[start+1];
            }
            if(end%2==1){
                res+= mod5[end-1];
            }
            start/=2;
            end/=2;
        }
        return res;
    }
}

void find(int indx){
    if((indx*2)<len){
        find(indx*2);
    }
    if((indx*2+1)<len){
        find(indx*2+1);
    }
    mod2[indx] = mod2[indx*2] + mod2[indx*2 + 1];
    mod3[indx] = mod3[indx*2] + mod3[indx*2 + 1];
    mod4[indx] = mod4[indx*2] + mod4[indx*2 + 1];
    mod5[indx] = mod5[indx*2] + mod5[indx*2 + 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int q;
    int register temp, a, b, c;
    string str;
    cin >> len >> q;
    fill_n(mod2+len, len+1, 1);
    fill_n(mod3+len, len+1, 1);
    fill_n(mod4+len, len+1, 1);
    fill_n(mod5+len, len+1, 1);
    find(1);

    for(int i=0; i<q; i++){
        cin >> str;
        if(str[0]=='S'){
            cin >> a >> b >> c;
            //cout << "S," << a << ',' << b << ',' << c << '.';
            cout << query(a-1, b-1, c) << '\n';
        }
        else{
            cin >> a >> b;
            //cout << "A," << a << ',' << b << '.';
            add(a-1, b); 
        }
    }
}