// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 19-06-23
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
  int n, target; cin >> n >> target;
  vector<int>v(n);
  for(int i = 0; i < n; ++i){
  	cin >> v[i];
  }

  sort(v.begin(), v.end());
  set<vector<int>>st;
  print(v)
  
  for(int i = 0; i < n; ++i){
  	int j = i + 1, k = n - 1;

  	while(j < k){
  		int sum = v[i] + v[j] + v[k];

  		if(sum == target){
  			st.insert({v[i], v[j], v[k]});
  			j++;
  			k--;
  		}
  		else if(sum < target)
  			j++;
  		else
  			k--;
  	}
  }

  for(auto x : st){
  	print(x)
  }
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}