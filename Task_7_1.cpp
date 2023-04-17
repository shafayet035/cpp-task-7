#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
public:
    Node *root;

    Node *createNode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            root = createNode(data);
        }
        else if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }

    void preorder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postOrder(Node *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }

    void inOrder(Node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    Node *search(Node *root, int data)
    {
        if (root == NULL || root->data == data)
        {
            return root;
        }
        else if (data < root->data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }

    Node *deleteNode(Node *root, int data) {
        if (root == NULL) {
            return root;
        } else if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            if (root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            } else if (root->left == NULL) {
                Node *temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == NULL) {
                Node *temp = root;
                root = root->left;
                delete temp;
            } else {
                Node *temp = root->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }
};

int main()
{
    BST *bst = new BST();
    Node *root = bst->root;

    cout << "\nBinary Search Tree Operations:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Inorder Traversal" << endl;
    cout << "3. Preorder Traversal" << endl;
    cout << "4. Postorder Traversal" << endl;
    cout << "5. Search" << endl;
    cout << "6. Delete" << endl;
    cout << "7. Exit" << endl;

    int choice, num;
    do
    {
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the number to be inserted: ";
            cin >> num;
            root = bst->insert(root, num);
            break;
        }

        case 2:
        {
            cout << "Inorder Traversal: ";
            bst->inOrder(root);
            cout << endl;
            break;
        }

        case 3:
        {
            cout << "Preorder Traversal: ";
            bst->preorder(root);
            cout << endl;
            break;
        }

        case 4:
        {
            cout << "Postorder Traversal: ";
            bst->postOrder(root);
            cout << endl;
            break;
        }

        case 5:
        {
            cout << "Enter the number to be searched: ";
            cin >> num;
            Node *result = bst->search(root, num);
            if (result == NULL)
                cout << "not found in the BST.\n";
            else
                cout << "found in the BST.\n";
            break;
        }
        case 6:
        {
            cout << "Enter the number to be deleted: ";
            cin >> num;
            bst->root = bst->deleteNode(root, num);
            break;
        }

        case 7:
        {
            cout << "Terminate";
            break;
        }

        default:
            cout << "Invalid choice. Please enter a valid choice.\n";
        }
    } while (choice != 7);

    return 0;
}