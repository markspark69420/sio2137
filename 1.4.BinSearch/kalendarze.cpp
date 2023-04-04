#include<iostream>
#include<algorithm>

using namespace std;

int list1[1000001];
int list2[1000001];
int n,m;

int binsearch(int x, bool cal_ver){
    int iter = 0;
    int start, end, s;
    if(cal_ver==2){
        start = 1;
        end = 1000001;
        s = (end+start)/2;
        while(end-start > 1){
            iter++;
            if(iter>100){
                return 0;
            }
            if(list2[s]>x){
                end = s + 1;
            }
            else{
                start = s;
            }
            s = (end+start)/2;
        }
    }
    else{
        start = 1;
        end = 1000001;
        s = (end+start)/2;
        while(end-start > 1){
            iter++;
            if(iter>100){
                return 0;
            }
            if(list1[s]>x){
                end = s + 1;
            }
            else{
                start = s;
            }
            s = (end+start)/2;
        }
    }
    cout<<"iter "<<iter << '\n';
    return start;
}

int main(){
    fill_n(list1,1000001,1000000001);
    fill_n(list2,1000001,1000000001);
    list1[0] = 0;
    list2[0] = 0;
    cin >> n >> m;
    for(int i=1; i<n+1; i++){
        cin >> list1[i];
        list1[i] += list1[i-1]; 
    }
    for(int i=1; i<m+1; i++){
        cin >> list2[i];
        list2[i] += list2[i-1]; 
    }

    int q;
    cin >> q;
    char date_ver;
    int month;
    int day;
    int true_date;
    int temp;

    for(int i=0; i<q; i++){
        cin >> day >> month >> date_ver;
        if(date_ver=='A'){
            true_date = list1[month] + day;
            temp = binsearch(true_date, 2);
            //cout<<"temp " << temp << '\n';
            cout<< list2[temp] << '\n';
        }
        else{
            true_date = list2[month] + day;
            temp = binsearch(true_date, 1);
            //cout<<"temp " << temp << '\n';
            cout<< list1[temp] << '\n';
        }
    }
}