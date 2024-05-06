// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-06
Time: 23:43:53
Problem: Stock Buy and Sell
Link:
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

int bestTimeToBuyAndSellStock(vector<int>& prices) {
    // Write your code here.
    int profit = 0, n = prices.size(), cost = 0, mini = prices[0];
    for (int i = 0; i < n; i++) {
        // 7 1 2 5 6 4
        // i:0 -> mini - 7, cost - 7, profit - 0
        // i:1 -> mini - 1, cost - 1, profit - 0
        // i:2 -> mini - 1, 
        if (mini > prices[i]) mini = prices[i];
        profit = max(profit, prices[i] - mini);
    }
    return profit;
}

void solve() {

}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}