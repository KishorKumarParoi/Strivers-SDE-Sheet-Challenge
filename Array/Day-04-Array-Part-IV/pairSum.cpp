// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 18-06-23
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
  int n, k; cin >> n >> k;
  vector<int>v(n);
  map<int,vector<int>> m;

  for(int i = 0; i < n; ++i){
    cin >> v[i];
    m[v[i]].push_back(i);
  }

  // PRINT(id[3])

  for(auto x : m){
    d(x.first) print(x.second)
  }

  // for(int i = 0; i < n; ++i){
  //   print(id[v[i]])
  // }

  vector<vector<int>>ans;
  vector<vector<int>>idx;

  map<int,int>mp;

  for(int i = 0; i < n; ++i){
  	if(mp.find(k - v[i]) != mp.end()){
      int val = mp[k - v[i]];

  		int mini = min(v[i], k - v[i]);
  		int maxi = max(v[i], k - v[i]);
      int k = 0;
      while(val--){
    		ans.push_back({mini, maxi});
        idx.push_back({i, m[k - v[i]][k++]});
      }
  	}
  	mp[v[i]]++;
  }

  sort(ans.begin(), ans.end());
  sort(idx.begin(), idx.end());
  
  for(auto x : ans){
  	print(x)
  }

  for(auto x : idx){
    print(x)
  }
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}