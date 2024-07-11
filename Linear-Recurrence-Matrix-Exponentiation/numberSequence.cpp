// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-11
Time: 15:21:10
Problem: Number Sequence
Link: https://lightoj.com/problem/number-sequence
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

int mod = 1e9 + 7;
const int sz = 3;

struct Mat {
    int m[sz][sz];

    Mat() {
        memset(m, 0, sizeof(m));
    }

    void identity() {
        for (int i = 0; i < sz; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator* (Mat a) {
        Mat res;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }

};

int fiboSum(int a, int b, int n, int lastMDigit) {
    // base case
    if (n <= 0)
        return a;
    if (n == 1)
        return b;

    int val = 1;
    while (lastMDigit--) {
        val *= 10;
    }

    mod = val;

    // n >= 2
    Mat res;
    res.identity();
    Mat T;

    T.m[0][0] = 1, T.m[0][1] = 1;
    T.m[1][0] = 1, T.m[1][1] = 0;

    int temp = n - 1;

    while (temp) {
        if (temp & 1)
            res = res * T;
        T = T * T;
        temp >>= 1;
    }

    // cout << "n: " << n << " -> ";
    // cout << res.m[0][0] << " " << res.m[0][1] << endl;

    return (res.m[0][0] * b + res.m[0][1] * a) % (mod);
}

void solve() {
    int a, b, n, lastMDigit;
    cin >> a >> b >> n >> lastMDigit;
    cout << fiboSum(a, b, n, lastMDigit) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    int testCase; cin >> testCase;
    for (int i = 1; i <= testCase;i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}