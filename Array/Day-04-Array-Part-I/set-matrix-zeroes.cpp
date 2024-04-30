// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 25-07-23
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
	int n, m; cin >> n >> m;
	int arr[n+10][m+10];

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> arr[i][j];
		}
	}

	int col[m + 10] = {0};
	int row[n+10] = {0};

	for(int i = 0 ; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(arr[i][j] == 0){
				row[i] = -1;
				col[j] = -1;
			}
		}
	}

	printArr(0, n, row)
	printArr(0, m, col)

	for(int i = 0; i < n; ++i){
		if(row[i] == -1){
			for(int k = 0; k < m; ++k){
				arr[i][k] = 0;
			}
		}
	}

	for(int i = 0; i < m; ++i){
		if(col[i] == -1){
			for(int k = 0; k < n; ++k){
				arr[k][i] = 0;
			}
		}
	}
  
  for(int i = 0; i < n; ++i){
  	for(int j = 0; j < m; ++j){
  		cout << arr[i][j] << " ";
  	}
  	cout << endl;
  }
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}