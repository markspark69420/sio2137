#include<iostream>

using namespace std;

int main(){
    int c =0;
    cin >>c;
    int a = 0;
    cin >>a;
    int i;
    int b = 0;
    for (int j = c; j < a+1; j++){
        i = j;
        b=0;
        if (i%7==0) cout<<"plum\n";
        else{

            while (i>6){
                if (i%10==7){
                    cout << "plum\n";
                    b = 1;
                    break;
                }
                else i= i/10;
            }
            if (b==0) cout<<j<<"\n";
        }
    }
}