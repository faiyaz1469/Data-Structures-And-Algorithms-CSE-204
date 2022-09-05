#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(){

    }

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinarySearchTree
{

private:
    Node *root;
public:
    BinarySearchTree() { root = NULL;} // constructor

private:

    // insertItem method
    Node* insertItem(Node *cursor, int x)
    {
        if(cursor == NULL)
        {
            Node* newItem = new Node(x);
            cursor = newItem;
        }

        else if(x < cursor->data)
            cursor->left = insertItem(cursor->left, x);

        else if(x > cursor->data)
            cursor->right = insertItem(cursor->right, x);

        return cursor;
    }

    // searchItem method
    bool searchItem(Node *cursor, int x)
    {
        if(cursor == NULL) return false;
        else if(x < cursor->data) return searchItem(cursor->left, x);
        else if(x > cursor->data) return searchItem(cursor->right, x);
        else if(x == cursor->data) return true;
        else return false;

    }

    // getMinItem method
    Node* getMinItem(Node *cursor)
    {
        if(cursor == NULL) return NULL;
        while(cursor->left != NULL)
            cursor = cursor->left;
        return cursor;
    }

    // getMaxItem method
    Node* getMaxItem(Node *cursor)
    {
        if(cursor == NULL) return NULL;

        while(cursor->right != NULL)
            cursor = cursor->right;
        return cursor;
    }

    // deleteItem method
    Node* deleteItem(Node *cursor, int x)
    {
        Node *temp;

        // if tree is empty, nothing to delete
        if(cursor == NULL)
            return NULL;

        else if(x < cursor->data)
            cursor->left = deleteItem(cursor->left, x);

        else if(x > cursor->data)
            cursor->right = deleteItem(cursor->right, x);

        else if(x == cursor->data)
        {
            /// CASE 1: node is leaf
            if(cursor->left == NULL && cursor->right == NULL)
            {
                delete cursor;
                return NULL;
            }

            /// CASE 2.1: node has just right child (one child)
            else if(cursor->left == NULL)
            {
                temp = cursor->right;
                delete cursor;
                return temp;
            }

            /// CASE 2.2: node has just left child (left child)
            else if(cursor->right == NULL)
            {
                temp = cursor->left;
                delete cursor;
                return temp;
            }

            /// CASE 3: node has two children (both left and right children)
            /*temp = getMinItem(cursor->right);
            cursor->data = temp->data;
            cursor->right = deleteItem(cursor->right, temp->data);*/

            temp = getMaxItem(cursor->left);
            cursor->data = temp->data;
            cursor->left = deleteItem(cursor->left, temp->data);
        }
        return cursor;
    }

    // printPreOrder method
    void printPreOrder(Node *cursor)
    {
        if(cursor == NULL) return;

        cout<< cursor->data <<" ";
        printPreOrder(cursor->left);
        printPreOrder(cursor->right);
    }

    // printInOrder method
    void printInOrder(Node *cursor)
    {
        if(cursor == NULL) return;

        printInOrder(cursor->left);
        cout<< cursor->data <<" ";
        printInOrder(cursor->right);
    }

    // printPostOrder method
    void printPostOrder(Node *cursor)
    {
        if(cursor == NULL) return;

        printPostOrder(cursor->left);
        printPostOrder(cursor->right);
        cout<< cursor->data <<" ";
    }

    //print bst state
    void printTree(Node *cursor)
    {
        if(cursor == NULL) return;

        cout<<cursor->data;

        if (!cursor->left && !cursor->right)
        return;

        cout<<"(";
        printTree(cursor->left);
        cout<<")";

        cout<<"(";
        printTree(cursor->right);
        cout<<")";
    }

public:

    // insertItem method overloaded
    void insertItem(int x)
    {
        root = insertItem(root, x);
        printTree(root);
        cout<<endl;
        //cout<<endl;
    }

    void findItem(int x)
    {
        bool found = searchItem(root, x);
        if(found == true) cout<<"True"<<endl;
        else if(found == false) cout<<"False"<<endl;
    }

    // deleteItem method overloaded
    void deleteItem(int x)
    {
        if(searchItem(root, x) == false)
        {
            cout<<"Invalid Operation"<<endl;
            return;
        }

        root = deleteItem(root,x);
        printTree(root);
        cout<<endl;
        //cout<<endl;
    }

    // printPreOrder method Overloaded
    void printPreOrder()
    {
        if (root != NULL)
            printPreOrder(root);
        else
            cout<<"No item in BST";
    }

    // printInOrder method Overloaded
    void printInOrder()
    {
        if (root != NULL)
            printInOrder(root);
        else
            cout<<"No item in BST";
    }

    // printPostOrder method Overloaded
    void printPostOrder()
    {
        if (root != NULL)
            printPostOrder(root);
        else
            cout<<"No item in BST";
    }

    void printTree()
    {
        printTree(root);
        cout<<endl;
    }

    Node* getRoot() { return root;}
};


