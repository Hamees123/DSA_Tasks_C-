#include <iostream>
using namespace std;



void SelectionSort(int arr[],int n){

for (int i = 0; i < n-1; i++)
{
    int mi = i;
for (int j = i+1; j < n; j++)
{
    
if(arr[j] < arr[mi]){
    mi = j;
}



}

int temp = arr[i];
arr[i]  = arr[mi];
arr[mi] = temp;

}


}







void InsertionSort(int arr[],int n){

for (int i = 1; i < n; i++)
{
    
int hold = arr[i];

while (hold < arr[i-1] && i>0)
{
    
arr[i] = arr[i-1];

i--;

}

arr[i] = hold;



}


}





void BubbleSort(int arr[],int n){

for (int i = 0; i < n-1; i++)
{
  
for (int j = 0; j < n-i-1; j++)
{
    
if(arr[j] > arr[j+1]){

  int temp = arr[j];
  arr[j]  = arr[j+1];
  arr[j+1] = temp;

}


}

}

}






int main(){

int n;
cout <<" Enter Array Length " << endl;
cin>>n;

int arr[n];
cout << "Enter Array Elements" << endl;

for(int i=0;i<n;i++){

cin>>arr[i];


}


  int choice;
    do {
        cout << endl << "Enter 1 for Selection Sort " << endl << "Enter 2 for Insertion Sort " << endl << "Enter 3 for Bubble Sort" << endl;
        cin >> choice;
        if (choice == 1){
            SelectionSort(arr,n);

            cout << "Sorted Array By Selection Sort : " ;

            for(int i=0;i<n;i++){

            cout << arr[i] << " " ;


              }
        }
        else if (choice == 2){
             InsertionSort(arr,n);

             cout << "Sorted Array By Insertion Sort : " ;
             for(int i=0;i<n;i++){

            cout << arr[i] << " " ;


              }
        }
       else if (choice == 3){
             BubbleSort(arr,n);

             cout << "Sorted Array By Bubble Sort : " ;

             for(int i=0;i<n;i++){

            cout << arr[i] << " " ;


              }
        }
        
    } while (choice != 4);


}

