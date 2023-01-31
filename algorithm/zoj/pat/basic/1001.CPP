#include<iostream>
using namespace std;
int count = 0;
void kan(int n){
    if(n==1) return;
    if(n%2==0){
        count++;
        kan(n/2);
        }
    else{
        count++;
        kan((3*n+1)/2);
        
    }
    }

int main(){
    int n;
    cin>>n;
    if(n>1000) exit(0);
    //static int count=0;
    kan(n);
    cout<<count;
}
