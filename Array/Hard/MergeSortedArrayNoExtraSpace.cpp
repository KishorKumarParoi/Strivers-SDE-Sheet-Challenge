// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-13
Time: 08:58:16
Problem: Merge two sorted array without no space
Link: https://leetcode.com/problems/merge-sorted-array/description/
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

void mergeArrays(vector<int>& arr, int low, int mid, int high) {
    int left = low, right = mid + 1;

    // while (left >= 0 and right <= high) {
    //     if (arr[left] > arr[right]) {
    //         swap(arr[left], arr[right]);
    //         left--;
    //         right++;
    //     }
    //     else {
    //         break;
    //     }
    // }

    // sort(arr.begin() + low, arr.begin() + mid + 1);
    // sort(arr.begin() + mid + 1, arr.begin() + high + 1);

    vector<int>temp;
    d(low) d(mid) dl(high);

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

    print(temp);
}

void mergeSort(vector<int>& arr, int low, int high) {
    // 5 4 3 2 1
    // 5 4 3 | 2 1
    // 5 4 | 3
    // 5 | 4
    if (low == high) return;
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeArrays(arr, low, mid, high);
}

void mergeTwoArraysOptimal(vector<int>& arr, int n, vector<int>& brr, int m) {
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = gap;
        while (right < len) {
            // d(left) dl(right);

            if (left < n and right >= n) {
                if (arr[left] > brr[right - n]) {
                    swap(arr[left], brr[right - n]);
                }
                left++, right++;
            }
            else if (left < n and right < n) {
                if (arr[left] > arr[right]) {
                    swap(arr[left], arr[right]);
                }
                left++, right++;
            }
            else {
                if (brr[left - n] > brr[right - n]) {
                    swap(brr[left - n], brr[right - n]);
                }
                left++, right++;
            }
        }

        if (gap == 1)
            break;
        gap = gap / 2 + gap % 2;
    }

    for (int i = n; i < len; i++) {
        arr[i] = brr[i - n];
    }

    print(arr);
}

void merge(vector<int>& arr, int n, vector<int>& brr, int m) {
    int len = n + m;
    for (int i = n; i < arr.size(); i++) {
        arr[i] = brr[i - n];
    }

    int gap = (len / 2) + (len % 2);
    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < len) {
            if (arr[left] > arr[right]) {
                swap(arr[left], arr[right]);
            }
            left++, right++;
        }

        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int>arr = { 1,4,8,10,0,0,0 };
    vector<int>brr = { 2,3,9 };
    merge(arr, n, brr, m);
    print(arr);
    // mergeSort(arr, 0, n - 1)
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}