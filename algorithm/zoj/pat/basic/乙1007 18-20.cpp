//���Ⲣδ�ɹ�AC��������Ϊ���������뷨�����Բ��Ǻ���������̳�Ľⷨ
//ע�ͽ�Ϊ�Ҳ��Ҵ���Ĳ��Դ��룬�Ǵ���ģ����ÿ� 
//˼·���� ��
/*
��1��ʼ��n����������a�У����ú���SuShu��ѡ���е�������������b
����SuShu����ΪJudgeSuShu������Ϊ������һ�飬���������ľͲ�������
����ʱ�䳬ʱ�� 
*/ 

#include<iostream>
using namespace std;
int JudgeSuShu(int t){
    
    for(int i=2;i<t;i++){
        if(t%i==0) return 0;
    }
    return 1;//�˴����и�����뷨��һ���������2��3��5��7ȡ�඼��Ϊ0 
             //����һ���Ǹ�������û��֤��������������ֻ��һ�������Ǵ����
             //ͬʱҲû�ҵ��ܷ����������� 
			  

  
}
int k=0;
void SuShu(int a[],int b[],int n){
    //b[0]=a[0];
    for(int i=1;i<n;i++){
        int t=a[i];
        if(JudgeSuShu(t)){
            b[k++]=t;
            //cout<<b[k-1]<<endl;
        }
        else{
            continue;
        }
    }
}

/*
int SuShuDui(int b[],int c[],int k){
    int i=0;
    //cout<<"cnm";
    if(i<k-1){
    c[i]=b[i+1]-b[i];
    i++;
}
    return i;
}
*/
int main(){
    int n;
    cin>>n;
    if(n>100000) exit(0);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    int b[n];
    SuShu(a,b,n);
    int c[k];
    
    int i=0;int kk=0;
    for( i=0;i<k-1;i++) {
	 int t = b[i+1]-b[i];
     //cout<<t<<endl;
     c[kk++]=t;
}
/*
     for( i=0;i<kk;i++) {
	 
     cout<<c[i];
     
}
*/
    
    int count = 0;
    for(int i=0;i<kk;i++){
        
        if(c[i]==2) count++;
    }
    cout<<count;
    return 0;
}
