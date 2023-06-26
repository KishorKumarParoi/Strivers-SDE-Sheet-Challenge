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
  int n, m; cin >> n >> m;
  vector<int>a(n), b(m);

  for(int i = 0; i < n; ++i){
  	cin >> a[i];
  }

  for(int i = 0; i < m; ++i){
  	cin >> b[i];
  }

  // binary search median of two sorted arrays 0(log(min(x + y)))

  // if(a.size() > b.size()) median(a, b);
  if(a.size() > b.size()) swap(a, b);

  int n1 = a.size();
  int n2 = b.size();
  double ans = 0;

  if(n1 == 0){
  	if(n2 & 1){
  		// cout << b[n2/2] << endl;
  		ans = b[n2/2];
  	}
  	else{
  		// cout << b[n2/2] << " " << b[n2/2-1] << endl;
  		ans = (b[n2/2] + b[(n2/2)-1] ) / 2.000 ;
  	}
  }

  int l = 0, r = n1;

  while(l <= r){
  	int m1 = l + (r - l) / 2;
  	int m2 = (n1 + n2 + 1) / 2 - m1;

  	int l1 = (m1 == 0) ? INT_MIN : a[m1 - 1];
  	int l2 = (m2 == 0) ? INT_MIN : b[m2 - 1];

  	int r1 = (m1 == n1) ? INT_MAX : a[m1];
  	int r2 = (m2 == n2) ? INT_MAX : b[m2];

  	if(l1 <= r2 and l2 <= r1){
  		if((n1 + n2) & 1){
  			// return (max(l1, l2));
  			ans = (max(l1, l2));
  		}
  		else{
  			// return ((max(l1, l2) + min(r1, r2)) / 2.00);
  			ans = ((max(l1, l2) + min(r1, r2)) / 2.00);
  		}
  		break;
  	}
  	else if(l1 > r2){
  		r = m1 -1;
  	}
  	else{
  		l = m1 + 1;
  	}
  }

  cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}