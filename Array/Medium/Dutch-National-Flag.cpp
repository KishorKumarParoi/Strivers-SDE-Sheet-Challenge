// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-06
Time: 11:05:05
Problem: Sort of 0's, 1's, 2's
Link: https://leetcode.com/problems/sort-colors/
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

class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(!cin.tie(nullptr));
        // 0 - (low-1) | low - (mid - 1) | mid - high  | (high + 1) - (n - 1)
        // 0 0 0 0 0 0 | 1 1 1 1 1 1 1 1 | 0 1 2 1 0 2 |  2 2 2 2 2 2 2 2 2 2 2
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};

void solve() {

}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}