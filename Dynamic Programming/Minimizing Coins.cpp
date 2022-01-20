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
 
 
 
 
int main() {
   init_code();
   
   lli n,m;
   cin>>n>>m;
   lli ar[n];
   rep(i,n)
   cin>>ar[i];

   sort(ar,ar+n);

   lli dp[m+1];
   for(int i=0;i<=m;i++)
      dp[i]=INT_MAX;
   dp[0]=0;

   for(int i=1;i<=m;i++)
   {
      for(int j=0;j<n;j++)
      {
         if(i-ar[j]>=0)
            dp[i]=min(dp[i-ar[j]]+1,dp[i]);
      }
   }

   // for(int i=0;i<=m;i++)
   //    cout<<dp[i]<<" ";

   // cout<<endl;
   if(dp[m]==INT_MAX)
      cout<<-1<<endl;
   else
   cout<<dp[m]<<endl;
   return 0;
}