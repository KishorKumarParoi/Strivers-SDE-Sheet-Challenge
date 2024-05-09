// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-09
Time: 21:19:28
Problem: Majority Element
Link: https://leetcode.com/problems/majority-element-ii/description/
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

vector<int> majorityElement(vector<int>& nums) {
    ios_base::sync_with_stdio(!cin.tie(nullptr));
    // 3 2 3
    // int mini = (n / 3) + 1
    // 15/3 = 5, [6, 6, 3] -> max two times

    int n = nums.size();

    int firstEle = INT_MIN, secEle = INT_MIN, ele = 0;
    int cnt1 = 0, cnt2 = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && secEle != nums[i]) {
            firstEle = nums[i];
            cnt1++;
        }
        else if (cnt2 == 0 && firstEle != nums[i]) {
            secEle = nums[i];
            cnt2++;
        }
        else if (firstEle == nums[i]) {
            cnt1++;
        }
        else if (secEle == nums[i]) {
            cnt2++;
        }
        else {
            cnt2--;
            cnt1--;
        }
    }

    // d(firstEle) dl(secEle);

    cnt1 = 0, cnt2 = 0;
    int mini = (n / 3) + 1;

    for (int i = 0; i < n; i++) {
        if (firstEle == nums[i]) {
            cnt1++;
        }
        if (secEle == nums[i]) {
            cnt2++;
        }
    }

    // d(cnt1) dl(cnt2);

    vector<int>ans;
    if (cnt1 >= mini) ans.push_back(firstEle);
    if (cnt2 >= mini) ans.push_back(secEle);
    sort(ans.begin(), ans.end());

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int>ans = majorityElement(arr);
    print(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}