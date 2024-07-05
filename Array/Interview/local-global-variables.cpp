// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 24-06-23
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

int mergeSort(vector<int>&v, int s, int e){
	int i = s, m = (s + e) / 2, j = m + 1;
	vector<int>tmp;
	int cnt = 0;

	while(i <= m and j <= e){
		if(v[i] < v[j]){
			tmp.push_back(v[i]);
			i++;
		}
		else{
			cnt += (m - i + 1);
			tmp.push_back(v[j]);
			j++;
		}
	}

	while(i <= m){
		tmp.push_back(v[i]);
		i++;
	}

	while(j <= e){
		tmp.push_back(v[j]);
		j++;
	}

	int k = 0;
	for(int idx = s; idx <= e; ++idx){
		v[idx] = tmp[k++];
	}
	return cnt;
}
int inversion_count(vector<int>&v, int s, int e){
	if(s >= e)
		return 0;
	int m = (s + e) / 2;
	int C1 = inversion_count(v, s, m);
	int C2 = inversion_count(v, m+1, e);
	int CI = mergeSort(v, s, e);
	return C1 + C2 + CI;
}
bool isIdealPermutation(vector<int>& v) {
	int n = v.size();
	int local = 0;
	for(int i = 0; i < n - 1; ++i){
		if(v[i] > v[i+1])
			local++;
	}

	int global = inversion_count(v, 0 , n - 1);
	cout << "global " << global << endl;
	cout << "local " << local << endl;
	int biyogfol = abs(global - local);
	cout << "biyogfol " << biyogfol << endl;
	
	return (biyogfol > 0);
}

void solve(){
	int n; cin >> n;
	vector<int>v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}

	cout << isIdealPermutation(v) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	solve();

	return 0;
}