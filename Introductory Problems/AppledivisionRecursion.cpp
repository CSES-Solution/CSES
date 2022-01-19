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




void find_min(int i,lli ar[],int n,lli sum1,lli sum2,lli& m)
{

   if(i==n)
   {
      
      m=min(m,abs(sum1-sum2));

      // cout<<m<<endl;

      return ;
   }
   //sum1 ko lena hai
   find_min(i+1,ar,n,sum1+ar[i],sum2,m);

   //sum2 ko lena hai
   find_min(i+1,ar,n,sum1,sum2+ar[i],m);
}
int main() {
   init_code();
   
   int n;
   cin>>n;
   lli ar[n];
   rep(i,n)
   cin>>ar[i]; 

   lli m=INT_MAX;

   lli sum1=0,sum2=0;

   find_min(0,ar,n,sum1,sum2,m);

   cout<<m<<endl;
   return 0;
}