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
 
lli highest_dig(lli n)
{
   vector<lli>ans;
   while(n>0)
   {
      ans.push_back(n%10);
      n/=10;
   }

   sort(ans.begin(),ans.end(),greater<lli>());

   return ans[0];
}
 
 
int main() {
   init_code();
   
  lli n;
  cin>>n;
  set<lli>s;
  multiset<lli>m;

  s.insert(0);
  s.insert(n);
  m.insert(n);
  lli pos,q;
  cin>>q;
  while(q--)
  {
      cin>>pos;

      auto it=s.upper_bound(pos);
      auto it2=it;
      it2--;

      s.insert(pos);
      m.insert(pos-*it2);
      m.insert(*it-pos);

      m.erase(m.find(*it-*it2));

      auto ans=m.end();
      ans--;
      cout<<*ans<<" ";
  }
  cout<<endl;
   return 0;
}