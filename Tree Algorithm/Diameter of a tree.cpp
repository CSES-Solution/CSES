#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define ulli unsigned long long int
#define lli long long int 
#define ll long long 
#define dd double
#define pii pair<int,int>
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
 
 
 lli par[200001];
 
void init_code(){
 fast_io;
    #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
    #endif 
}

int vis[200005], dist[200005];

void dfs(int node,vector<int>adj[])
{
    vis[node]=1;

    for(auto item:adj[node])
    {
        if(!vis[item])
        {
            dist[item]=1+dist[node];
            dfs(item,adj);
        }
    }
}

lli findpar(lli elem,lli level)
{
    if(level==0 || elem==-1)
        return elem;

   
    level--;
    elem=par[elem];

    return findpar(elem,level);
}

int main() {
   init_code();
   lli n;
   cin>>n;
   vector<int>adj[n+1];
   lli a,b;
   rep(i,n-1)
   {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
   }

rep(i,n+2)
   dist[i]=0;
    rep(i,n+2)vis[i]=0;

      dist[1]=0;
   dfs(1,adj);

   lli num=0,maxi=0;

   rep(i,n+1)
   {
        if(dist[i]>maxi)
        {
            maxi=dist[i];
            num=i;
        }
   }
   rep(i,n+2)
   dist[i]=0;
    rep(i,n+2)vis[i]=0;
   dfs(num,adj);
  
   maxi=0;
   rep(i,n+1)
   {
        if(dist[i]>maxi)
        {
            maxi=dist[i];
            
        }
   }

   cout<<maxi<<endl;

 return 0;
}