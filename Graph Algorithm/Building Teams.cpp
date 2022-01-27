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
lli vis[200001];
lli color[200001];
lli dist[200001];
lli par[200001];
vector<int>str[200001];

bool dfs(int node,vector<int>adj[])
{
   vis[node]=1;

   for(auto item:adj[node])
   {
      if(!vis[item]){
            color[item]=1-color[node];
            dfs(item,adj);
      }
        
      else
      {
         if(color[item]==color[node])return false;
      }
   }
   return true;
}

void bfs(int x,vector<int>adj[])
{
   queue<int>q;
   q.push(x);
   while(!q.empty())
   {
      int src=q.front();
      q.pop();


      for(auto item:adj[src])
      {
         if(dist[item]>dist[src]+1)
         {
            dist[item]=dist[src]+1;
            par[item]=src;
            q.push(item);
         }
      }
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

   for(int i=1;i<=n;i++)
      vis[i]=0;
   
   color[0]=1;
   int flag=0;
   for(int i=1;i<=n;i++)
   {
      
         if(!dfs(i,adj))
         {
            flag++;
         }
      
   }

   if(flag>0)
   {
      cout<<"IMPOSSIBLE"<<endl;
   }
   else
   {
      for(int i=1;i<=n;i++)
         cout<<color[i]+1<<" ";

      cout<<endl;
   }

   

   return 0;
}