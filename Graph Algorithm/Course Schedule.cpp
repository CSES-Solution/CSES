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
 
 
 
 
void init_code(){
 fast_io;
    #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
    #endif 
}
lli n,m;
int vis[100005], dist[100005];

void dfs(int node,vector<int>adj[],stack<int>& st)
{
    vis[node]=1;

    for(auto item:adj[node])
    {
        if(!vis[item])
        {
            dfs(item,adj,st);
        }
    }

    st.push(node);
}

int main() {
   init_code();


    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>indegree(n+1,0);
    lli a,b;
    rep(i,m)
    {
        cin>>a>>b;
        adj[a].pb(b);
        // adj[b].pb(a);
        indegree[b]++;
    }

    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    
    vector<int>ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        ans.pb(node);

        for(auto item:adj[node])
        {
            indegree[item]--;
            if(indegree[item]==0)
                q.push(item);
        }
    }

    if(ans.size()!=n)
    {
        cout<<"IMPOSSIBLE"<<endl;

    }
    else
    {


        for(int i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}