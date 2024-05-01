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
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

struct StackNode {
    TreeNode* data;
    StackNode* next;
};

    StackNode* top=nullptr;

    void push(TreeNode* treeNode) {
        StackNode* newNode = new StackNode;
        newNode->data = treeNode;
        newNode->next = top;
        top = newNode;
    }

    TreeNode* pop() {
        if (top==nullptr) {
            cout << "Stack underflow\n";
            return nullptr;
        }
        TreeNode* treeNode = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return treeNode;
    }

    bool isEmpty() {
        return top == nullptr;
    }


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '>');
}

TreeNode* constructExpressionTree(string postfix) {
    
    for (int i=0;i<postfix.length();i++) {
        char ch= postfix[i];
        if (isOperator(ch)) {
            TreeNode* right = pop();
            TreeNode* left = pop();
            TreeNode* newNode = new TreeNode;
            newNode->data = ch;
            newNode->left = left;
            newNode->right = right;
            push(newNode);
        } else {
            TreeNode* newNode = new TreeNode;
            newNode->data = ch;
            newNode->left = nullptr;
            newNode->right = nullptr;
            push(newNode);
        }
    }
    return pop();
}

void preorderTraversal(TreeNode* root) {
    if (root) {
    
        preorderTraversal(root->left);
        cout << root->data << " ";
        preorderTraversal(root->right);
    }
}

int main() {
    string infixExpression;
    cout << "Enter any expression";
    getline(cin,infixExpression);
    cout << "Infix Expression: " << infixExpression << endl;
    string postfix= infixToPostfix(infixExpression) ;
    
    cout<<  "Postfix Expression: " << postfix << endl;
    TreeNode* root = constructExpressionTree(postfix);
    cout << "Inorder traversal of the constructed expression tree:\n";
    preorderTraversal(root);
    cout << endl;

    return 0;
}