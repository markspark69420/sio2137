#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a;
    int lim;
    cin>>a>>lim;
    bool tab[a];
    for(int i=0;i<a;i++){
        cin >> tab[i];
    }

    int min = 1000001;
    int curr = 0;
    int end = 0;
    
    for(int start=0;start<a;start++){
        
        if(curr == lim && end-start<min){
            //cout<<"found "<<end-start-lim;
            min = end-start;
        }
        
        while(curr<lim && end<a){
            curr+=tab[end];
            end++;
            //cout<<"curr: "<<curr<<" end: "<<end<<" start: "<<start<<"  "<<end-start-lim<<'\n';
        }
        
        if(curr == lim && end-start<min){
            //cout<<"found "<<end-start-lim;
            min = end-start;
        }
        
        if(end == a){
            while(tab[start]==0){
                start++;
            }
            if(curr == lim && end-start<min){
                //cout<<"found "<<end-start-lim;
                min = end-start;
            }
        }
        
        curr-=tab[start];
    }
    if(min!=1000001){    
        cout<<min-lim;
    }
    else{
        cout<<"NIE";
    }
}