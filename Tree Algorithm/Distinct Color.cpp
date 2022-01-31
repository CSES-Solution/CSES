#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
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

int c[200002];
int res[200001];
vi ar[200002];
set<int> *st[200001];

void dfs(int node, int par)
{
    int mx = 0;
    int mxNode = -1;
    
    for(int child : ar[node])
    if(child != par)
    {
        dfs(child , node);
        if( st[child]->size() > mx )
        mx = st[child]->size() , mxNode = child;
    }
    
    if(mxNode == -1) st[node] = new set<int>();
    else             st[node] = st[mxNode];
    
    st[node] -> insert(c[node]);
    
    for(int child : ar[node])
    if(child != par && child != mxNode)
    {
        for(int color : *st[child])
        st[node]->insert(color);
    }
    
    res[node] = st[node] -> size();
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
   int n , a , b;
    cin>>n;
    REP(i , n) cin>>c[i];
    
    REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
    
    dfs(1 , -1);
    
    REP(i , n) cout<<res[i]<<" ";

    return 0;
}