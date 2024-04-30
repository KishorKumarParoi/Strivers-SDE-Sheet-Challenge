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
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}

	// int n = v.size();
	int i = 0, j = n - 1, sum = 0;

	vector<pair<int,int>>vp;
	for(int i = 0; i < n; ++i){
		vp.push_back({v[i], i});
	}
	sort(vp.begin(), vp.end());
	vector<int>ans = {-1, -1};

    // for(auto x : vp){
    // 	cout << x.first << " " << x.second << endl;
    // }
   
	while(i < j){
		sum =  vp[i].first + vp[j].first;
		if(sum == k){
			ans[0] = vp[i].second;
			ans[1] = vp[j].second;
			break;
		}
		else if(sum < k)
			i++;
		else
			j--;
	}

	print(ans)
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	solve();

	return 0;
}