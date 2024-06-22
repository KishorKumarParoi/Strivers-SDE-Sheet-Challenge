// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-22
Time: 20:21:59
Problem: Check loop in Linked List
Link: https://leetcode.com/problems/linked-list-cycle/
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

template<typename T>

class Node {
public:
    T data;
    Node<T>* next;

    Node(T data1, Node<T>* next1) {
        this->data = data1;
        this->next = next1;
    }
    Node(T data1) {
        this->data = data1;
        this->next = NULL;
    }
    Node() {
        this->data = 0;
        this->next = NULL;
    }
};

Node<int>* LinkedListTraversalFromArray(vector<int>& arr, int n) {
    Node<int>* head = new Node(arr[0]);
    Node<int>* mover = head;

    for (int i = 1; i < n; i++) {
        Node<int>* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLinkedList(Node<int>* head) {
    if (head == NULL) {
        return;
    }

    Node<int>* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node<int>* reverseLinkedList(Node<int>* head) {
    Node<int>* temp = head;
    Node<int>* prev = NULL;

    while (temp) {
        Node<int>* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

bool hasCycle(Node<int>* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    Node<int>* slow = head;
    Node<int>* fast = head;

    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

int lenght(Node<int>* slow, Node<int>* fast) {
    int cnt = 1;
    fast = fast->next;
    while (fast != slow) {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node<int>* head) {
    // Write your code here
    if (head == NULL || head->next == NULL) {
        return 0;
    }

    Node<int>* slow = head;
    Node<int>* fast = head;

    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return lenght(slow, fast);
        }
    }



    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n)

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

    Node<int>* headA = LinkedListTraversalFromArray(arr, n);
    printLinkedList(head);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}