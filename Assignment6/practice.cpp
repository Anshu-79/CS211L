#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

class BST
{
private:
    Node *getNewNode(int);

public:
    Node *root = NULL;
    void insertNode(Node *&, int);
    void deleteNode(Node *&, int);
    bool search(Node *, int);
    Node *find(Node *, int);
    Node *findMin(Node *);
    Node *findMax(Node *);
    int findHeight(Node *);
    void levelOrderTraversal(Node *);
    void preOrderTraversal(Node *);
    void inOrderTraversal(Node *);
    void postOrderTraversal(Node *);
    Node *findSuccessor(Node *, Node *);
    Node *findPredecessor(Node *, Node *);
};

Node *BST::findPredecessor(Node *root, Node *node)
{
    if (root == NULL)
        return root;

    if (node == NULL)
        return node;

    if (node->left != NULL)
        return findMax(node->left);

    Node *predecessor = NULL;
    Node *parent = root;

    while (parent != node)
    {
        if (node->data > parent->data)
        {
            predecessor = parent;
            parent = parent->right;
        }
        else
            parent = parent->left;
    }

    return predecessor;
}

Node *BST::findSuccessor(Node *root, Node *node)
{
    if (root == NULL)
        return root;

    if (node == NULL)
        return node;

    if (node->right != NULL)
        return findMin(node->right);

    Node *successor = NULL;
    Node *parent = root;
    while (parent != node)
    {
        if (node->data < parent->data)
        {
            successor = parent;
            parent = parent->left;
        }
        else
            parent = parent->right;
    }

    return successor;
}

void BST::preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void BST::inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void BST::postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    cout << root->data << " ";
}

void BST::levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";

        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);

        Q.pop();
    }
}

Node *BST::getNewNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    return newNode;
}

int BST::findHeight(Node *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void BST::insertNode(Node *&root, int data)
{
    if (root == NULL)
        root = getNewNode(data);
    else if (data <= root->data)
        insertNode(root->left, data);
    else
        insertNode(root->right, data);
}

bool BST::search(Node *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    else if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

Node *BST::find(Node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;
    else if (data < root->data)
        return find(root->left, data);
    else
        return find(root->right, data);
}

Node *BST::findMin(Node *root)
{
    if (root == NULL)
        return root;
    if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

Node *BST::findMax(Node *root)
{
    if (root == NULL)
        return root;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

void BST::deleteNode(Node *&root, int val)
{
    if (root == NULL)
        return;
    else if (val < root->data)
        deleteNode(root->left, val);
    else if (val > root->data)
        deleteNode(root->right, val);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
}

int main()
{
    BST bst;
    bst.insertNode(bst.root, 15);
    bst.insertNode(bst.root, 10);
    bst.insertNode(bst.root, 20);
    bst.insertNode(bst.root, 3);
    bst.insertNode(bst.root, 5);
    bst.insertNode(bst.root, 25);
    bst.insertNode(bst.root, 1);
    bst.insertNode(bst.root, 2);
    bst.insertNode(bst.root, 21);
    bst.insertNode(bst.root, 22);

    cout << bst.search(bst.root, 3) << endl;
    cout << bst.findMin(bst.root)->data << endl;
    cout << bst.findHeight(bst.root) << endl;

    bst.deleteNode(bst.root, 15);
    bst.deleteNode(bst.root, 5);

    bst.preOrderTraversal(bst.root);
    cout << endl;
    bst.inOrderTraversal(bst.root);
    cout << endl;
    bst.postOrderTraversal(bst.root);
    cout << endl;
    bst.levelOrderTraversal(bst.root);
    cout << endl;
}
