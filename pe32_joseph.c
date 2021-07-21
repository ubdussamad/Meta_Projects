#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPEAT(i,a,n) for(int i=a;i<n;i++)
#define EACH(it,v) for(typeof(v.begin()) it = v.begin();it!=v.end();++it)
using namespace std;
int main()
{
 int n=2000,ans=0;
 set<int>st;
 REP(i,n)
  REPEAT(j,i,n)
  {
   string s;
   ostringstream oss;
   oss<<i<<j<<i*j;
   s=oss.str();
   sort(s.begin(),s.end());
   if(s=="123456789"){st.insert(i*j);cout<<i<<" x "<<j<<" = "<<i*j<<endl;}
  }
 EACH(it,st)ans+=*it;
 cout<<ans<<endl;
 system("pause");
 return 0;
}
