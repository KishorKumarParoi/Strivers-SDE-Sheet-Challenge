// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-02
Time: 15:27:46
Problem: reverseInt
Link: https://leetcode.com/problems/reverse-integer/description/
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define endl "\n"
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


int reverse(int x) {
    long int reversedInt = 0;
    bool minusCheck = x > 0 ? false : true;
    x = abs(x);

    while (x != 0) {
        int modVal = x % 10;
        reversedInt *= 10;
        reversedInt += modVal;
        x /= 10;
        // d(modVal) d(reversedInt) dl(x)
            // if (x == 0) break;
    }
    if (reversedInt > INT_MAX || reversedInt < INT_MIN) return 0;
    return (minusCheck ? (-1) * reversedInt : reversedInt);
}

void solve() {
    int n; cin >> n;
    cout << reverse(n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}