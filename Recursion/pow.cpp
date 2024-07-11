// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-09
Time: 15:26:22
Problem: Pow Function
Link: https://leetcode.com/problems/powx-n/description/
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define endl "\n"
// #define int long long
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

double recursiveBinExpo(double a, long int b, double res) {
    if (!b)
        return res;

    if (b & 1)
        res *= a;
    a *= a;
    b >>= 1;
    return recursiveBinExpo(a, b, res);
}

double myPow(double x, int n) {
    if (n == 0)
        return 1;
    if (n < 0) {
        return 1.00 / recursiveBinExpo(x, n * (-1L), 1L);
    }
    return recursiveBinExpo(x, n * 1L, 1L);
}

void solve() {
    cout << myPow(-2, -3) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}