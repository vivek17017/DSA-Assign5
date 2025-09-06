#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};

class DLL{
private:
    node *start;
public:
    DLL();
    ~DLL(){
    while (start!=nullptr)
    {
        deleteFirstNode();
    }   
}
    void insertDataAtBeginning(int);
    void insertDataAtEnd(int);
    node* searchNodeWithItem(int);
    void insertDataAfter(node*,int);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(node*);

};

DLL::DLL(){
    start=nullptr;
}

void DLL::insertDataAtBeginning(int data){
        node *temp=new node;
        temp->prev=nullptr;
        temp->item=data;
        temp->next=start;
        if(start!=nullptr)
            start->prev=temp;
        start=temp;
}
void DLL::insertDataAtEnd(int data){
     node *temp=new node;
     node *t;
    temp->item=data;
    temp->next=nullptr;
    if(start==nullptr){
       
        temp->prev=nullptr;
        start=temp;
    }
    else{
        t=start;
        while (t->next!=nullptr)
        {
            t=t->next;
        }
        temp->prev=t;
        t->next=temp;
    }

}
node* DLL::searchNodeWithItem(int data){
    node *t=start;
    while (t!=nullptr)
    {
        if(t->item==data)
        return t;
        t=t->next;
    }
    return nullptr;
    
}
void DLL::insertDataAfter(node* temp,int data){
    if(temp!=nullptr){
        node* t=start;
        while (t!=nullptr)
        {
            if(t==temp)
            break;
            t=t->next;
        }
        if(t==nullptr)
            cout<<"invalid node";
        else
        {
            t=new node;
            t->next=temp->next;
            t->item=data;
            t->prev=temp;
            if(temp->next!=nullptr)
             temp->next->prev=t;
            temp->next=t;
        }
        
    }
    
}
void DLL::deleteFirstNode(){
    if(start!=nullptr){
        if(start->next=nullptr)
            {
                delete start;
                start=nullptr;
            }
        else
        {
            node* temp=start;
            start->next->prev=nullptr;
            start=temp->next;
            delete temp;
        }
    }
}
void DLL::deleteLastNode(){
    if(start!=nullptr){
        node* t=start;
         if(start->next==nullptr){
                    delete start;
                    start=nullptr;
                }
        else{
        while (t->next->next!=nullptr)
        {
            t=t->next;
        }
        delete t->next;
        t->next=nullptr;
    }
        
    }
}
void DLL::deleteSpecificNode(node* temp){
    if(start!=nullptr){
        node *t=searchNodeWithItem(temp->item);
        if(t==temp){
            t=start;
            if(temp==start){
                deleteFirstNode();
            }
            else if(temp->next==nullptr){
                deleteLastNode();
            }
            else{
        while (t->next!=temp)
        {
            t=t->next;
        }
        t->next->next->prev=t;
        t->next=t->next->next;
        delete temp;
 
            }

        }
    }
}

int main(){
    DLL d;
    d.insertDataAtBeginning(4);
    d.insertDataAtBeginning(3);
    d.insertDataAtEnd(5);
    cout<<endl;
    cout<<d.searchNodeWithItem(5)<<endl;
}