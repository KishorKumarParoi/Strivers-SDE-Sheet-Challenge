// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 27-06-23
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
  int n; cin >> n; 
  vector<int>v(n);
  for(int i = 0; i < n; ++i){
  	cin >> v[i];
  }

  deque<int>q;
  q.push_back(0);
  vector<int>ans(n, 0);
  unordered_map<int,int>mp;
  mp[v[0]] = 0;
  
  for(int i = 1; i < n; ++i){

  	if(q.empty()){
  		q.push_back(i);
  		continue;
  	}

  	while(!q.empty() and v[q.back()] < v[i]){
  		// d(q.back()) d(v[q.back()]) dl(v[i])

  		ans[q.back()] = v[i];
  		mp[v[i]] = q.back();

  		q.pop_back();
  	}

  	q.push_back(i);
  }

  while(!q.empty()){
  	ans[q.back()] = -1;
  	mp[v[q.back()]] = -1;
  	q.pop_back();
  }

  vector<int>nums = {2, 4};
  print(nums)
  print(ans)

  vector<int>a;

  PRINT(mp)

  for(int i = 0; i < nums.size(); ++i){
  	a.push_back(mp[nums[i]]);
  }

  print(a)
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}