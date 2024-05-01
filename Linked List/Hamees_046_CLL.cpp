#include<iostream>
#include<stdlib.h>
using namespace std;
struct Record {
    int rollNo;
    float CGPA;
    Record* next;
};

Record *head = NULL;

void count(){
    int  count=0;
if(head==nullptr){
    cout<<"there is no entry"<<endl;
}
Record *curr= head;
if(curr== head){
    count++;
}
    curr=curr->next;
while (curr!= head)
{

    count++;
   
    curr=curr->next;
}
 cout<<"Total count is:"<<count<< endl;


}

void index(){
      int toSearch;
    cout << "Enter Roll no you want to Search : ";
    cin >> toSearch;
    int  index=0;
if(head==NULL){

    cout<<"there is no entry"<<endl;
}
else if((head)->rollNo==toSearch){
    index=0;
    cout<<"index of head is"<<index<<endl;
}
Record *curr=head->next;
while (curr!= head)
{
    index++;
if(curr->rollNo==toSearch){

 

cout<<"your roll no. index is:"<<index<<endl;

}

curr=curr->next;

   
   
    
}



}

void insert(){

// Step # 1 Memory Allocation

Record *ptr =(Record*)malloc(sizeof(Record));


// Step # 2 Value Assigning
cout << "Enter your Roll No. : " << endl;

cin >> ptr-> rollNo;

cout << "Enter your CGPA : " << endl;

cin >> ptr-> CGPA;

ptr->next = NULL;

// Step # 3 Inserting Values

if(head == NULL){

head = ptr;
head->next = head;

}

else{

Record *curr = head;

while(curr->next != head){

curr = curr-> next;

}
curr->next = ptr;
ptr->next = head;

}


}


void SortedInsert(){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "Enter Roll no of the Student : ";
    cin >> ptr->rollNo;
    cout << "Enter CGPA of Student : ";
    cin >> ptr->CGPA;

    if (head == NULL){
       
        head = ptr;
        ptr->next = head;
       
    }
  
    else if((head)->rollNo >= ptr->rollNo){

           ptr->next = head;
           Record *last = head;

    while(last->next != head){
         last = last->next;
     }

     last->next = ptr;
     head = ptr;



}

else{

Record *curr = head;

while(curr->next != head && curr->next->rollNo < ptr->rollNo){

curr = curr->next;

}

ptr->next = curr->next;
curr->next = ptr;


}

    
}

void search (){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    int toSearch;
    cout << "Enter Roll no you want to Search : ";
    cin >> toSearch;
    if ((head)->rollNo == toSearch){
        cout << "CGPA of Student is " << (head)->CGPA << endl;
        return;
    }
    Record* curr = (head)->next;
    while (curr != head){
        if (curr->rollNo == toSearch){
            cout << "CGPA of the student is " << curr->CGPA << endl;
            return;
        }
        curr = curr->next;
    }
    if (curr == head){
        cout << "Roll no not Found in the List" << endl;
    }
}

void print (){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    if (head == (head)->next){
        cout << "CGPA of Roll no "<<(head)->rollNo<< " is "<<(head)->CGPA<< endl;
        return;
    }
    Record* curr = head;
    do {
        cout << "CGPA of Roll no "<<curr->rollNo<< " is "<<curr->CGPA<< endl;
        curr = curr->next;
    } while (curr != head);
}

void deleteElement (){
    if (head == NULL){
        cout << "List is Empty "<< endl;
        return;
    }
    int toDelete;
    cout << "Enter Roll no of Student which you want to Delete : ";
    cin >> toDelete;
    if ((head)->next == head){
        if ((head)->rollNo == toDelete){
            free(head);
            head = NULL;
            cout << "Deleted Successfully"<< endl;
        } else {
            cout << "Roll no not Found in the List"<<endl;
        }
        return;
    } 
    Record* last = head;
    while (last->next != head){
        last = last->next;
    }
    Record* curr = head;
    if (toDelete == (head)->rollNo){
        head = (head)->next;
        free(curr);
        last->next = head;
        cout << "Deleted successfully  " << endl;
        return;
    }
    Record* prev = head;
    curr = prev->next;
    while(curr != head){
        if (curr->rollNo == toDelete){
            prev->next = curr->next;
            free(curr);
            cout << "Deleted successfully  " << endl;
            return;
        }
        prev = prev->next;
        curr = curr->next;
    }
    if (curr == head){
        cout << "Roll no Not found in the List"<<endl;
    }
}

void deleteList (){
    if (head == NULL){
        cout << "List is empty " << endl;
        return;
    }
    if (head->next == head){
        free(head);
        head = NULL;
        cout << "Whole List Deleted "<<endl;
        return;
    }
    Record* last = head;
    while (last->next != head){
        last = last->next;
    }
    Record* curr = head;
    while (head != last){
        head = (head)->next;
        free(curr);
        curr = head;
    }
    free(head);
    head = NULL;
    cout << "Whole List deleted"<<endl;
}

int main (){

    int n;
    do {
        cout << "Enter 1 to Insert data " << endl << "Enter 2 to search data " << endl << "Enter 3 to print all Records" << endl << "Enter 4 to Delete a Record " << endl << "Enter 5 to Delete whole List " << endl << "Enter 6 to count" << endl << "Enter 7 to check index" << endl << "Enter 8 to Sort The Linked List" << endl << "Enter 9 to Quit The Program" << endl;
        cin >> n;
        if (n == 1){
            insert ();
        } else if (n == 2){
            search ();
        } else if (n == 3){
            print();
        }  else if (n == 4){
            deleteElement();
        } else if (n == 5){
            deleteList();
        }
        else if (n == 6){
            count();
        }
         else if (n == 7){
            index();
        }
           else if (n == 8){
            SortedInsert();
        }
    } while (n != 9);
}