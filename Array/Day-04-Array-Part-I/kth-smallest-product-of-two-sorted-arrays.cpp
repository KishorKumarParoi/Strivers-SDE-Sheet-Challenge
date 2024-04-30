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

// ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
//   ll l = -1e10, r = 1e10;
//   ll ans;
//   while (l <= r) {
//     ll m = (l+r) / 2;
    
//     ll cnt = 0;
//     for (int x : nums1) {
//       if (x == 0) cnt += (m >= 0) * size(nums2);
//       else if (x > 0) cnt += upper_bound(all(nums2), m / x - (m < 0 && m % x)) - begin(nums2);
//       else cnt += end(nums2) - lower_bound(all(nums2), m / x + (m < 0 && m % x));
//     }
//     if (cnt < k) l = m+1;
//     else ans = m, r = m-1;
//   }
//   return ans;
// }


void solve(){
  int n, m, k; cin >> n >> m >> k;
  vector<int>a(n),b(m);

  for(int i = 0; i < n; ++i){
  	cin >> a[i];
  }

  for(int i = 0; i < m; ++i){
  	cin >> b[i];
  }

  int l = -1e10, r = 1e10;
  int ans;

  while(l <= r){
  	int m = (l + r) >> 1;

  	int cnt = 0;

  	for(int x : a){
  		if(x == 0)
  			cnt += (m >= 0) * 
  	}
  }
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}