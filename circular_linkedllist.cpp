#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int value): data(value), next (nullptr){
        
    }
};
class Circular{
    private:
        Node* head;
        
    public:
        Circular(): head(nullptr){
            
        }
    
    void append(int data)
    {
        
        Node* newNode = new Node(data);
        if(!head){ //liste boşsa  circular linked list'in tek elemanı olduğunu
        //ifade eden bir döngü oluşturulmuş olur
        head= newNode;    
        head->next = head;}
        else
        {
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next; //son elemanı bulmak için
            }
            temp->next=newNode;
            newNode->next=head;
        }
            
            
    }
    
    
    void remove(int key){
        if (!head){
            return;
        }
        
        Node* temp = head;
        Node* prev = NULL;
        
        //baştaki elemanı silme
        if(temp->data == key) //silinecek eleman listenin başındaysa
        {
            while(temp->next != head)
            {
                temp =temp->next;
            }
            if(head == head->next)
            {
                delete head;
                head = NULL;
                
            }
            else{
                temp->next = head->next;
                Node* tempHead = head;
                head = head->next;
                delete tempHead;
            }
        }
        else // aradan veya sondan eleman silme
        {
            while(temp->next != head && temp->data !=key)
            {
                prev= temp;
                temp = temp->next;
            }
            if (temp->data == key){
                prev->next = temp->next;
                delete temp;
            }
        }
    }
    
    
   void print()
   {
       if(!head)
       {
           return;
       }
       
       Node* temp = head;
       do{
           cout<<temp->data<<" ";
           temp = temp->next;
       }while(temp != head);
       
       cout<<endl;
   }
    
        
    
    
    
    
    
    };
    

using namespace std;

int main()
{
    Circular ci;
    ci.append(1);
    ci.append(2);
    ci.append(3);
    ci.append(4);
    
    ci.print();
    ci.remove(3);
    ci.print();

    return 0;
}
