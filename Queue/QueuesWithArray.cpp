#include <iostream>
#include <stdlib.h>
using namespace std;


int front = -1;
int rear = -1;
int len =5;

int Queues[5];

void EnQueue(int value){

if(rear == len){

cout << "Queue Overflow" << endl;

}

else{

rear++;
Queues[rear] = value;

if(front == -1){
    front++;
}

}

}




void DeQueue(){

if(front == -1 || front > rear){

cout << "Queue Underflow";


}

front++;

}



void Peek(){

if(front == -1){

cout << "Queue Underflow";


}

cout << Queues[front];

}





int main(){

    int n;
    do {
        cout << "Enter 1 to EnQueue " << endl << "Enter 2 to DeQueue " << endl << "Enter 3 to Peek" << endl;
        cin >> n;
        if (n == 1){

            int value;
            cout << "Enter value to Push";
            cin >> value; 
         EnQueue(value);

        }
        else if (n == 2){
            DeQueue();
        }
       else if (n == 3){
            Peek();
        }
     
    } while (n != 4);



}