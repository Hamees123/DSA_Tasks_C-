#include <iostream>
#include<cstdlib>
#include <algorithm>
using namespace std;

struct stNode
{
    int	value;
	stNode *next;
	
};
stNode *top=NULL;

void Push(int value){
	
    stNode *temp = (stNode*)malloc(sizeof(stNode));
    temp->value = value; 
    temp->next = top;
    top = temp;
	
}

int pop(){
	
	if(top == NULL){
		return -1;
	}
	
	int poppedvalue= top->value;
	stNode* temp=top;
	top=top->next;
	free(temp);
	return poppedvalue;

}

int precedence(char op){
    if (op=='*'|| op=='/' || op=='%') return 6;
    if (op=='+'|| op=='-' ) return 5;
    if (op=='<'|| op=='>' || op=='<='|| op=='=>') return 4;
    if (op=='==' || op=='!=') return 3;
    if (op=='&&') return 2;
    if (op=='||') return 1;
    return 0;
}
string infixToPrefix(string infix) {
    reverse(infix.begin(),infix.end());
    string postfix = "";
      
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        } else if (ch == ')') {
            Push(ch);
        } else if (ch == '(') {
            while (top != NULL && top->value != ')') {
                postfix += top->value;
                pop();
            }
            if (top != NULL)
                pop();
        } else {
            while (top != NULL && precedence(ch) <= precedence(top->value)) {
                postfix += top->value;
                pop();
            }
            Push(ch);
        }
    }

    while (top != NULL) {
        postfix += top->value;
        pop();
    }
        reverse(postfix.begin(),postfix.end());

    return postfix;
}



int main() {
    string infixExpression;
    cout << "Enter any expression";
    getline(cin,infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Prefix Expression: " << infixToPrefix(infixExpression) << endl;
    return 0;

}