// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-02
Time: 13:58:23
Problem: Count Inversion
Link:
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

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int>temp;
    int left = low, right = mid + 1;
    // nums[i] > 2 * nums[j]

    long long int cnt = 0;
    while (left <= mid and right <= high) {
        if (arr[left] * 1LL > arr[right] * 2LL) {
            right++;
        }
        else {
            cnt = cnt + right - mid - 1;
            left++;
        }
    }

    if (left <= mid) {
        cnt = cnt + (mid - left + 1) * (high - mid);
    }

    left = low, right = mid + 1;

    while (left <= mid and right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

// The number of local inversions is the number of indices i where:
// 0 <= i < n - 1
// nums[i] > nums[i + 1]

int countLocalInversion(vector<int>& arr) {
    int n = arr.size();
    long long int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            cnt++;
    }
    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return 0;
    long long int cnt = 0;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int reversePairs(vector<int>& arr) {
    int n = arr.size();
    int cnt = mergeSort(arr, 0, n - 1);

    print(arr);
    cout << cnt << endl;
    return cnt;
}


// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

void solve() {
    int n; cin >> n;
    vector<int>arr(n);

    for (int i = 0;i < n; i++) {
        cin >> arr[i];
    }

    cout << reversePairs(arr) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}