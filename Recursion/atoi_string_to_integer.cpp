// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-08
Time: 21:58:05
Problem: String to Integer
Link: https://leetcode.com/problems/string-to-integer-atoi/description/
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



int myAtoi(string s) {
    int n = s.size();
    long ans = 0, i = 0;
    int sign = 1;

    if (s[i] == ' ') {
        while (s[i] == ' ') i++;
    }

    // dl(INT_MIN);

    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
        i++;

    if (s[i] == '0') {
        while (s[i] == '0') i++;
    }

    // cout << (1 << 31) - 1 << endl;


    while (i < n) {
        if (s[i] >= '0' and s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            // d(i) d(sign) dl(ans);
            if (sign < 0 and ans * sign <= INT_MIN) {
                return INT_MIN;
            }
            if (sign > 0 and ans >= INT_MAX) {
                return INT_MAX;
            }
            i++;
        }
        else
            break;
    }
    if (sign < 0 and ans * sign <= INT_MIN) {
        return INT_MIN;
    }
    if (sign > 0 and ans >= INT_MAX) {
        return INT_MAX;
    }

    return ans * sign;
}

void solve() {
    string s = "  +02147483648";
    cout << myAtoi(s) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}