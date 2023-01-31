//本题并未成功AC，并且因为这题我有想法，所以不是很想借鉴各论坛的解法
//注释皆为我查找错误的测试代码，是错误的，不用看 
//思路如下 ： 
/*
定义数据结构：底数 幂 的数组a 
一旦输入幂为0或回车即结束
QiuDao：底=底*幂，幂=幂-1（幂不为0） 为零就直接为0，求导后为0不输出
妈的，为什么不对啊，草 
 
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
