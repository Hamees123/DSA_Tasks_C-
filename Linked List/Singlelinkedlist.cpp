#include<iostream>
using namespace std;




struct Record {
    int rollNo;
    float CGPA;
    Record* next;
};
  
Record* head = NULL;

void count(){
    int  count=0;
if(head==nullptr){
    cout<<"there is no entry"<<endl;
}

Record *curr=head;
while (curr!=nullptr)
{
    count++;
   
    curr=curr->next;
}
 cout<<"Total count is:"<<count<< endl;


}
// void sortedinsert(){

// if(head==nullptr){

//     cout<<"there is no entry"<<endl;
// }

// Record *curr=head;
// while (curr!=nullptr)
// {

 
// curr=curr->next;

   
   
    
// }



// }

void index(){
      int toSearch;
    cout << "Enter Roll no you want to Search : ";
    cin >> toSearch;
    int  index=0;
if(head==nullptr){

    cout<<"there is no entry"<<endl;
}
else if(head->rollNo==toSearch){
    index=0;
    cout<<"index of head is"<<index<<endl;
}
Record *curr=head->next;
while (curr!=nullptr)
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

}

else{

Record *curr = head;

while(curr->next != NULL){

curr = curr-> next;

}
curr->next = ptr;

}


}

void SortedInsert(){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "Enter Roll no of the Student : ";
    cin >> ptr->rollNo;
    cout << "Enter CGPA of Student : ";
    cin >> ptr->CGPA;
    ptr->next = NULL;
    if (head == NULL || head->rollNo >= ptr->rollNo){
        
        ptr->next = head;
        head = ptr;
       
        return;
    }


    
    Record* curr = head;
    while (curr->next != NULL && curr->next->rollNo < ptr->rollNo){
        curr = curr->next;
    }

    ptr->next = curr->next;
    curr->next = ptr;
}

void search (){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    int toSearch;
    cout << "Enter Roll no you want to Search : ";
    cin >> toSearch;
    Record* curr = head;
    while (curr != NULL){
        if (curr->rollNo == toSearch){
            cout << "CGPA of the student is " << curr->CGPA << endl;
            return;
        }
        curr = curr->next;
    }
    if (curr  == NULL){
        cout << "Roll no not Found in the List" << endl;
    }
}

void print (){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    Record* curr = head;
    while (curr != NULL){
        cout << "CGPA of Roll no "<<curr->rollNo<< " is "<<curr->CGPA<< endl;
        curr = curr->next;
    }
}

void deleteElement (){
    if (head == NULL){
        cout << "List is Empty "<< endl;
        return;
    }
    int toDelete;
    cout << "Enter Roll no of Student which you want to Delete : ";
    cin >> toDelete;
    Record* curr = head;
    if (toDelete == curr->rollNo){
        head = head->next;
        free(curr);
        cout << curr->rollNo << endl;
        curr = head;
        cout << "Deleted successfully  " << endl;
        return;
    }
    Record* prev = head;
    curr = prev->next;
    while(curr != NULL){
        if (curr->rollNo == toDelete){
            prev->next = curr->next;
            free(curr);
            cout << "Deleted successfully  " << endl;
            return;
        }
        prev = prev->next;
        curr = curr->next;
    }
    if (curr == NULL){
        cout << "Roll no Not found in the List " << endl;
    }
}

void deleteList (){
    if (head == NULL){
        cout << "List is empty " << endl;
        return;
    }
    Record* curr = head;
    while (head != NULL){
        head = head->next;
        free(curr);
        curr = head;
    }
    free(head);
    cout << "Whole List Deleted "<< endl;
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
}while (n != 9);

}
