//他妈的就加起来计算，为什么差一分啊 
#include<iostream>
using namespace std;
int main(){
    char s[100];
    for(int i=0;i<100;i++){
    	s[i]='c';
	}//initial
    cin.getline(s,100);
       int n=0;
    {
      	for(int i=0;i<100;i++){
      		if(s[i]!='c') n++;
      		else{
      			break;
			  }
		  }
	
	}//to find the uninitial limit
	
	
    int x = 0;
    for(int i=0;i<n-1;i++){
        x+=(s[i]-'0');
       // cout<<x<<endl;
    }
       //cout<<"final:"<<endl;
       //cout<<x;
    //test and get the sum "x"
       int bai=x/100;
       int shi=(x-bai*100)/10;
       int ge=x-bai*100-shi*10;
    if(bai!=0){
    	switch(bai){
    		case 1:{cout<<"yi";break;}
    		case 2:{cout<<"er";break;}
    		case 3:{cout<<"san";break;}
    		case 4:{cout<<"si";break;}
    		case 5:{cout<<"wu";break;}
    		case 6:{cout<<"liu";break;}
    		case 7:{cout<<"qi";break;}
    		case 8:{cout<<"ba";break;}
    		case 9:{cout<<"jiu";break;}
		}
		cout<<" ";
	}
	if(shi!=0){
		switch(shi){
    		case 1:{cout<<"yi";break;}
    		case 2:{cout<<"er";break;}
    		case 3:{cout<<"san";break;}
    		case 4:{cout<<"si";break;}
    		case 5:{cout<<"wu";break;}
    		case 6:{cout<<"liu";break;}
    		case 7:{cout<<"qi";break;}
    		case 8:{cout<<"ba";break;}
    		case 9:{cout<<"jiu";break;}
		}
		cout<<" ";
	}
	if(ge!=0){
		switch(ge){
    		case 1:{cout<<"yi";break;}
    		case 2:{cout<<"er";break;}
    		case 3:{cout<<"san";break;}
    		case 4:{cout<<"si";break;}
    		case 5:{cout<<"wu";break;}
    		case 6:{cout<<"liu";break;}
    		case 7:{cout<<"qi";break;}
    		case 8:{cout<<"ba";break;}
    		case 9:{cout<<"jiu";break;}
		}
		//cout<<" ";
	}
    cout<<endl;
    return 0;
}
