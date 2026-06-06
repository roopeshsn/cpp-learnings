#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Tree {
private:
    struct Node {
        int data;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }

        // Node(int val) : data(val), left(nullptr), right(nullptr) {}

        // Node(int val) : data(val) {}
    };

    Node *root = nullptr;

    void clear(Node *node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void inorder_traversal(Node *node) {
        if(node == nullptr) {
            return;
        }
        inorder_traversal(node->left);
        cout << node->data << " ";
        inorder_traversal(node->right);
    }
public:
    Tree() {
        root = nullptr;
    }

    // Tree() : root = nullptr {}

    ~Tree() {
        clear(root);
    }

    void insert(int value) {
        Node *new_node = new Node(value);
        if(root == nullptr) {
            root = new_node;
            return;
        }

        Node *current = root;

        while(true) {
            if(value < current->data) {
                if(current->left == nullptr) {
                    current->left = new_node;
                    break;
                }
                current = current->left;
            } else {
                if(current->right == nullptr) {
                    current->right = new_node;
                    break;
                }
                current = current->right;
            }
        }
    }

    void level_order_traversal() {
        if(root == nullptr) {
            return;
        }
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node *current = q.front();
            q.pop();

            cout << current->data << " ";

            if(current->left != nullptr) {
                q.push(current->left);
            }

            if(current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }

    void inorder_traversal() {
        inorder_traversal(root);
        cout << endl;
    }

    void inorder_traversal_iterative() {
        if(root == nullptr) {
            return;
        }
        stack<Node*> st;
        Node *node = root;

        while(true) {
            if(node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                if(st.empty() == true) {
                    break;
                }
                node = st.top();
                st.pop();
                cout << node->data << " ";
                node = node->right;
            }
        }

        cout << endl;
        return;
    }

    bool search(int value) {
        Node *node = root;

        if(node == nullptr) {
            return true;
        }

        while(node != nullptr) {
            if(value == node->data) {
                return 1;
            } else if (value < node->data){
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return false;
    }
};

int main() {
    Tree tree;
    tree.insert(10);
    tree.insert(21);
    tree.insert(3);
    tree.insert(15);
    tree.insert(23);
    tree.level_order_traversal();
    tree.inorder_traversal();
    tree.inorder_traversal_iterative();
}

