#include <iostream>
using namespace std;

int main() {
	// your code goes here!!
	
	int n;
	cin>>n;
	
	int a=0;
	int b=0;
	
	int diff1=0;
	int diff2=0;
	
	while(n--){
	    
	    int p1;
	    int p2;
	    
	    cin>>p1>>p2;
	    
	    a = a+p1;
	    b= b+p2;
	    
	    if(a>b){
	        diff1 = max(diff1 , a-b);
	    }else{
	        diff2 = max(diff2 , b-a);
	    }
	    
	  }
	  
	   if(diff1>diff2){
	        cout<<"1 ";
	    }else{
	        cout<<"2 ";
	    }
	    
	cout<<max(diff1 , diff2)<<endl;
	return 0;
}
