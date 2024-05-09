// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-09
Time: 19:53:49
Problem: Pascals Triangle
Link: https://leetcode.com/problems/pascals-triangle/description/
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

vector<vector<int>> generate(int numRows) {

    // 5c2 = 5! / (2! * (5 - 2!)) = (5 * 4 * 3 * 2 * 1) / ((2 * 1) * (3 * 2 * 1))
    // = (5 * 4) / (2 * 1)
    // 5c3 = (5 * 4 * 3)/ (3 * 2 * 1)

    vector<vector<int>>ans;

    for (int i = 0; i < numRows; i++) {
        vector<int>v;
        v.push_back(1);
        int val = 1;
        for (int j = 1; j < i; j++) {
            val *= (i - j + 1);
            val /= j;
            v.push_back(val);
        }
        if (i > 0)
            v.push_back(1);
        ans.push_back(v);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> ans = generate(n);
    for (auto x : ans) {
        print(x);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}