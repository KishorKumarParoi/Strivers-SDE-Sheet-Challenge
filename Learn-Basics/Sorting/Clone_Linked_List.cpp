// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-30
Time: 18:23:16
Problem: Clone a Linked List
Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
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
    Node<T>* random;

    Node(T data1, Node<T>* next1, Node<T>* random1) {
        this->data = data1;
        this->next = next1;
        this->random = random1;
    }
    Node(T data1) {
        this->data = data1;
        this->next = NULL;
        this->random = NULL;
    }
    Node() {
        this->data = 0;
        this->next = NULL;
        this->random = NULL;
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

Node<int>* insertCopyInBetween(Node<int>* head) {

}

Node<int>* copyRandomList(Node<int>* head) {
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}

Node* cloneLL(Node* head) {
    // TC : O(2N)
    // SC : O(N) + O(N) (this can't be avoid for copy Node)
    unordered_map<Node, Node>mpp;
    Node* temp = head;

    while (temp) {
        mpp[temp] = new Node(temp->data);
        temp = temp->next;
    }

    temp = head;
    Node* copyNode = new Node(-1);
    Node* ansHead = copyNode;

    while (temp) {
        copyNode->next = mpp[temp];
        copyNode = copyNode->next;
        copyNode->next = temp->data;
        copyNode->random = temp->random;
        temp = temp->next;
    }
    return ansHead->next;
}

void solve() {

}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}