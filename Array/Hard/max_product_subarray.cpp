// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-02
Time: 10:54:33
Problem: Maximum Product Subarray
Link:https://www.interviewbit.com/problems/subarray-with-given-xor/
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
#define all(v)                            v.begin(),v.end()
#define TEST                              int tc;cin>>tc; while(tc--)
// Debug
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout << #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int maxProduct(vector<int>& arr) {
    int n = arr.size();
    __int128_t prefix = 1;  // double prefix = 1
    __int128_t suffix = 1;
    __int128_t ans = arr[0];

    for (int i = 0; i < n; i++) {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxProduct(arr) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}