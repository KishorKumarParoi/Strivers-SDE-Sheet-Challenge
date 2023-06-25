// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 20-06-23
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

int merge(vector<int>& arr, int s, int e){
	int i = s, m = (s + e) / 2, j = m + 1;
	vector<int>tmp;
	int cnt = 0;

	while(i <= m and j <= e){
		if(arr[i] < arr[j]){
			tmp.push_back(arr[i]);
			i++;
		}
		else{
			tmp.push_back(arr[j]);
			cnt += (m - i + 1);
			j++;
		}
	}

	while(i <= m){
		tmp.push_back(arr[i]);
		i++;
	}

	while(j <= e){
		tmp.push_back(arr[j]);
		j++;
	}

	int k = 0;
	for(int idx = s; idx <= e; ++idx){
		arr[idx] = tmp[k++];
	}

	return cnt;
}

int inversion_count(vector<int>&arr, int s, int e){
	if(s >= e)
		return 0;
	int m = (s + e) / 2;

	int C1 = inversion_count(arr, s, m);
	int C2 = inversion_count(arr, m + 1, e);
	int CI = merge(arr, s, e);

	return C1 + C2 + CI;
}

void solve(){
  int n; cin >> n;
  vector<int>arr(n);
  for(int i = 0; i < n; ++i){
  	cin >> arr[i];
  }

  cout << inversion_count(arr, 0, n - 1) << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}