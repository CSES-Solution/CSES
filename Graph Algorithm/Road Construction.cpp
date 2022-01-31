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
lli ra[200001];
vector<int>str[200001];

int flag=0;
vector<int>ans;
void dfs(int node,vector<int>adj[],lli s,lli& maxm)
{
   vis[node]=1;

   s++;
   maxm=max(maxm,s);
   

   for(auto item:adj[node])
   {
      if(!vis[item]){
         dfs(item,adj,s,maxm);
      }
   }

  
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

lli find(lli a)
{
   if(par[a]==-1)return a;

   else return par[a]=find(par[a]);
}
lli merge(lli a,lli b)
{
   a=find(a);
   b=find(b);

   if(ra[a]>ra[b])
      swap(a,b);

   ra[a]+=ra[b];
   par[b]=a;

   return ra[a];
}
int main() {
   init_code();


   cin>>n>>m;
   
   lli a,b;
   vector<int>adj[n+1];
   lli cc=n,mx=0;
   // memset(par,-1,sizeof(par));
  
   rep(i,n+1)ra[i]=1;
   rep(i,n+1)par[i]=-1;
   while(m--)
   {
      cin>>a>>b;
     

      if(find(a)!=find(b))
      {
         mx=max(mx,merge(a,b));
         cc--;
      }

      cout<<cc<<" "<<mx<<endl;
   }
   return 0;
}