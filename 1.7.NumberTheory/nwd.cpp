#include<algorithm>
#include<iostream>

using namespace std;

int num[1000000];

int nwd(int len, int min_){
    int min_after=min_;
    
    for(int i=0; i<len; i++){
        
        if((num[i]%min_) != 0){
            num[i]%=min_;
            min_after = min(min_after,num[i]);
        }
    }


    if(min_after==min_){
        ///cout<<"nie zmienia sie";
        return min_after;
    }

    else{
        /*cout<<"nieznalezione\n";
        for(int i=0; i<len; i++){
            cout<<num[i]<<"\n";
        }*/
        return nwd(len,min_after);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    fill(num,num+1000000,0);
    
    int a;
    int mini=1e+9 +1;
    int indx;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>num[i];
        if(mini>num[i]){
            mini=num[i];
            indx=i;
        }
    }

    cout<<nwd(a,mini);
}