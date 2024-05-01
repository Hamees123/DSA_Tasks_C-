#include <iostream>
using namespace std;
#include <stdlib.h>

struct Hash{

int value;
Hash *next;

};




void Insert(int key,Hash* hashtable[],int size){


int index = key%size;
Hash* ptr=(Hash*)malloc(sizeof(Hash));

ptr->value=key;
ptr->next=NULL;

    if(hashtable[index] == NULL){
          hashtable[index] = ptr;   

 }
    else{
        Hash *curr=hashtable[index];
        while(curr->next!= NULL){
            
            curr=curr->next;
            
        }
        curr->next=ptr;
        
    }
    
    
    






}













void Search(Hash* hashtable[],int size,int toSearch){
    int index=toSearch%size;
Hash *curr=hashtable[index];
if(curr==NULL){
    cout<<"not found";
    return;
}
if(curr->value==toSearch){
    cout<<"found";
      return;
}


    curr=curr->next;
     while(curr!=nullptr){
            if(curr->value==toSearch){
    cout<<"found";
      return;
  
}
            curr=curr->next;
            
        }

// for(int i  = 0;i<size;i++){

// if(hashtable[i] == toSearch){

//  cout << "Found" << endl;


// }
 

// }


 if (curr == NULL){
        cout << "Not found " << endl;
    }


}







int main(){


int size;
cout<<"Enter Array Size";
cin>>size;
Hash* hashtable[size];
for(int i = 0 ; i<size ; i++){

hashtable[i] = nullptr;


}



int choice;




do{


cout << "Enter 1 for Insert" << endl << "Enter 2 for Search" << endl << "Enter 3 for Exit" << endl;
cin >> choice;

if (choice == 1)
{






int key;
cout << "Enter Your Value";
cin >> key;

Insert(key,hashtable,size);






}

else if(choice == 2){

int toSearch;
cout << "Enter Your Value to Search";
cin >> toSearch;



Search(hashtable,size,toSearch);



}





}
while (choice != 3);









}
