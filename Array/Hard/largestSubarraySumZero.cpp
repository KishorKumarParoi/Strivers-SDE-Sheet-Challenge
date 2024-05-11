// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-11
Time: 14:52:44
Problem: Largest Subarray of Sum equals to zero
Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category[]=Hash&company[]=Amazon&page=1&query=category[]Hashcompany[]Amazonpage1company[]Amazoncategory[]Hash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum
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

int largestPos(vector<int>& arr, int n) {
    int maxlen = 0, sum = 0;
    int left = 0, right = n - 1;

    while (right < n) {
        if (sum == 0) {
            maxlen = max(maxlen, right - left + 1);
        }

        while (left <= right and sum > 0) {
            sum -= arr[left];
            left++;
        }

        right++;
        if (right < n) {
            sum += arr[right];
        }
    }

    return maxlen;
}

// pos+neg
int largest(vector<int>& arr, int n) {
    // -2 -2 -2 -1 -1 -1 0 0 0 1 1 1 2 2 2 
    // -3 -4 1 0 0 -1 4 3
    int left = 0, right = 0;
    int len = 0, maxLen = 0, cnt = 0;
    int sum = 0;
    unordered_map<int, int>mp;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            maxLen = max(maxLen, i + 1);
        }
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
        else {
            maxLen = max(maxLen, i - mp[sum]);
        }
    }

    return maxLen;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << largestPos(arr, n) << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}