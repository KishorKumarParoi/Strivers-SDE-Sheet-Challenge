// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-10
Time: 15:27:49
Problem: Binary Exponentiation
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

// (a * b) % c where a,b,c <= 1e15
int fastMultiply(int a, int b, int c) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res += a, res %= c;
        a += a, a %= c;
        b >>= 1;
    }
    return res;
}

int binExpo(int a, int b) {
    // (a ^ b) % MOD
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a, res %= MOD;
        a *= a, a %= MOD;
        b >>= 1;
    }
    return res;
}

int recursiveBinExpo(int a, int b, int res) {
    if (!b)
        return res;

    if (b & 1)
        res *= a, res %= MOD;
    a *= a, a %= MOD;
    b >>= 1;
    return recursiveBinExpo(a, b, res);
}

void solve() {
    int a, b; cin >> a >> b;
    cout << binExpo(a, b) << endl;
    cout << recursiveBinExpo(a, b, 1) << endl;
    cout << fastMultiply(a, b, MOD) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}