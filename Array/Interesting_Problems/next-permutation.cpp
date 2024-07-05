// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 25-06-23
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

  int break_point = 0;
  for(int i = n - 2; i >= 0; i--){
  	if(v[i] < v[i + 1]){
  		break_point = i;
  		break;
  	}
  }

  int minMax = INT_MAX, minMax_id = -1;

  for(int i = break_point + 1; i < n; ++i){
  	if(v[i] > v[break_point]){
  		minMax = min(minMax, v[i]);
  		minMax_id = i;
  	}
  }

  if(minMax_id == -1){
  	reverse(v.begin(), v.end());
  }
  else{
  	swap(v[break_point], v[minMax_id]);
  	// print(v)
  	
  	sort(v.begin() + break_point + 1, v.end());
  }

  print(v)
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}