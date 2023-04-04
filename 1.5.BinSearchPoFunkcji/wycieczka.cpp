#include<iostream>
#include<algorithm>

using namespace std;

int tab[100002];
int dni;
int sh;
long long mean;

bool check(long long max){
    if(max>=mean){
        long long indx = 0;
        long long a = 0;
        for(int i=0;i<sh;i++){  
            a+=tab[i];
            if(a>max){
                indx++;
                a = tab[i];
            }
            
        }
        if(indx>=dni){
            return 0;
        } else{
            return 1;
        }
    }
    else return 0;
}

long long binsearch(long long start,long long end){
    long long s = (end+start)/2;
    //int iter = 0;
    while((end-start)>1){
        //iter++;
        if(check(s)) end=s;
        else start = s;
        s = (end+start)/2;
    }
    //cout<<"iter "<<iter<<'\n';
    return end;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> sh >> dni;
    long long sum = 0;
    sh--;
    for(int i=0;i<sh;i++){
        cin >> tab[i];
        sum += tab[i];
    }
    mean = sum / sh;
    cout << binsearch(1,1e18);
}