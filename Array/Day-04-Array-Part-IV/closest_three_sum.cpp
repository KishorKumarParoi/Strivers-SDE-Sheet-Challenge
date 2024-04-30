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

  int diff = INT_MAX;
  int ans = INT_MAX;
  sort(v.begin(), v.end());
  
  for(int i = 0; i < n; ++i){
  	int j = i + 1, k = n - 1;
  	while(j < k){
  		int sum = v[i] + v[j] + v[k];
  		d(sum) d(i) d(j) dl(k)
  		if(sum == target){
  			// cout << sum << endl;
        dl(sum)
  			// return sum;
        ans = sum;
  			break;
  		}
  		else if(sum < target){
  			if(diff > abs(target - sum)){
  				ans = sum;
  				diff = target - sum;
  			}
  			j++;
  		}
  		else{
  			if(diff > abs(sum - target)){
  				ans = sum - target;
  				diff = sum - target;
  			}
  			k--;
  		}
  	}
  }

  cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}