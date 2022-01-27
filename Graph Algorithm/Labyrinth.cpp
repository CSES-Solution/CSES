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

struct mydata{
   int a;
   int b;
   string s;
};
lli br[100000];
char ar[10001][10001];
lli vis[10001][1001];
lli dist[10001][10001];
char pr[1001][1001];
int n,m,srcx,srcy,endx,endy;
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
char d[]={'U','R','D','L'};

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
void bfs(int x,int y)
{
   queue<pair<int,int>>q;
   
   q.push({x,y});

   while(!q.empty())
   {
      int s1=q.front().first;
      int s2=q.front().second;
      

      q.pop();

      for(int i=0;i<4;i++)
      {
         int newx=s1+dx[i];
         int newy=s2+dy[i];
         if(isvalid(s1+dx[i],s2+dy[i]))
         {
            if(dist[newx][newy]>dist[s1][s2]+1)
            {
               dist[newx][newy]=dist[s1][s2]+1;
               pr[newx][newy]=d[i];
               q.push({newx,newy});
            }
         }
      }
   }
}
int main() {
   init_code();


   cin>>n>>m;
   
   
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {

         cin>>ar[i][j];
         if(ar[i][j]=='A')
         {
            srcx=i;
            srcy=j;
         }
         if(ar[i][j]=='B')
         {
            endx=i;
            endy=j;
         }

      }

   lli cnt=0;

   
 
  vector<char>ans;

   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         dist[i][j]=INT_MAX;

    dist[srcx][srcy]=0;
    
   

   memset(vis,0,sizeof(vis));
  
   bfs(srcx,srcy);
  
   if(dist[endx][endy]==INT_MAX)
   {
      cout<<"NO"<<endl;
   }
   else
   {
      cout<<"YES"<<endl;

    
      cout<<dist[endx][endy]<<endl;
      while(1)
      {
         ans.push_back(pr[endx][endy]);
         
            if(ans.back() == 'L') endy++;
            if(ans.back() == 'R') endy--;
            if(ans.back() == 'U') endx++;
            if(ans.back() == 'D') endx--;
            
            if(srcx == endx && srcy == endy)
            break;
      }
      reverse(ans.begin(),ans.end());
      for(int i=0;i<ans.size();i++)
         cout<<ans[i];
      cout<<endl;
   }
   return 0;
}