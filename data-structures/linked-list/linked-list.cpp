#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node *next;

        Node(int val, Node *n) {
            data = val;
            next = n;
        }

        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;

public:
    void insert(int value) {
        Node *new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            return;
        }

        Node *node = head;
        while (node->next != nullptr) {
            node = node->next;
        }

        node->next = new_node;
    }

    void insert_at(int index, int value) {
        Node *new_node = new Node(value);

        // Insert at head
        if (index == 0) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node *current = head;

        for(int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void traverse() {
        if(head == nullptr) {
            return;
        }

        Node *node = head;
        while(node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }

        cout << endl;
    }

    void reverse_list() {
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;
        Node *next;

        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void reverse_list_using_stack() {
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        stack<int> st;

        Node *curr = head;
        while(curr != nullptr) {
            st.push(curr->data);
            curr = curr->next;
        }

        curr = head;
        while(!st.empty()) {
            curr->data = st.top();
            st.pop();
            curr = curr->next;
        }
    }

    void reverse_sublist(int start, int end) {
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        Node *dummy = new Node(0);
        dummy->next = head;

        Node *pre_node = dummy; // previous node of our current node where it will be in start - 1 index
        Node *curr = head;
        for(int i = 0; i < start-1; i++) {
            pre_node = pre_node->next;
            curr = curr->next;
        }

        Node *head_of_the_sublist = curr;
        Node *prev = nullptr;
        Node *next = nullptr;
        for(int j = 0; j <= end - start; j++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        pre_node->next = prev;
        head_of_the_sublist->next = curr;

        head = dummy->next;
    }

    // remove nth node from the end of list
    void remove_nth_node_from_end(int pos) {
        Node *dummy = new Node(0);
        dummy->next = head;

        Node *first = dummy;
        Node *second = dummy;

        for(int i = 0; i < pos; i++) {
            second = second->next;
        }

        while(second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        first->next = first->next->next;
        head = dummy->next;
    }
};

int main() {
    vector<int> nums = {2, 3, 4, 5, 6, 7, 8};
    LinkedList ll;
    for(int i = 0; i < nums.size(); i++) {
        ll.insert(nums[i]);
    }
    ll.traverse();

    // insert at index
    // ll.insert_at(2, 6);
    // ll.traverse();

    // revere list
    // ll.reverse_list();
    // ll.traverse();

    // reverse list
    // ll.reverse_list_using_stack();
    // ll.traverse();

    // reverse sublist
    // ll.reverse_sublist(2, 6);
    // ll.traverse();

    ll.remove_nth_node_from_end(3);
    ll.traverse();
}