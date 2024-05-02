// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-02
Time: 16:33:07
Problem: Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/description/
*/
#include <bits/stdc++.h>
#include <cctype>
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

bool isPalindrom(string s) {
    string temp = "";
    int i = 0;
    while (i < s.size()) {
        if (isalnum(s[i])) {
            temp += tolower(s[i]);
        }
        i++;
    }
    int len = temp.size();

    for (int i = 0; i < len / 2; i++) {
        if (temp[i] != temp[len - i - 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    string s; cin >> s;
    isPalindrom(s) ? cout << "Yes" << endl : cout << "No" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}