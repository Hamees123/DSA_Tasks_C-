#include <iostream>
using namespace std;


void Insert(int key,int HashTable[],int len){


int index = key%len;
int i = 0;

while (i<len)
{
    

index = (index + i*i)%len;
i++;

if(HashTable[index] == -1){

HashTable[index] = key;
break;

}


}

HashTable[index]  = key;


for(int i  = 0;i<len;i++){
    cout << HashTable[i] << endl; 
}




}






void Search(int HashTable[],int len,int toSearch){

int i = 0;
int index = toSearch%len;

// if(HashTable[index] == toSearch){

// cout << "Found" << endl;
// return;

// }
if(HashTable[index]==-1){
    cout<<"Not Found";
    return;
}
do{

if(HashTable[index] == toSearch){

cout << "Found" << endl;
return;

}
 index = (index + i*i)%len;
 i++;

}while(i<len);


cout<<"Not Found";



}







int main(){


int len;
cout << "Enter Array Size";
cin >> len;

int HashTable[len];

for(int i = 0 ; i<len ; i++){

HashTable[i] = -1;


}



int choice;
cout << "Enter 1 for Insert" << endl << "Enter 2 for Search" << endl << "Enter 3 for Exit" << endl;
cin >> choice;
int count = 0;


do{




if (choice == 1)
{

count++;

if(count <= len){


int key;
cout << "Enter Your Value";
cin >> key;

Insert(key,HashTable,len);

}
else{

cout << "Hash Table is Full" << endl;

}

cout << "Enter 1 for Insert" << endl << "Enter 2 for Search" << endl << "Enter 3 for Exit" << endl;
cin >> choice;

}

else if(choice == 2){

int toSearch;
cout << "Enter Your Value to Search";
cin >> toSearch;



Search(HashTable,len,toSearch);

cout << "Enter 1 for Insert" << endl << "Enter 2 for Search" << endl << "Enter 3 for Exit" << endl;
cin >> choice;


}





}
while (choice != 3);









}