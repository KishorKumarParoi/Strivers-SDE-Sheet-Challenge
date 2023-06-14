// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 14-06-23
#include <bits/stdc++.h>
            
#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
#define pi acos(-1.0)
#define fr(i,a,b)                         for(int i=a;i<=b;++i)
#define all(v)                            v.begin(),v.end()
#define TEST                              int tc;cin>>tc; while(tc--)
// Debug
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout << #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

using namespace std;

const int N   = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
  // cout << "Hello World";
  string s; cin >> s;
  int n = s.size();

  map<char,int>mp;

  int i = 0, j = 0, ans = 0;
  
  while(j < n){
    mp[s[j]]++;

    if(mp.size() == j - i + 1){
      ans = max(ans, j - i + 1);
    }
    else if(mp.size() < j - i + 1){
      while(mp.size() < j - i + 1){
        --mp[s[i]];
        if(mp[s[i]] == 0){
          mp.erase(s[i]);
        }
        ++i;
      }
    }

    ++j;
  }

  cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}