// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 16-06-23
#include "bits/stdc++.h"
            
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
  vector<int>arr(n);
  for(int i = 0; i < n; ++i){
  	cin >> arr[i];
  }

  vector<int>tmp;
  int len = 1;
  tmp.push_back(arr[0]);


  for(int i = 0; i < n; ++i){
  	if(tmp.back() < arr[i]){
  		tmp.push_back(arr[i]);
  		len++;
  	}
  	else{
  		// int *a = &*std::lower_bound(x.begin(), x.end(),temp1);
  		int ind = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
  		tmp[ind] = arr[i];
  	}
  }

  cout << len << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}