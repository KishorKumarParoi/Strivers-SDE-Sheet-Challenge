// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-25
Time: 15:14:35
Problem: Find Pairs of given sum in Doubly Linked List
Link: https://www.naukri.com/code360/problems/find-pairs-with-given-sum-in-doubly-linked-list_1164172?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries
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
    Node<T>* prev;

public:
    Node(T data1, Node<T>* next1, Node<T>* prev1) {
        this->data = data1;
        this->next = next1;
        this->prev = prev1;
    }
    Node(T data1, Node<T>* next1) {
        this->data = data1;
        this->next = next1;
        this->prev = nullptr;
    }
    Node(T data1, nullptr_t, Node<T>* prev1) {
        this->data = data1;
        this->next = nullptr;
        this->prev = prev1;
    }
    Node(T data1) {
        this->data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node() {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
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
            temp->prev = prev;
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

Node<int>* reverseDoublyLinkedList(Node<int>* head) {
    /*
        Problem : Reversing a Linked List
        Cases:
        1. no element hence return NULL
        2. one element, results into same as previous -> return head
        3. more than one element
          (head)  5 -> 4 -> 3 -> NULL
          NULL <- 5 <- 4 <- 3 (head)
          index:
          i -> 0:
             5->next = 4
             5->prev = null
             5->prev = 4
             5->next = null
          i -> 1:
             4->next = 3
             4->prev = 5
             4->prev = 3
             4->next = 5
          i -> 2:
             3->next = null
             3->prev = 4
             3->prev = null
             3->next = 4
          4. implementation:
            Node<int>*temp = head;
            swap(temp->next, temp->prev)
            temp = temp->prev

    */

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node<int>* current = head;
    Node<int>* temp = NULL;

    while (current) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        // swap(temp->next, temp->prev);
        if (current->prev == NULL) break;
        current = current->prev;
    }

    head = current;
    return head;
}
/**
 * The function `InsertAtKthPosition` inserts a new node with a given value at a specified position in
 * a doubly linked list.
 *
 * @param head The `head` parameter in the `InsertAtKthPosition` function represents the head of a
 * doubly linked list where each node contains an integer value. This function is designed to insert a
 * new node with a specified value at the k-th position in the linked list.
 * @param k The parameter `k` in the `InsertAtKthPosition` function represents the position at which
 * you want to insert a new node with the value `val` in a linked list. It indicates the index
 * (starting from 1) where you want to place the new node.
 * @param val The `val` parameter represents the value that you want to insert into the linked list at
 * position `k`. This value will be stored in a new node that will be inserted at the specified
 * position in the linked list.
 *
 * @return The function `InsertAtKthPosition` returns a pointer to the head of the linked list after
 * inserting a new node with value `val` at the k-th position in the list.
 */

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
            head->prev = temp;
            return temp; //new head
        }
        else if (k == 2) {
            Node<int>* temp = new Node(val);
            head->next = temp;
            temp->prev = head;
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
        newNode->prev = NULL;
        temp->prev = newNode;
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
            newNode->prev = prev;
            prev->next = newNode;
            temp->prev = newNode;
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
        newNode->prev = prev;
        prev->next = newNode;
        temp->prev = newNode;
        return head;
    }

    // insert after last element
    if (k - 1 == cnt) {
        Node<int>* newNode = new Node(val);
        newNode->prev = temp;
        temp->next = newNode;
        return head;
    }

    //  if k > cnt + 1
    return head;
}

/**
 * The function `printDoublyLinkedList` prints the data of each node in a doubly linked list in forward
 * order.
 *
 * @param head The `head` parameter in the `printDoublyLinkedList` function is a pointer to the first
 * node of a doubly linked list containing integer data. The function traverses the linked list
 * starting from the `head` node and prints the data in each node.
 */
void printDoublyLinkedList(Node<int>* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node<int>* deleteAllOccurrences(Node<int>* head, int key) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        if (key == head->data) {
            return NULL;
        }
        return head;
    }

    while (head->data == key) {
        Node<int>* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) {
            // cout << "jdsf" << endl;
            return NULL;
        }
    }


    Node<int>* temp = head;
    Node<int>* prevNode = NULL;
    Node<int>* nextNode = head->next;

    while (temp != NULL) {
        if (temp->data == key) {
            Node<int>* deleteNode = temp;
            temp = nextNode;
            prevNode->next = nextNode;
            if (nextNode != NULL) {
                nextNode->prev = prevNode;
                nextNode = nextNode->next;
            }
            delete deleteNode;
        }
        else {
            prevNode = temp;
            temp = nextNode;
            if (nextNode != NULL)
                nextNode = nextNode->next;
        }
    }

    return head;
}

vector<pair<int, int>> findPairs(Node<int>* head, int target) {
    Node<int>* left = head;
    Node<int>* temp = head;
    Node<int>* right = head;

    while (right->next != NULL) {
        right = right->next;
    }

    // cout << left->data << " " << right->data << endl;
    vector<pair<int, int>>ans;

    while (left->data < right->data) {
        int sum = left->data + right->data;
        // dl(sum);

        if (sum == target) {
            ans.push_back({ left->data, right->data });
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }

    return ans;
}


void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node<int>* head = convertToDoublyLinkedList(arr, n);
    // head = reverseDoublyLinkedList(head);
    printDoublyLinkedList(head);
    // head = deleteKthElement(head, 1);
    // printDoublyLinkedList(head);
    // head = InsertAtKthPosition(head, 2, 100);
    // printDoublyLinkedList(head);
    // head = deleteAllOccurrences(head, 10);
    // printDoublyLinkedList(head);

    vector<pair<int, int>>ans = findPairs(head, 50);

    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}