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





int main() {
   init_code();
   
   string str;
   cin>>str;

 
   map<char,int>mp;
   for(int i=0;i<str.length();i++)
      mp[str[i]]++;


   char ch;
   int cnt=0;
   for(auto item:mp)
  {
     
       if(item.second%2!=0)
       {
            cnt++;ch=item.first;
       }

   }

   if(cnt>1)
      cout<<"NO SOLUTION"<<endl;
   else
   {
      string ans="";

      for(auto item:mp)
      {
         // cout<<item.first<<" "<<item.second<<endl;
         for(int i=0;i<item.second/2;i++)
            ans+=item.first;
      }
      string res=ans;
      if(ch)
      ans+=ch;
      reverse(res.begin(),res.end());

      ans+=res;
      cout<<ans<<endl;
   }
   return 0;
}