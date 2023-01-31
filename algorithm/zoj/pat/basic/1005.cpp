#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[100];
bool cmp(int a,int b){return a>b;}
int main(){
	int k,n;
	int flag=0;
	cin>>k; 
	vector<int> v(k);
	for(int i=0;i<k;i++){
		cin>>n;
		v[i]=n;//v数组是第二个输入行 
		while(n!=1){
			if(n%2!=0)  n=3*n+1;
			n=n/2;
			if (arr[n] == 1) break;
            arr[n] = 1;
		}//CALLATZ的覆盖数是一组一组循环的，并不是无限个
		//将覆盖数标记 
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		 if (arr[v[i]] == 0) {//找出不重复数
            if (flag == 1) cout << " ";
            cout << v[i];
            flag = 1;//不输出空格&输出未标记的数字
			         //在v的范围之内 
	} 
}
	return 0;
}
