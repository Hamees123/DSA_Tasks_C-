#include <iostream>
#include <stdlib.h>
using namespace std;


int top = -1;
int len =5;

int Stacks[5];

void Push(int value){

if(top == len){

cout << "Stack Overflow" << endl;

}

else{
top++;
Stacks[top] = value;


}

}




void Pop(){

if(top == -1){

cout << "Stack Underflow";


}

top--;

}

void Peek(){

if(top == -1){

cout << "Stack Underflow";


}

cout << Stacks[top];




}





int main(){









    int n;
    do {
        cout << "Enter 1 to Push " << endl << "Enter 2 to Pop " << endl << "Enter 3 to Peek" << endl;
        cin >> n;
        if (n == 1){

            int value;
            cout << "Enter value to Push";
            cin >> value; 
         Push(value);

        }
        else if (n == 2){
            Pop();
        }
       else if (n == 3){
            Peek();
        }
     
    } while (n != 4);



}