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
		v[i]=n;//v�����ǵڶ��������� 
		while(n!=1){
			if(n%2!=0)  n=3*n+1;
			n=n/2;
			if (arr[n] == 1) break;
            arr[n] = 1;
		}//CALLATZ�ĸ�������һ��һ��ѭ���ģ����������޸�
		//����������� 
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		 if (arr[v[i]] == 0) {//�ҳ����ظ���
            if (flag == 1) cout << " ";
            cout << v[i];
            flag = 1;//������ո�&���δ��ǵ�����
			         //��v�ķ�Χ֮�� 
	} 
}
	return 0;
}
