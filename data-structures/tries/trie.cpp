#include<iostream>

using namespace std;

class Trie {
private:
    struct Node {
        Node *links[26];
        bool is_last = false;

        Node() {
            for(int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }

        bool contains(char ch) {
            return (links[ch - 'a'] != nullptr);
        }
    };

    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *current = root;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(!current->contains(ch)) {
                current->links[ch - 'a'] = new Node();
            }
            current = current->links[ch - 'a'];
        }

        current->is_last = true;
    }

    bool search(string word) {
        Node *current = root;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(current->contains(ch)) {
                current = current->links[ch - 'a'];
            } else {
                return false;
            }
        }

        return current->is_last;
    }

    void dfs(Node* node, string currentWord, vector<string>& result) {
        if(node->is_last) {
            result.push_back(currentWord);
        }
        for(int i = 0; i < 26; i++) {
            if(node->links[i] != nullptr) {
                dfs(node->links[i], currentWord + char('a' + i), result);
            }
        }
    }

    vector<string> all_words_starts_with(string prefix) {
        Node *current = root;
        for(int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if(current->links[ch-'a'] != nullptr) {
                current = current->links[ch-'a'];
                cout << ch << " " << ch-'a' << endl;
            }
        }
        vector<string> result;
        dfs(current, prefix, result);
        return result;
    }

    vector<string> all_words_starts_with_dfs_iterative(string prefix) {
        Node *current = root;
        for(int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if(current->links[ch-'a'] != nullptr) {
                current = current->links[ch-'a'];
                cout << ch << " " << ch-'a' << endl;
            }
        }
        vector<string> result;
        stack<pair<Node*, string>> st;
        st.push({current, prefix});

        while(!st.empty()) {
            auto[node, word] = st.top();
            st.pop();

            if(node->is_last) {
                result.push_back(word);
            }

            for(int i = 0; i < 26; i++) {
                if(node->links[i] != nullptr) {
                    st.push({node->links[i], word + char('a' + i)});
                }
            }
        }

        return result;
    }

    vector<string> all_words_starts_with_bfs(string prefix) {
        Node *current = root;
        for(int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if(current->links[ch-'a'] != nullptr) {
                current = current->links[ch-'a'];
                cout << ch << " " << ch-'a' << endl;
            }
        }
        vector<string> result;
        queue<pair<Node*, string>> q;
        q.push({current, prefix});

        while(!q.empty()) {
            auto[node, word] = q.front();
            q.pop();

            if(node->is_last) {
                result.push_back(word);
            }

            for(int i = 0; i < 26; i++) {
                if(node->links[i] != nullptr) {
                    q.push({node->links[i], word + char('a' + i)});
                }
            }
        }

        return result;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("ape");
    trie.insert("app");
    trie.insert("aero");
    trie.insert("apache");
    trie.insert("aplain");
    trie.insert("banana");

    cout << trie.search("apple") << endl;
    cout << trie.search("bat") << endl;

    // vector<string> res = trie.all_words_starts_with("ap");
    // vector<string> res = trie.all_words_starts_with_dfs_iterative("ap");
    vector<string> res = trie.all_words_starts_with_bfs("ap");
    for(string word : res) {
        cout << word << endl;
    }
}