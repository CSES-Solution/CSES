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
int level[200001];
vi adj[200002];
vi g[200002];
set<int> *st[200001];

// void dfs(int node, int par)
// {
//     vi childlist;
//     for(auto child:ar[node])
//     {
//         if(child!=par)
//         {
       
//             dfs(child,node);
//             f[node]=max(f[node],f[child]+1);
//             // f[child]=max(f[child],f[node]+1);
//         }
        
//     }
   
// }

void get_level(int node,int par,int lvl)
{
    level[node]=lvl;

    for(auto item:adj[node])
    {
        if(item!=par)
        {
            get_level(item,node,lvl+1);
        }
    }
}
int main() {
   init_code();
   int n , a ,q,b;
    cin>>n>>q;
    lli maxn=21;
    lli ar[n+1][maxn+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=maxn;j++)
            ar[i][j]=-1;
    loop(i ,2,n+1) 
    {
        cin>>a;
        ar[i][0]=a;
        adj[i].pb(a);
        adj[a].pb(i);
    }
    int lvl=0;
    get_level(1,-1,lvl);

    REP(j,maxn)
    {
        for(int i=1;i<=n;i++)
        {
            if(ar[i][j-1]!=-1)
            {
                int par=ar[i][j-1];
                ar[i][j]=ar[par][j-1];
            }
        }
    }

    while(q--)
    {
        cin>>a>>b;
        if(level[b]<level[a])swap(a,b);
        int d=level[b]-level[a];
        while(d>0)
        {
            int i=log2(d);
            b=ar[b][i];
            d-=(1<<i);
        }

        if(a==b)
        {
            cout<<a<<endl;
            continue;
        }
        for(int i=maxn;i>=0;i--)
        {
            if(ar[a][i]!=-1 && (ar[a][i]!=ar[b][i]))
            {
                a=ar[a][i];
                b=ar[b][i];
            }
        }
        // cout<<a<<endl;
        cout<<ar[a][0]<<endl;

    }


    return 0;
}