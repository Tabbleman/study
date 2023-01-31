#include<iostream>
#include<string>
using namespace std;
class stu{
  public:
    string name;
    string sto;
    int grade;
};
stu findmax(stu s[],int n){
    stu max=s[0];
    for(int i=0;i<n;i++){
        if(max.grade<s[i].grade){
            max=s[i];
        }
    }
    return max;
}
stu findmin(stu s[],int n){
    stu min=s[0];
    for(int i=0;i<n;i++){
        if(min.grade>s[i].grade){
            min=s[i];
        }
    }
    return min;
}
int main(){
    int n;
    cin>>n;
    stu s[n];
    for(int i=0;i<n;i++){
        /*
        getline(cin,s[i].name);
        getline(cin,s[i].sto);
        getline(cin,s[i].grade);
        */
        cin>>s[i].name;
        cin>>s[i].sto;
        cin>>s[i].grade;
    }
    stu max=findmax(s,n);
    stu min=findmin(s,n);
    cout<<max.name<<" "<<max.sto<<endl;
    cout<<min.name<<" "<<min.sto<<endl;
    return 0;
}
