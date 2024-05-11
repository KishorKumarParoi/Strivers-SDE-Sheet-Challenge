// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-11
Time: 14:40:17
Problem: Subarray with given XORsum
Link: https://www.interviewbit.com/problems/subarray-with-given-xor/
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

int SubarrayXorSumCount(vector<int>& arr, int target) {
    int cnt = 0, n = arr.size();
    unordered_map<int, int>mp;
    mp[0] = 1;
    int xorr = 0;

    for (int i = 0; i < n; i++) {
        xorr ^= arr[i];
        int rem = target ^ xorr;
        cnt += mp[rem];
        mp[xorr]++;
    }
    return cnt;
}

void solve() {
    int n, target; cin >> n >> target;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = SubarrayXorSumCount(arr, target);
    cout << cnt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}