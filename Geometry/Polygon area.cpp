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

struct point {
   lli x;
   lli y;
};
lli find_ans(point a,point b,point c)
{
   return (b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
}
int main() {
   init_code();
   
   lli n;
   cin>>n;
   point ar[n];
   rep(i,n)
      cin>>ar[i].x>>ar[i].y;


   lli res=0;

   for(int i=0;i<n;i++)
   {
      int j=i+1;
      if(i==n-1)
         j=0;

      res+=(ar[j].y+ar[i].y)*(ar[i].x-ar[j].x);
   }

   cout<<abs(res)<<endl;
   return 0;
}