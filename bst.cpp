#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{
    public:
        Node* root;

        BST(){
            this->root = NULL;
        }

        Node* search(int data){
            if(this->root == NULL){
                return NULL;
            }
            Node* curr = this->root;
            while(curr){
                if(curr->data == data){
                    return curr;
                }
                else if(curr->data > data){
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                }
            }
            return NULL;
        }

        void insert(int data){
            Node* newNode = new Node(data);
            if(this->root == NULL){
                this->root = newNode;
                return;
            }
            Node* curr = this->root;
            while(curr){
                if(curr->data > data){
                    if(curr->left == NULL){
                        curr->left = newNode;
                        return;
                    }
                    curr = curr->left;
                }
                else{
                    if(curr->right == NULL){
                        curr->right = newNode;
                        return;
                    }
                    curr = curr->right;
                }
            }
        }

        void remove(int data){
            if(this->root == NULL){
                return;
            }
            Node* curr = this->root;
            Node* parent = NULL;
            while(curr){
                if(curr->data == data){
                    break;
                }
                else if(curr->data > data){
                    parent = curr;
                    curr = curr->left;
                }
                else{
                    parent = curr;
                    curr = curr->right;
                }
            }
            if(curr == NULL){
                return;
            }
            if(curr->left == NULL && curr->right == NULL){
                if(parent == NULL){
                    this->root = NULL;
                }
                else if(parent->left == curr){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
                delete curr;
            }
            else if(curr->left == NULL){
                if(parent == NULL){
                    this->root = curr->right;
                }
                else if(parent->left == curr){
                    parent->left = curr->right;
                }
                else{
                    parent->right = curr->right;
                }
                delete curr;
            }
            else if(curr->right == NULL){
                if(parent == NULL){
                    this->root = curr->left;
                }
                else if(parent->left == curr){
                    parent->left = curr->left;
                }
                else{
                    parent->right = curr->left;
                }
                delete curr;
            }
            else{
                Node* temp = curr->right;
                Node* tempParent = curr;
                while(temp->left){
                    tempParent = temp;
                    temp = temp->left;
                }
                curr->data = temp->data;
                if(tempParent->left == temp){
                    tempParent->left = temp->right;
                }
                else{
                    tempParent->right = temp->right;
                }
                delete temp;
            }
        }

        void inorder(Node* curr){
            if(curr == NULL){
                return;
            }
            inorder(curr->left);
            cout << curr->data << " ";
            inorder(curr->right);
        }

        void preorder(Node* curr){
            if(curr == NULL){
                return;
            }
            cout << curr->data << " ";
            preorder(curr->left);
            preorder(curr->right);
        }

        void postorder(Node* curr){
            if(curr == NULL){
                return;
            }
            postorder(curr->left);
            postorder(curr->right);
            cout << curr->data << " ";
        }



};

int main() {
    BST* bst = new BST();
    bst->insert(5);
    bst->insert(3);
    bst->insert(7);
    bst->insert(2);
    bst->insert(4);
    bst->insert(6);
    bst->insert(8);
    bst->insert(1);
    bst->insert(9);
    bst->insert(10);
    bst->insert(11);

    bst->inorder(bst->root);
    cout << endl;
    bst->preorder(bst->root);
    cout << endl;
    bst->postorder(bst->root);
    cout << endl;

    bst->remove(5);
    bst->inorder(bst->root);
    cout << endl;

    bst->remove(3);
    bst->inorder(bst->root);
    cout << endl;

    bst->search(7);
    return 0;
}