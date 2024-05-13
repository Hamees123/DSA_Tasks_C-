#include <iostream>
using namespace std;




int LinearSearch(int arr[],int n,int value){

for(int i=0;i<n;i++){

  if(arr[i]==value){

    return i;

  }


}

  return -1;



}











int BinarySearch(int arr[],int n,int value){

int left=0;
int right=n;

while (left<=right)
{
    int mid=(left+right)/2;

    if(arr[mid]==value){

        return mid;

    }
   else if(arr[mid]>value){

    right = mid-1;

   }
   else{

     left = mid+1;

   }


}

return -1;



}










int main(){

int n;
cout <<" Enter Array Length " << endl;
cin>>n;

int arr[n];
cout << "Enter Array Elements In Sorted Order" << endl;

for(int i=0;i<n;i++){

cin>>arr[i];


}



  int choice;

    do {

     

        cout << endl << "Enter 1 for Linear Search " << endl << "Enter 2 for Binary Search " << endl << "Enter 3 to Exit the Program " << endl;
        cin >> choice;
        if (choice == 1){

            int toSearch; 
            cout<<"enter your value";
            cin>>toSearch;

            int SearchedValue =  LinearSearch(arr,n,toSearch);

            cout << " Searched Index of Value By Linear Search : "  << SearchedValue << endl;

        }
        else if (choice == 2){
             
            int toSearch; 
            cout<<"enter your value";
            cin>>toSearch;

            int SearchedValue =  BinarySearch(arr,n,toSearch);

            cout << " Searched Index of Value By Binary Search : "  << SearchedValue << endl;
       
        }
   
        }while (choice != 3);
        
    } 


