//本题并未成功AC，并且因为这题我有想法，所以不是很想借鉴各论坛的解法
//注释皆为我查找错误的测试代码，是错误的，不用看 
//思路如下 ：
/*
由1开始至n输入至数组a中，套用函数SuShu挑选其中的素数放入数组b
函数SuShu核心为JudgeSuShu，内容为：都除一遍，有能整除的就不是素数
所以时间超时了 
*/ 

#include<iostream>
using namespace std;
int JudgeSuShu(int t){
    
    for(int i=2;i<t;i++){
        if(t%i==0) return 0;
    }
    return 1;//此处还有个别的想法，一个数如果对2，3，5，7取余都不为0 
             //那他一定是个素数，没有证明，但运行起来只有一个例子是错误的
             //同时也没找到能反驳↑的数字 
			  

  
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
