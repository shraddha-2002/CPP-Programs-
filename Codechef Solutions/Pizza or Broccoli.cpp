#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define all(x) x.begin(),x.end()
#define trav(x) for(auto &i:x)
#define f first
#define s second
#define endl '\n'
#define int long long int
#define ld long double
#define ii pair<int,int>
#define vi vector<int>
#define vp vector<ii>
#define loop(i,a,b) for(int i=a;i<b;i++)
#ifndef ONLINE_JUDGE
#define debarr(a,n) cerr<<#a<<"[ "; loop(i,0,n) cerr<<a[i]<<" "; cerr<<"]\n";
#define debug(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const vector<pair<S,T>>&p){os<<"[";for(auto&it:p)os<<"("<<it.f<<","<<it.s<<")";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#else
#define debug(...){}
#define debarr(a,n){}
#endif
#define gcd(a,b) __gcd(a,b)
const int mod=1000000007;
const int inf=1e18;
/********** code from here *******************/
int n,k;
string s;
void solve(int tc){
   cin>>n>>k;
   cin>>s;
   vi pref(n);
   vi suff(n);
   int lst=-1;
   for(int i=0;i<n;i++){
     pref[i]=lst;
     if(s[i]=='0') {
      lst=i;
     } 
   }
   lst=n;
   for(int i=n-1;i>=0;i--){
     suff[i]=lst;
     if(s[i]=='0') lst=i;
   }
   int ans=0;
   for(int i=0;i<n;i++){
       if(i>=k-1){
         ans=max(ans,k+(i-k+1-pref[i-k+1]-1)+(suff[i]-i-1));
       }
   }
   cout<<ans<<endl;
}
/**********code ends here ********************/
signed main( ){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
//freopen("inputf.in", "r", stdin);
//freopen("outputf.in", "w", stdout);
freopen("error.txt", "w", stderr);
#endif
int t=1;
cin>>t;
for(int i=1;i<=t;i++){
  solve(i);
}
return 0;
}
