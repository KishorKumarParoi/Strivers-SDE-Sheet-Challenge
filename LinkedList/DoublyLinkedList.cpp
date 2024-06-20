// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-19
Time: 23:54:47
Problem: Doubly Linked List
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

template <typename T>

class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* back;

public:
    Node(T data1, Node<T>* next1, Node<T>* back1) {
        this->data = data1;
        this->next = next1;
        this->back = back1;
    }
    Node(T data1, Node<T>* next1) {
        this->data = data1;
        this->next = next1;
        this->back = nullptr;
    }
    Node(T data1, nullptr_t, Node<T>* back1) {
        this->data = data1;
        this->next = nullptr;
        this->back = back1;
    }
    Node(T data1) {
        this->data = data1;
        this->next = nullptr;
        this->back = nullptr;
    }
    Node() {
        this->data = 0;
        this->next = nullptr;
        this->back = nullptr;
    }

};

Node<int>* deleteKthElement(Node<int>* head, int k) {
    /* Cases:
       1. no element (return NULL)
       2. only single element
          1. k == 1 -> return NULL after deleting head
          2. k >= 2 -> return head
       3. more than one element
          1. delete at last position -> return head as it is
          2. delete at first position -> change head to head->next
          3. delete at middle positiion -> change temp and prev node

       *** k could be minus and more than length of linkedlist
    */

    // if there is no element
    if (head == NULL || k < 0) {
        return NULL;
    }

    // if there is only one element
    if (head->next == NULL) {
        if (k == 1) {
            delete head;
            return NULL;
        }
        else {
            return head;
        }
    }

    // if there is more than one element

    // at first position
    if (k == 1) {
        Node<int>* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // at middle position

    int cnt = 1;
    Node<int>* temp = head;
    Node<int>* prev = NULL;

    while (temp->next != NULL) {
        if (cnt < k) {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        else if (cnt == k) {
            Node<int>* toBeDeletedNode = temp;
            prev->next = temp->next;
            temp = temp->next;
            temp->back = prev;
            delete toBeDeletedNode;
            return head;
        }
    }

    // last element to be deleted
    if (cnt == k) {
        prev->next = NULL;
        delete temp;
    }

    // if k is greater than length
    // returns at it is

    return head;
}

Node<int>* convertToDoublyLinkedList(vector<int>& arr, int n) {
    Node<int>* head = new Node(arr[0]);
    Node<int>* prev = head;

    for (int i = 1; i < n; i++) {
        Node<int>* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node<int>* InsertAtKthPosition(Node<int>* head, int k, int val) {
    /* Cases:
       1. no element (k == 1, k > 1)
       2. only single element (k == 1, k == 2, k > 2)
       3. more than one element
          1. insert at before first pos (k = 1)
          2. insert after last pos (k = length + 1, k > length + 1)
          3. insert at middle (k = 1...length)
    */

    // if there is no element
    if (head == NULL) {
        // if k = 1 then returns New Node 
        if (k == 1) {
            head = new Node(val);
        }
        // else it is impossible as i.e. k=3 impossible
        return head;
    }

    // if there is only one element
    if (head->next == NULL) {
        if (k == 1) {
            Node<int>* temp = new Node(val);
            temp->next = head;
            head->back = temp;
            return temp; //new head
        }
        else if (k == 2) {
            Node<int>* temp = new Node(val);
            head->next = temp;
            temp->back = head;
            return head;
        }
        else {
            return head;
        }
    }

    // if there is more than one element
    int cnt = 1;
    Node<int>* temp = head;
    Node<int>* prev = NULL;

    // beginning insertion
    if (k == 1) {
        Node<int>* newNode = new Node(val);
        newNode->next = temp;
        newNode->back = NULL;
        temp->back = newNode;
        return newNode;
    }

    while (temp->next != NULL) {
        if (cnt < k) {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        else if (cnt == k) {
            Node<int>* newNode = new Node(val);
            newNode->next = temp;
            newNode->back = prev;
            prev->next = newNode;
            temp->back = newNode;
            return head;
        }
    }

    // cout << temp->data << " " << temp->next << endl;
    // cout << prev->data << " " << prev->next << endl;

    d(cnt) dl(k);
    // insert before last element
    if (k == cnt) {
        Node<int>* newNode = new Node(val);
        newNode->next = temp;
        newNode->back = prev;
        prev->next = newNode;
        temp->back = newNode;
        return head;
    }

    // insert after last element
    if (k - 1 == cnt) {
        Node<int>* newNode = new Node(val);
        newNode->back = temp;
        temp->next = newNode;
        return head;
    }

    //  if k > cnt + 1
    return head;
}

void printDoublyLinkedList(Node<int>* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node<int>* head = convertToDoublyLinkedList(arr, n);
    printDoublyLinkedList(head);
    head = deleteKthElement(head, 1);
    printDoublyLinkedList(head);
    head = InsertAtKthPosition(head, 2, 100);
    printDoublyLinkedList(head);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}