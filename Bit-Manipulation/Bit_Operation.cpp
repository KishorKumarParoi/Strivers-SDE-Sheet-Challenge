// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-17
Time: 11:27:47
Problem: All Bit Operation
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

int getKthBit(int n, int k) {
    int mask = (1 << k);
    return (n & mask) == 0 ? 0 : 1;
}

void clearKthBit(int& n, int k) {
    int mask = ~(1 << k);
    n = n & mask;
}

void setKthBit(int& n, int k) {
    int mask = (1 << k);
    n = (n | mask);
}

void updateKthBit(int& n, int k, int v) {
    clearKthBit(n, k);
    int mask = (v << k);
    n = (n | mask);
}

void clearLastKBits(int& n, int k) {
    // ~0 = -1
    // -1 = 111111111...
    int mask = (-1 << k);
    n = n & mask;
    // cout << mask << endl;
    // for (int i = 31; i >= 0; i--) {
    //     if (mask & (1 << i)) cout << 1;
    //     else cout << 0;
    // }
    // cout << endl;
}

void clearRangeBits(int& n, int i, int j) {
    if (i < j)
        swap(i, j);
    int a = (-1 << (i + 1));
    int b = (1 << j) - 1;
    int mask = a | b;
    n = n & mask;
}

void replaceRangeBits(int& n, int i, int j, int m) {
    clearRangeBits(n, i, j);
    int mask = m << min(i, j);
    n = n | mask;
}

int powOfTwo(int n) {
    return ((n & (n - 1)) == 0 ? 1 : 0);
}

int count_bits(int n) {
    // complexity : logn
    int cnt = 0;
    while (n > 0)
    {
        int last_bit = (n & 1);
        cnt += last_bit;
        n >>= 1;
    }
    return cnt;
}

int count_bits_hack(int n) {
    // complexity : log(no. of setbits)
    // more faster
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}

void solve() {
    int val, pos1, pos2, repVal; cin >> val >> pos1 >> pos2 >> repVal;
    // cout << getKthBit(val, pos) << endl;
    // clearKthBit(val, pos);
    // updateKthBit(val, pos, 1);
    // clearLastKBits(val, pos);
    // clearRangeBits(val, pos1, pos2);
    replaceRangeBits(val, pos1, pos2, repVal);
    cout << val << endl;
    cout << count_bits_hack(val) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}