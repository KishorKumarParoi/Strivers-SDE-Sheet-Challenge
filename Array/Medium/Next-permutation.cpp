// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-07
Time: 08:43:09
Problem: Next Permutation
Link: https://leetcode.com/problems/next-permutation/
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


void nextPermutation(vector<int>& nums) {
    ios_base::sync_with_stdio(!cin.tie(nullptr));
    // print(nums);

    //  // 2 1 5 4 3 0 0 0

    int break_point = -1;
    int length = nums.size();

    for (int i = length - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            break_point = i;
            break;
        }
    }

    if (break_point < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = length - 1; i > break_point; i--) {
        if (nums[i] > nums[break_point]) {
            swap(nums[i], nums[break_point]);
            break;
        }
    }

    reverse(nums.begin() + break_point + 1, nums.end());
}


void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int>ans = nextPermutation(arr);
    print(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}