// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-03
Time: 15:11:18
Problem: Max Min Frequency
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

vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++) {
        mp[v[i]]++;
    }
    PRINT(mp);
    vector<int>ans;
    int minFreq = INT_MAX;
    int maxFreq = INT_MIN;
    int maxFreqElement = -1;
    int minFreqElement = -1;

    for (auto x : mp) {
        if (x.second > maxFreq) {
            maxFreq = x.second;
            maxFreqElement = x.first;
        }
        if (x.second < minFreq) {
            minFreq = x.second;
            minFreqElement = x.first;
        }
    }
    cout << "Max Frequency: " << maxFreq << " Element: " << maxFreqElement << endl;
    cout << "Min Frequency: " << minFreq << " Element: " << minFreqElement << endl;

    ans.emplace_back(maxFreqElement);
    ans.emplace_back(minFreqElement);
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>res = getFrequencies(arr);
    print(res);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}