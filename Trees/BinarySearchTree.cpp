#include <iostream>
#include <stdlib.h>
using namespace std;



struct BSTNode{

int data;
BSTNode *left;
BSTNode *right;

};



BSTNode* Insert(int key,BSTNode *node){

if (node == NULL)
{
   BSTNode *node =(BSTNode*)malloc(sizeof(BSTNode)); 
node->data = key;
node->left = NULL;
node->right = NULL;

return node;

}


if(key < node->data)
{

node->left = Insert(key,node->left);

}

else{

node->right = Insert(key,node->right);

}


return node;


}


void Search(int toSearch,BSTNode *node){

if(node == NULL){

cout << "value not found" << endl;
return;
 
}

else if(toSearch == node->data){

cout << "Value Found" << endl;

return;

}


 else if (toSearch < node->data)
{
    
Search(toSearch,node->left);


}

else{

Search(toSearch,node->right);

}





}





void InOrder(BSTNode* node){
	
	
	if(node == NULL){
		return;
		
		
		
		
	}
	else{
	InOrder(node->left);
		cout <<  "->" <<node->data<<endl ;
		InOrder(node->right);
	}

	
	
	
	
	
}

void preOrder(BSTNode* node){
	
	
	if(node == NULL){
		return;
		
	}
	
	else{
		cout <<  "->" <<node->data<<endl ;
		preOrder(node->left);
		preOrder(node->right);
	}
	
	
	
	
}

void postOrder(BSTNode* node){
	
	
	if(node == NULL){
		
		return;
		
	}
	
	else{
		postOrder(node->left);
		postOrder(node->right);
		cout <<  "->" <<node->data<<endl ;
	}
	
	
	
	
}

BSTNode* min(BSTNode* node){
	
	BSTNode* curr=node;
	while(curr->left!=NULL){
		curr=curr->left;
	}
	
	return curr;
	
}

BSTNode* max(BSTNode* node){
	
	BSTNode* curr=node;
	while(curr->right!=NULL){
		curr=curr->right;
	}
	
	return curr;
	
}

BSTNode* deletenode(BSTNode* node,int todel){
	
	if(node==NULL){
		cout<<"tree is empty"<<endl;
		return node;
	}
	if(todel<node->data){
		node->left=deletenode(node->left,todel);
		
	}
	   else	if(todel>node->data){
		node->right=deletenode(node->right,todel);
		
	}
	else{
		if(node->left==NULL){
			BSTNode* temp=node->right;
			free(node);
			return temp;
		}
		else if(node->right==NULL){
			BSTNode* temp=node->left;
			free(node);
			return temp;
		}
		
		BSTNode* temp=min(node->right);
		node->data=temp->data;
		   deletenode(temp,todel);
		  
		
		
	}
	return node;
}



int main(){


BSTNode *Root = NULL;




  int n;
    do {
        cout << "Enter 1 to Insert data " << endl << "Enter 2 to search data " << endl << "Enter 3 to Inorder Traverse  " << endl<< "Enter 4 to preorder Traverse  " << endl<< "Enter 5 to postorder Traverse  " << endl<< "Enter 6 for min value   " << endl<< "Enter 7 for max value " << endl<< "Enter 8 to delete value " << endl;
        cin >> n;
        if (n == 1){

            int key;
            cout << "Enter any number";
            cin >> key;

          Root = Insert(key,Root);
        }
        else if (n == 2){

            int toSearch;
            cout << "Enter any number to search";
            cin >> toSearch;
            Search (toSearch,Root);
        }
        
          else if (n == 3){
            InOrder(Root);
        }
         else if (n == 4){
            preOrder(Root);
        }
         else if (n == 5){
            postOrder(Root);
        }
         else if (n == 6){
           BSTNode* temp= min(Root);
           cout<< temp->data;
        }
         else if (n == 7){
           BSTNode* temp= max(Root);
           cout<< temp->data;
        }
          else if (n == 8){
          	int todel;
          	cout<<"enter value to delete";
          	cin>>todel;
           Root= deletenode(Root,todel);
           
        }
        
    } 
    while (n != 9);




}

