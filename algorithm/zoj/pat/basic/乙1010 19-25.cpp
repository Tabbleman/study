//���Ⲣδ�ɹ�AC��������Ϊ���������뷨�����Բ��Ǻ���������̳�Ľⷨ
//ע�ͽ�Ϊ�Ҳ��Ҵ���Ĳ��Դ��룬�Ǵ���ģ����ÿ� 
//˼·���� �� 
/*
�������ݽṹ������ �� ������a 
һ��������Ϊ0��س�������
QiuDao����=��*�ݣ���=��-1���ݲ�Ϊ0�� Ϊ���ֱ��Ϊ0���󵼺�Ϊ0�����
��ģ�Ϊʲô���԰����� 
 
*/
#include<iostream>
using namespace std;
typedef struct polynomial{
    int coefficient;
    int exp;
}; 
void QiuDao(polynomial a[],polynomial b[],int n){
	for(int i=0;i<n;i++)
	{
	  
    b[i].coefficient=a[i].coefficient*a[i].exp;
    if(a[i].exp!=0){
        b[i].exp=a[i].exp-1;
     }
    else{
        b[i].exp=0;
     }
    }
}


int main(){
    polynomial a[1000];
    int temp=1;int i=0;
    while(temp){
        cin>>a[i].coefficient>>a[i].exp;
        if(a[i].exp==0) temp=0;
        i++;
        if(cin.get()=='\n') {
        	temp=0;
        	break;
		}; 
    }
    int n=i;
    polynomial b[n];
    QiuDao(a,b,n);
    for(int j=0;j<n-2;j++){
    	
        cout<<b[j].coefficient<<" "<<b[j].exp<<" ";
    }
    
     cout<<b[n-2].coefficient<<" "<<b[n-2].exp;
    
    if(b[n-1].coefficient){
        cout<<" ";
    cout<<b[n-1].coefficient<<" "<<b[n-1].exp;
   }
   //cout<<0;
    return 0;
}
