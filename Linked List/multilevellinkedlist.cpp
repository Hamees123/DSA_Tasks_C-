#include<iostream>
#include <stdlib.h>
using namespace std;

struct student{
int sid;
student *next;

};



struct course {

    int cid;
    course* next;
    student *stud=nullptr;

};



course* head=nullptr;



// void count(){
//     int  count=0;
// if(head==nullptr){
//     cout<<"there is no entry"<<endl;
// }

// course *curr=head;
// while (curr!=nullptr)
// {
//     count++;

//     curr=curr->next;
// }
//  cout<<"Total count is:"<<count<< endl;


// }
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

// void index(){
//       int toSearch;
//     cout << "Enter Roll no you want to Search : ";
//     cin >> toSearch;
//     int  index=0;
// if(head==nullptr){

//     cout<<"there is no entry"<<endl;
// }
// else if(head->cid==toSearch){
//     index=0;
//     cout<<"index of head is"<<index<<endl;
// }
// course *curr=head->next;
// while (curr!=nullptr)
// {
//     index++;
// if(curr->cid==toSearch){



// cout<<"your roll no. index is:"<<index<<endl;

// }

// curr=curr->next;




// }



// }



void insert (){
    course* ptr = (course*)malloc(sizeof(course));
    cout << "Enter course id of the Student : ";
    cin >> ptr->cid;

    ptr->next = NULL;
    if (head == NULL || head->cid >= ptr->cid){

        ptr->next = head;
        head = ptr;

        return;
    }



    course* curr = head;
    while (curr->next != NULL && curr->next->cid < ptr->cid){
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
    cout << "Enter course id you want to Search : ";
    cin >> toSearch;
    course* curr = head;
    while (curr != NULL){
        if (curr->cid == toSearch){
            cout << "course id :"<<curr->cid << endl;
            return;
        }
        curr = curr->next;
    }
    if (curr  == NULL){
        cout << "course id not Found in the List" << endl;
    }
}

void print (){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    course* curr = head;
    while (curr != NULL){
        cout <<curr->cid<< endl;
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
    course* curr = head;
    if (toDelete == curr->cid){
        head = head->next;
        free(curr);
        cout << curr->cid << endl;
        curr = head;
        cout << "Deleted successfully  " << endl;
        return;
    }
    course* prev = head;
    curr = prev->next;
    while(curr != NULL){
        if (curr->cid == toDelete){
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

// void deleteList (){
//     if (head == NULL){
//         cout << "List is empty " << endl;
//         return;
//     }
//     course* curr = head;
//     while (head != NULL){
//         head = head->next;
//         free(curr);
//         curr = head;
//     }
//     free(head);
//     cout << "Whole List Deleted "<< endl;
// }







void addstudent(){
if(head==nullptr){
 cout<<"course list is empty";

}

course *curr=head;
int c;
cout<<"In which course do you want to add a student";
cin>>c;
while(curr!=nullptr){

if(curr->cid==c){

student *s=(student*)malloc(sizeof(student));
int a;
cout<<"enter student id";
cin >> a;
s->sid=a;

if(curr->stud==nullptr){

   curr->stud=s;
   s->next = nullptr;
}


else{
student *temp=curr->stud;

while(temp->next!=nullptr){

temp=temp->next;

}

temp->next=s;

}
}

curr=curr->next;

}





}



void studentprint(){


    if(head==nullptr){

        cout<<"course list empty";

    }

    int b;
    cout<<"enter course id";
    cin>>b;
    course *curr =head;
    while(curr!=nullptr){
        if(curr->cid==b){

        if(curr->stud==nullptr){

               cout<<"no students enrolled in this course";
           }

           else{
               student *temp=curr->stud;
                while(temp!=nullptr){
                   cout<<"student id"<<temp->sid;
                   temp=temp->next;

               }



           }

        }

        curr = curr->next;

    }






}


void deleteStudentFromCourse(){
    
    if(head==nullptr){

cout<<"course list is empty";
return;
}

int searchCourse;
cout<<"enter course id";
cin>>searchCourse;

course *curr = head;
while(curr!=nullptr){
if(searchCourse==curr->cid){
    int delStudentFromCourse;
cout<<"enter Student id";
cin>>delStudentFromCourse;

if(curr->stud==nullptr){
    
    cout << "No Students are enrolled in this course";
    return;
    
}

student *temp=curr->stud;

// student *currst=temp;
if(temp->sid==delStudentFromCourse){
curr->stud=curr->stud->next;
free(temp);

   cout<<"delete successfully";
return;
}

else{
student *prev=temp;
temp=prev->next;
while (temp!=nullptr)
{
    if(temp->sid==delStudentFromCourse){
       prev->next=temp->next;
       free(temp);
        cout<<"delete successfully";
        return;
    }
    prev=prev->next;
    temp=temp->next;

}




}



}
curr=curr->next;
} 
    
    
    
    
    
    
    
    
    
}





void searchStudent(){

if(head==nullptr){
    cout << "Course list is empty";
}

int searchStudent;
cout << "Enter Course ID";
cin >> searchStudent;
course  *curr = head;
while(curr!=nullptr){

if(curr->cid == searchStudent){
int searchStudentID;
cout << "Enter Student ID";
cin >> searchStudentID;
if(curr->stud == nullptr){
    cout << "No students";
}

else {

student *temp = curr->stud;

while(temp!=nullptr){
if(temp->sid == searchStudentID){

cout << "ID is : " << temp->sid << endl;


}

temp = temp->next;

}


}

}

curr = curr->next;




}



}



void deleteStudent(){
    
    if(head==nullptr){

cout<<"course list is empty";

}

int searchSID;
cout<<"enter Student id";
cin>>searchSID;
 course* curr = head;
    while (curr != nullptr) {
        student* temp = curr->stud;
        student* prev = nullptr;
        while (temp != nullptr) {
            if (temp->sid == searchSID) {
                if (prev == nullptr) {
                    curr->stud = temp->next;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
                break; // Delete only the first occurrence
            }
            prev = temp;
            temp = temp->next;
        }
        curr = curr->next;
    }
// course *curr = head;
// student *temp=curr->stud;
// while(curr!=nullptr){

// if(curr->stud==nullptr){
    
//     cout << "No Students are enrolled in this course";
    
    
// }
// if(temp!=nullptr){
//     if(temp->sid==searchSID){
//         curr->stud=curr->stud->next;
//         free(temp);
//         cout<<"delete successfully";
//         curr=curr->next;
//         continue;
//     }







// student *prev=temp;
// temp=prev->next;
// while (temp!=nullptr)
// {
//     if(temp->sid==searchSID){
//        prev->next=temp->next;
//        free(temp);

// cout << "Deleted Successfully";
// break;

//     }
//     prev=prev->next;
//     temp=temp->next;

// }





// }
// curr=curr->next;

// }

} 
    
    
    
    
    
    
    
    
    





int main (){




    int n;
    do {
        cout << "Enter 1 to Add Course " << endl << "Enter 2 to Search Course " << endl << "Enter 3 to Print Course List" << endl << "Enter 4 to Delete a Course" << endl << "Enter 5 to Add Student to Course " << endl << "Enter 6 to Print Students" << endl << "Enter 7 to Delete Student From Course" << endl<<"Enter 8 to Search A Student" << endl <<  "Enter 9 to Delete Students From All Courses " << endl <<  "Enter 10 to Quit" << endl;
        cin >> n;
        if (n == 1){
            insert();
        } else if (n == 2){
            search ();
        } else if (n == 3){
            print();
        }  else if (n == 4){
            deleteElement();
        } else if (n == 5){
            addstudent();
        }
         else if (n == 6){
            studentprint();
        }
        else if (n == 7){
            deleteStudentFromCourse();
        }
        else if (n == 8){
            searchStudent();
        }
       
         else if (n == 9){
            deleteStudent();
        }
        
    } while (n != 10);
}
