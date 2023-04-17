#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

struct Node {
    Student data;
    Node* left;
    Node* right;
};

class STUDENTBST {
public:
    Node* root;

    STUDENTBST() {
        root = NULL;
    }

    Node* createNode(Student student) {
        Node* newNode = new Node();
        newNode->data = student;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    Node* insert(Node* root, Student student) {
        if (root == NULL) {
            root = createNode(student);
        }
        else if (student.id < root->data.id) {
            root->left = insert(root->left, student);
        }
        else if (student.id > root->data.id) {
            root->right = insert(root->right, student);
        }
        return root;
    }

    Node* search(Node* root, int id) {
        if (root == NULL || root->data.id == id) {
            return root;
        }
        else if (id < root->data.id) {
            return search(root->left, id);
        }
    
        else {
            return search(root->right, id);
        }
    }

    void printStudent(Node* node) {
        cout << "ID: " << node->data.id << endl;
        cout << "Name: " << node->data.name << endl;
        cout << "CGPA: " << node->data.cgpa << endl;
    }

};

int main() {
    STUDENTBST* studentbst = new STUDENTBST();
    Node* root = studentbst->root; 

    root = studentbst->insert(root, { 1, "Shafayet", 3.6 });
    root = studentbst->insert(root, { 2, "Abir", 3.8 });
    root = studentbst->insert(root, { 3, "John Cena", 3.7 });
    
    Node* found = studentbst->search(root, 3);
    if (found != NULL) {
        studentbst->printStudent(found);
    }
    else {
        cout << "Student not found." << endl;
    }
    
    return 0;
}
