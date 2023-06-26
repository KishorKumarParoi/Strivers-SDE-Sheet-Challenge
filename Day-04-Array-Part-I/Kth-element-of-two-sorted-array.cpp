// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 26-06-23
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
  int n, m, k; cin >> n >> m >> k;
  vector<int>a(n), b(m);

  for(int i = 0; i < n; ++i){
  	cin >> a[i];
  }

  for(int i = 0; i < m; ++i){
  	cin >> b[i];
  }

  int l = max(0, k - m), r = min(k, n);
  int ans = 0;

  while(l <= r){
  	int cut1 = (l + r) >> 1;
  	int cut2 = k - cut1;

  	int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
  	int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
  	int r1 = (cut1 == n) ? INT_MAX : a[cut1];
  	int r2 = (cut2 == m) ? INT_MAX : b[cut2];

  	if(l1 > r2){
  		r = cut1 - 1;
  	}
  	else if(l2 > r1){
  		l = cut1 + 1;
  	}
  	else{
  		ans = min(r1,r2);
  	}
  }

  cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}