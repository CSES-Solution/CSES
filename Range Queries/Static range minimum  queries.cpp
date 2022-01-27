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
lli ar[1000000];
lli br[1000000];


void build_tree(lli si,lli ss,lli se)
{
   if(ss==se)
   {
      br[si]=ar[ss];
      return ;
   }

   lli mid=(ss+se)/2;

   build_tree(2*si,ss,mid);
   build_tree(2*si+1,mid+1,se);

   br[si]=min(br[2*si],br[2*si+1]);


}
lli query(lli si,lli ss,lli se,lli qs,lli qe)
{
   if(ss>qe || se<qs)
      return INT_MAX;

   if(ss>=qs && se<=qe)
      return br[si];

   lli mid=(ss+se)/2;

   int l = query(2*si , ss , mid , qs , qe);
   int r = query(2*si+1 , mid+1 , se , qs , qe);

   return min(l,r);


}
 

int main() {
   init_code();
   
   lli n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++) 
   cin>>ar[i];

   
   build_tree(1,1,n);

   

   lli a,b;
   while(q--)
   {

      cin>>a>>b;
      cout<<query(1,1,n,a,b)<<endl;
   }
   
   return 0;
}