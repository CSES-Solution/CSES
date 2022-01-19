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



void dfs(int node,vector<int> adj[],vector<int>&dp,vector<int>& vis)
{
   vis[node]=1;

   for(auto elem:adj[node])
   {
      if(!vis[elem])
      {
         dfs(elem,adj,dp,vis);
         dp[node]+=dp[elem]+1;
      }
      else
         dp[node]+=dp[elem]+1;
   }
}
int main() {
   init_code();
   
   lli n;
   cin>>n;
   vector<int>dp(n+1,0);

   vector<int> adj[n+1];

   lli x;
   for(int i=2;i<=n;i++)
   {
      cin>>x;
      adj[x].pb(i);
   }
   vector<int>vis(n+1,0);
   for(int i=1;i<=n;i++)
   {
      if(!vis[i])
         dfs(i,adj,dp,vis);
   }


   for(int i=1;i<=n;i++)
      cout<<dp[i]<<" ";

   cout<<endl;

   return 0;
}