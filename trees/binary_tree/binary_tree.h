#ifndef BINARY_TREE
#define BINARY_TREE

class BinaryTree
{
public:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

private:
    Node *root;

public:
    BinaryTree();
    ~BinaryTree();

    void deconstruct_tree(Node *root);

    Node *get_root() const;

    void inorderTraversal(Node *root) const;
    void preorderTraversal(Node *root) const;
    void postorderTraversal(Node *root) const;

    void insert_root(int value);
    void insert_left(Node *parent, int value);
    void insert_right(Node *parent, int value);
    void delete_left(Node *parent); // only for leaf nodes
    void delete_right(Node *parent);
};

#endif