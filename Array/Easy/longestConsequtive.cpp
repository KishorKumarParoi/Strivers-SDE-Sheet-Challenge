// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-07
Time: 16:25:20
Problem: Longest Consequtive
Link: https://leetcode.com/problems/longest-consecutive-sequence/
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

int longestConsecutive(vector<int>& a) {
    // TC : O(nlogn) + O(n)
    // SC : O(1)

    int n = a.size();
    if (n == 0) return 0;
    sort(a.begin(), a.end());

    int last_smaller = INT_MIN, cnt = 0, longest = 1;

    for (int i = 0; i < n; i++) {
        if (last_smaller == a[i]) {
            continue;
        }
        else if (last_smaller == a[i] - 1) {
            last_smaller = a[i];
            cnt++;
        }
        else if (last_smaller < a[i] - 1) {
            last_smaller = a[i];
            cnt = 1;
        }

        longest = max(longest, cnt);
    }

    return longest;
}

int OptimumlongestConsecutive(vector<int>& a) {
    // TC : O(n) + O(n + n)
    // SC : O(n)

    ios_base::sync_with_stdio(!cin.tie(nullptr));
    int n = a.size(), longest = 1;
    if (n == 0) return 0;

    unordered_set<int>st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (st.find(a[i] - 1) != st.end()) {
            continue;
        }
        else {
            int x = a[i];
            int cnt = 1;
            while (st.find(++x) != st.end()) {
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

void solve() {

}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}