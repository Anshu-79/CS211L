#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left = NULL;
    Node *right = NULL;
    int height = 0;
};

class AVL
{
private:
    Node *getNewNode(int);
    void updateHeight(Node *);

public:
    Node *root = NULL;
    int balanceFactor(Node *);
    Node *LLrotate(Node *);
    Node *RRrotate(Node *);
    Node *RLrotate(Node *);
    Node *LRrotate(Node *);
    Node *insertNode(Node *, int);
    Node *deleteNode(Node *, int);
    Node *findMin(Node *);
    Node *findSuccessor(Node *);
};

Node *AVL::findMin(Node *root)
{
    if (root == NULL)
        return root;
    if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

Node *AVL::findSuccessor(Node *node)
{
    if (node == NULL)
        return node;

    if (node->right != NULL)
        return findMin(node->right);

    Node *successor = NULL;
    Node *parent = root;
    while (parent != node)
    {
        if (node->key < parent->key)
        {
            successor = parent;
            parent = parent->left;
        }
        else
            parent = parent->right;
    }

    return successor;
}

Node *AVL::getNewNode(int x)
{
    Node *node = new Node();
    node->key = x;
    return node;
}

void AVL::updateHeight(Node *z) { z->height = max(z->left->height, z->right->height) + 1; }

int AVL::balanceFactor(Node *node)
{
    return node->left->height - node->right->height;
}

Node *AVL::LLrotate(Node *z)
{
    Node *y = z->left;
    Node *T3 = y->right;
    y->right = z;
    z->left = T3;
    updateHeight(z);
    updateHeight(y);

    return y;
}

Node *AVL::RRrotate(Node *z)
{
    Node *y = z->right;
    Node *T3 = y->left;
    y->left = z;
    z->right = T3;

    updateHeight(z);
    updateHeight(y);

    return y;
}

Node *AVL::LRrotate(Node *z)
{
    z->left = LLrotate(z->left);
    return RRrotate(z);
}

Node *AVL::RLrotate(Node *z)
{
    z->right = RRrotate(z->right);
    return LLrotate(z);
}

Node *AVL::insertNode(Node *root, int key)
{
    if (root == NULL)
        return getNewNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    updateHeight(root);

    int bf = balanceFactor(root);

    if (bf > 1 && root->left->key > key)
        return LLrotate(root);

    if (bf > 1 && root->left->key < key)
        return LRrotate(root);

    if (bf < -1 && root->right->key < key)
        return RRrotate(root);

    if (bf < -1 && root->right->key > key)
        return RLrotate(root);

    return root;
}

Node *AVL::deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->key)
        return deleteNode(root->left, key);
    else if (key > root->key)
        return deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            Node *child = NULL;
            return NULL;
        }

        else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        {
            Node *child = NULL;
            if (root->left != NULL)
                child = root->left;
            else
                child = root->right;
            return child;
        }
        else
        {
            Node *succ = findSuccessor(root);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }

        updateHeight(root);

        int bf = balanceFactor(root);

        if (bf > 1 && balanceFactor(root->left) >= 0)
            return LLrotate(root);

        if (bf > 1 && balanceFactor(root->left) < 0)
            return LRrotate(root);

        if (bf < -1 && balanceFactor(root->right) <= 0)
            return RRrotate(root);

        if (bf < -1 && balanceFactor(root->left) > 0)
            return RLrotate(root);

        return root;
    }
}
