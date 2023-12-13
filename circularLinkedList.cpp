// circular linkedlist`s implementation

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class circularLinkedList{
    public:
        Node* head;
        Node* tail;

        circularLinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }

        void insertAtEnd(int data){
            Node* newNode = new Node(data);
            if(this->head == NULL){
                this->head = newNode;
                this->tail = newNode;
                this->tail->next = this->head;
            }
            else{
                this->tail->next = newNode;
                this->tail = newNode;
                this->tail->next = this->head;
            }
        }

        void remove(int data){
            if(this->head == NULL){
                cout << "List is empty" << endl;
            }
            else{
                Node* temp = this->head;
                if(this->head->data == data){
                    this->head = this->head->next;
                    this->tail->next = this->head;
                    delete temp;
                }
                else{
                    while(temp->next != this->head){
                        if(temp->next->data == data){
                            Node* temp2 = temp->next;
                            temp->next = temp->next->next;
                            delete temp2;
                            break;
                        }
                        temp = temp->next;
                    }
                }
            }
        }


        Node* search(int data){
            if(this->head == NULL){
                cout << "List is empty" << endl;
                return NULL;
            }
            else{
                Node* temp = this->head;
                while(temp->next != this->head){
                    if(temp->data == data){
                        return temp;
                    }
                    temp = temp->next;
                }
                if(temp->data == data){
                    return temp;
                }
                return NULL;
            }
        }
        
};