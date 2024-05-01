#include <iostream>
using namespace std;



void heapify(int arr[],int size){
      for(int i=0;i<size;i++){
          int p=(i-1)/2;
           if(arr[p]<arr[i]){
            int temp=arr[i];
            arr[i]=arr[p];
            arr[p]=temp;
              
              p=(i-1)/2;
               if(arr[0]<arr[p]){
                 int temp=arr[0];
                 arr[0]=arr[p];
                 arr[p]=temp;
               }


           }


      }
     
      

           cout<< "Max Heap Array :" << endl;
        for(int i=0;i<size;i++){
           cout<< arr[i]<<" ";
            
         }






}


void MinHeap(int arr[],int size){
      for(int i=0;i<size;i++){
          int p=(i-1)/2;
           if(arr[p]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[p];
            arr[p]=temp;
              
              p=(i-1)/2;
               if(arr[0]>arr[p]){
                 int temp=arr[0];
            arr[0]=arr[p];
            arr[p]=temp;
               }


           }


      }
     
      

    cout<< "Min Heap Array :" << endl;
 for(int i=0;i<size;i++){
           cout<< arr[i]<<" ";
            
         }






}



void insert(int arr[],int size){

         int value;
         for(int i=0;i<size;i++){
            cout<<"Enter Value :" << endl;
            cin>>value;

            arr[i]=value;

         }
      
 for(int i=0;i<size;i++){
           cout<< arr[i] << " " ;
            
         }

    
}









void delheapify(int arr[],int size){
        for(int i=0;i<size;i++){
          int p=(i-1)/2;
           if(arr[p]<arr[i]){
            int temp=arr[i];
            arr[i]=arr[p];
            arr[p]=temp;
              
              p=(i-1)/2;
               if(arr[0]<arr[p]){
                 int temp=arr[0];
            arr[0]=arr[p];
            arr[p]=temp;
               }


           }


      }

}







void del(int arr[],int size){
          int temp=arr[0];
          arr[0]=arr[size-1];
          arr[size-1]=temp;
          delheapify(arr,size-1);
}






void heapsort(int arr[],int size){


        for(int i=0;i<size;i++){
               
               del(arr,size-i);
               

        }


  cout<< "Heap Sorted :"<<endl;
           for(int i=0;i<size;i++){
               
              cout<<  arr[i] << " " ;
               

        }

}





int main(){
int n;
cout<< "Enter Array Length :" << endl;
cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
    arr[i]=-1;
    cout << arr[i]<< " " ;
 }
int choice;
do{
cout << endl <<"Enter 1 for Insert" << endl << "Enter 2 for Max Heap" << endl << "Enter 3 for Heap Sort" << endl << "Enter 4 for Min Heap" << endl << "Enter 5 for Exit" << endl;
cin >> choice;



if (choice == 1)
{


insert(arr,n);





}

else if(choice == 2){

heapify(arr,n);



}

else if(choice == 3){

heapsort(arr,n);


}

else if(choice == 4){


MinHeap(arr,n);



}


}
while (choice != 5);


}
