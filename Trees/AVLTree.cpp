#include <iostream>
#include <stdlib.h>
using namespace std;



struct BSTNode{

int data;
BSTNode *left;
BSTNode *right;
int LeftHeight;
int RightHeight;


};



int MaxHeight(int LH,int RH){

if(LH > RH){

return LH;

}

else{

return RH;

}




}





BSTNode* ShiftRight(BSTNode *Unbalance){

BSTNode *RL = Unbalance->left;
BSTNode *temp = RL->right;
RL->right = Unbalance;
Unbalance->left = temp;

if(temp == NULL){

Unbalance->LeftHeight = 0;

}

else{

Unbalance->LeftHeight = MaxHeight(temp->LeftHeight,temp->RightHeight) + 1;



}

RL->RightHeight = MaxHeight(Unbalance->LeftHeight,Unbalance->RightHeight) + 1;
return RL;


}


BSTNode* ShiftLeft(BSTNode *Unbalance){

BSTNode *RL = Unbalance->right;
BSTNode *temp = RL->left;
RL->left = Unbalance;
Unbalance->right = temp;

if(temp == NULL){

Unbalance->RightHeight = 0;

}

else{

Unbalance->RightHeight = MaxHeight(temp->LeftHeight,temp->RightHeight) + 1;



}

RL->LeftHeight = MaxHeight(Unbalance->LeftHeight,Unbalance->RightHeight) + 1;
return RL;


}









BSTNode* Insert(int key,BSTNode *node){

if (node == NULL)
{
   BSTNode *node =(BSTNode*)malloc(sizeof(BSTNode)); 
node->data = key;
node->left = NULL;
node->right = NULL;
node->LeftHeight = 0;
node->RightHeight = 0;

return node;

}


if(key < node->data)
{

node->left = Insert(key,node->left);
node->LeftHeight = MaxHeight(node->left->LeftHeight,node->left->RightHeight) +1;


}


else{

node->right = Insert(key,node->right);
node->RightHeight = MaxHeight(node->right->LeftHeight,node->right->RightHeight) +1;



}

int BalanceFactor = node->LeftHeight - node->RightHeight;

if(BalanceFactor < -1){

if(key > node->right->data){

node = ShiftLeft(node);


}
 
else{

// Double Shift (Right , Left)
node->right = ShiftRight(node->right);
node = ShiftLeft(node);


}




}

else if(BalanceFactor > 1){

if(key < node->left->data){

node = ShiftRight(node);


}
 
else{
   
// Double Shift (Left , Right)

node->left = ShiftLeft(node->left);
node = ShiftRight(node);

}




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
			cout<<:" delete successfully";
			return temp;
		}
		else if(node->right==NULL){
			BSTNode* temp=node->left;
			free(node);
			cout<<:" delete successfully";
			return temp;
		}
		
		BSTNode* temp=min(node->right);
		node->data=temp->data;
		  node->right= deletenode(node->right,temp->data);
		  
		
		
	}
	return node;
}

// int height(BSTNode* Root) {
//     if (Root == nullptr) {
//         return 0;
//     }

//     int left_height = height(Root->left);
//     cout << Root->data;
//     int right_height = height(Root->right);

//     return 1 + max(left_height, right_height);
// }


// bool isBalanced(BSTNode* Root) {
//     if (Root == nullptr) {
//         return true;
//     }

// if(isBalanced(Root->left) == false){
//     return false;
// }

// if(isBalanced(Root->right) == false){
//     return false;
// }
//     int left_height = height(Root->left);
//     int right_height = height(Root->right);

// if(abs(left_height-right_height)<=1){
//     return true;
// }
// else{
//     return false;
// }


// }

int main(){


BSTNode *Root = NULL;




  int n;
    do {
        cout << "Enter 1 to Insert data " << endl << "Enter 2 to search data " << endl << "Enter 3 to Inorder Traverse  " << endl<< "Enter 4 to preorder Traverse  " << endl<< "Enter 5 to postorder Traverse  " << endl<< "Enter 6 for min value   " << endl<< "Enter 7 for max value " << endl << "Enter 8 to delete value " << endl << "Enter 9 to get height" << endl << "Enter 10 to Find Balance or Unbalance Tree Nodes" << endl;
        cin >> n;
        if (n == 1){

            int key;
            cout << "Enter any number" << endl;
            cin >> key;

          Root = Insert(key,Root);
        }
        else if (n == 2){

            int toSearch;
            cout << "Enter any number to search" << endl;
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
          	cout<<"enter value to delete" << endl;
          	cin>>todel;
           Root= deletenode(Root,todel);
           
        }
           else if (n == 9){

        //    int a = height(Root);
        
            //  if(Root->LeftHeight > Root->RightHeight){

            //     Root->LeftHeight++;
            //     cout << Root->LeftHeight  << endl;

            //  }
            //  else{
            //     Root->RightHeight++;
            //     cout << Root->RightHeight  << endl;
            //  }
        }

          else if (n == 10){

        //    bool a = isBalanced(Root);
        //    if(a == true ){
        //     cout << "Balanced Tree" << endl;
        //    }
        //      else{
        //     cout << "Unbalanced Tree" << endl;
        //    }
        }
    } 
    while (n != 11);




}
