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


void leetcode(){
	class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& v,long long int target) {
			int n = v.size();
			sort(v.begin(), v.end());
			
			set<vector<int>>st;
			for(int i = 0; i < n; ++i){
				for(int j = i + 1; j < n; ++j){
					int k = j + 1, l = n - 1;

					while(k < l){
						long long	int sum1 = v[i] + v[j];
						long long	int sum2 = v[k] + v[l];
						if(target - sum1 - sum2 == 0){
							st.insert({v[i], v[j], v[k], v[l]});
							k++;
							l--;
						}
						else if(target - sum1 - sum2 > 0){
							k++;
						}
						else{
							l--;
						}
					}
				}
			}

			vector<vector<int>>ans;
			for(auto x : st){
  	// print(x);
				ans.push_back(x);
			}

			return ans;
		}
	};
}


void solve(){
	int n, target; cin >> n >> target;
	vector<int>v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	set<vector<int>>st;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int k = j + 1, l = n - 1;

			while(k < l){
				int sum = v[i] + v[j] + v[k] + v[l];
				if(sum == target){
					st.insert({v[i], v[j], v[k], v[l]});
					k++;
					l--;
				}
				else if(sum < target){
					k++;
				}
				else{
					l--;
				}
			}
		}
	}

	for(auto x : st){
		print(x);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(nullptr));
	
	solve();

	return 0;
}