// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-22
Time: 13:46:36
Problem: Add One to number represented with Linked List
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

bool isPalindrome(Node<int>* head) {
    // find middle element first
    Node<int>* slow = head;
    Node<int>* fast = head;

    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // now reverse from the slow pointer to end
    Node<int>* prev = NULL;
    Node<int>* temp = slow;

    while (temp) {
        Node<int>* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    //      3 -> 2 -> 1 -> x
    // x <- 3 <- 2 <- 1 <- x
    // prev at 1
    // slow at NULL

    slow = prev; // points at 1
    // now traverse from 1 -> 3

    temp = head;
    while (slow != NULL) {
        if (temp->data != slow->data) {
            return 0;
        }
        slow = slow->next;
        temp = temp->next;
    }

    return 1;
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

Node<int>* recursiveReverseLinkedList(Node<int>* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node<int>* newHead = recursiveReverseLinkedList(head->next);

    // fun part of recursion
    Node<int>* front = head->next;
    head->next = NULL;
    front->next = head;

    return newHead;
}

int addHelper(Node<int>* temp) {
    // Time Complexity : O(N)
    // Space Complexity : O(N)

    if (temp == NULL)
        return 9;

    int carry = addHelper(temp->next);
    int sum = temp->data + carry;
    temp->data = sum % 10;
    return sum / 10;
}

Node<int>* recursiveAddOne(Node<int>* head) {
    // ultimate carry
    int carry = addHelper(head);
    if (carry) {
        Node<int>* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}



Node<int>* AddOne(Node<int>* head) {
    // time complexity : O(3N)
    // space complexity : O(1)

    Node<int>* reverseHead = reverseLinkedList(head);
    Node<int>* temp = reverseHead;
    Node<int>* ans = new Node(-1LL);

    int sum = (temp->data + 1);
    int carry = sum / 10;
    sum = sum % 10;
    ans->next = new Node(sum);
    ans = ans->next;
    temp = temp->next;
    // cout << carry << " " << sum << endl;
    Node<int>* ansHead = ans;

    while (temp) {
        sum = temp->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        // cout << carry << " " << sum << endl;
        ans->next = new Node(sum);
        ans = ans->next;
        temp = temp->next;
    }

    if (carry) {
        ans->next = new Node(carry);
        ans = ans->next;
    }
    return ansHead;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node<int>* head = LinkedListTraversalFromArray(arr, n);
    head = recursiveAddOne(head);
    printLinkedList(head);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}