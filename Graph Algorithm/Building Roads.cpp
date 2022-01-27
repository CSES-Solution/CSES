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

lli n,m;
lli vis[100001];

void dfs(int node,vector<int>adj[])
{
   vis[node]=1;

   for(auto item:adj[node])
   {
      if(!vis[item])
         dfs(item,adj);
   }
}
int main() {
   init_code();


   cin>>n>>m;
   
   
   vector<int>adj[n+1];
   lli a,b;
   memset(vis,0,sizeof(vis));
   for(int i=0;i<m;i++)
   {
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
   }
   int cc=0;
   vector<int>v;
   for(int i=1;i<=n;i++)
   {
      if(!vis[i])
      {
         cc++;
         if(i!=1)
         v.pb(i);
         dfs(i,adj);
      }
   }

   cc--;
   cout<<cc<<endl;

   for(int i=0;i<v.size();i++)
      cout<<1<<" "<<v[i]<<endl;
  

   return 0;
}