#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


struct stNode
{
    int	value;
	stNode *next;
	
};
stNode *top1=nullptr;

void Push1(int value){
	
    stNode *temp = (stNode*)malloc(sizeof(stNode));
    temp->value = value; 
    temp->next = top1;
    top1 = temp;
	
}

int pop1(){
	
	if(top1 == NULL){
		return -1;
	}
	
	int poppedvalue= top1->value;
	stNode* temp=top1;
	top1=top1->next;
	free(temp);
	return poppedvalue;

}

int precedence(char op){
     if (op=='^') return 7;
    if (op=='*'|| op=='/' || op=='%') return 6;
    if (op=='+'|| op=='-' ) return 5;
    if (op=='<'|| op=='>' || op=='<='|| op=='=>') return 4;
    if (op=='==' || op=='!=') return 3;
    if (op=='&&') return 2;
    if (op=='||') return 1;
    return 0;
}
string infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        } else if (ch == '(') {
            Push1(ch);
        } else if (ch == ')') {
            while (top1 != NULL && top1->value != '(') {
                postfix += top1->value;
                pop1();
            }
            if (top1 != NULL)
                pop1();
        } else {
            while (top1 != NULL && precedence(ch) <= precedence(top1->value)) {
                postfix += top1->value;
                pop1();
            }
            Push1(ch);
        }
    }

    while (top1 != NULL) {
        postfix += top1->value;
        pop1();
    }

    return postfix;
}

struct StackNode {
    int data;
    StackNode* next;
};

    StackNode* top=nullptr;

    void push(int value) {
        StackNode* newNode = new StackNode;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top==NULL) {
            cout << "Stack underflow\n";
            return NULL;
        }
        int data = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return top == nullptr;
    }


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '>');
}

int PostfixEvaluation(string postfix) {
    
  int result;
    for (int i=0;i<postfix.length();i++) {
        char ch= postfix[i];
        if (isOperator(ch)) {
             
            int temp; 
            int right = pop();
            int left = pop();
           
          
         switch (ch)
         {
         case '+':
            temp = left+right;
            break;
            case '-':
            temp = left-right;
            break;
               case '*':
            temp = left*right;
            break;
               case '/':
            temp = left/right;
            break;
         default:
            break;
         }
          push(temp);
        
        } 
        else {
            
            push(ch-48);
        }
    }
    result =  pop();
    return result;
}

// void preorderTraversal(TreeNode* root) {
//     if (root) {
    
//         preorderTraversal(root->left);
//         cout << root->data << " ";
//         preorderTraversal(root->right);
//     }
// }

int main() {
    string infixExpression;
    cout << "Enter any expression";
    getline(cin,infixExpression);
    cout << "Infix Expression: " << infixExpression << endl;
    string postfix= infixToPostfix(infixExpression) ;
    
    cout<<  "Postfix Expression: " << postfix << endl;
    int PostEvaluation =  PostfixEvaluation(postfix); 
    cout << "Postfix Evaluation :" << PostEvaluation << endl;

    return 0;
}