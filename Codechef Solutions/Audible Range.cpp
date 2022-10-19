#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,x;
	cin>>t;
	while(t--)
	{
	    cin>>x;
	    if(x>=67&&x<=45000)
	    cout<<"YES"<<endl;
	    else
	    {
	        std::cout << "NO" << std::endl;
	    }
	}
	return 0;
}
