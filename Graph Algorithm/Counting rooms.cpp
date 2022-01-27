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

lli br[100000];
char ar[10001][10001];
lli vis[10001][1001];

int n,m;
bool isvalid(int x,int y)
{
   if(x<1 || x>n || y<1 || y>m)
      return false;
   if(vis[x][y]==1 || ar[x][y]=='#')
      return false;

   return true;

}
lli dx[]={-1,0,1,0};
lli dy[]={0,1,0,-1};

void dfs(int x,int y)
{
   vis[x][y]=1;

   for(int i=0;i<4;i++)
   {
      if(isvalid(x+dx[i],y+dy[i]))
      {
         dfs(x+dx[i],y+dy[i]);
      }
   }
}
int main() {
   init_code();


   cin>>n>>m;
   
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         cin>>ar[i][j];

   lli cnt=0;
   

   memset(vis,0,sizeof(vis));
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         {
            if(vis[i][j]==0 && ar[i][j]=='.')
            {
               dfs(i,j);
               cnt++;
            }
         } 

   cout<<cnt<<endl;
   return 0;
}