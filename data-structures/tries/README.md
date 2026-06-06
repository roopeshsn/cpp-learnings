# Trie

## Trie to store strings or words

```
struct Node {
    Node *links[26];
    int is_last = false;
}
```

The only difference is that in Binary Search Trees, we saw that the root node or any descendant nodes will point to left and right nodes. But here we are storing nodes in an array so now every node is pointing to 26 nodes at max.