#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define ulli unsigned long long int
#define lli long long int 
#define ll long long 
#define dd double
#define endl "\n"
#define mod 1000000007
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define s second
 
#define inf INT_MAX
#define vi vector<int>
#define vlli vector<long long int>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define limit 1000000000000000000
 
 
using namespace std;
 
 
 
 
void init_code(){
 fast_io;
    #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
    #endif 
}
 
lli highest_dig(lli n)
{
   vector<lli>ans;
   while(n>0)
   {
      ans.push_back(n%10);
      n/=10;
   }
 
   sort(ans.begin(),ans.end(),greater<lli>());
 
   return ans[0];
}
 
 
int main() {
   init_code();
   
   lli n,q;
   cin>>n>>q;
   lli ar[n];
   rep(i,n)
   cin>>ar[i];

   vector<lli>br(n,0);

   br[0]=ar[0];
   for(int i=1;i<n;i++)
      br[i]=ar[i]^br[i-1];

   
   lli a,b;

   while(q--)
   {
      cin>>a>>b;
      a--;
      b--;
     
      if(a!=0)
      cout<<((br[n-1]^br[a-1])^(br[n-1]^br[b]))<<endl;
      else
      cout<<((br[n-1]^br[b])^br[n-1])<<endl;
   }

   return 0;
}