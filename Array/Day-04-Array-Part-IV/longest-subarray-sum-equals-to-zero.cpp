// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 15-06-23
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
  int n; cin >> n;
  vector<int>v(n);
  for(int i = 0; i < n; ++i){
  	cin >> v[i];
  }

  int maxLen = 0, sum = 0;
  unordered_map<int,int> mp;
  mp[0] = 1;

  for(int i = 0; i < n; ++i){
  	sum += v[i];
  	if(sum == 0){
  		maxLen = max(maxLen, i + 1);
  	}

  	if(mp.find(sum) != mp.end()){
  		maxLen = max(maxLen, i - mp[sum]);
  	}
  	mp[sum] = i;
  }

  cout << maxLen << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}