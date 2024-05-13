#include<iostream>
#include <cstdlib>
#include <memory>


using namespace std;

struct Vertex;

struct Edge{

int data;
Edge *next;
Vertex *ver;

};

struct Vertex {
     Vertex *parent;
    bool visited;
    int data;
    Vertex* next;
    Edge *EdgeList = NULL;

};


Vertex* head = NULL;

// Function to push onto stack
int top = -1;
void push(Vertex *value, Vertex *stack[], int size)
{
  if (top == size - 1)
  {
    cout << "Stack overflow" << endl;
    return;
  }
  top++;
  stack[top] = value;
}


Vertex *pop(Vertex *stack[], int size)
{
  if (top == -1)
  {
    return NULL;
  }
  Vertex *tmp = stack[top];
  top--;
  return tmp;
}

int top1=-1;
void push1(Vertex *value, Vertex *stack[], int size)
{
  if (top1 == size - 1)
  {
    cout << "Stack overflow" << endl;
    return;
  }
  top1++;
  stack[top1] = value;
}


Vertex *pop1(Vertex *stack[], int size)
{
  if (top1 == -1)
  {
    return NULL;
  }
  Vertex *tmp = stack[top1];
  top1--;
  return tmp;
}



// Undirected Graph
void AddVertex(){
    Vertex* ptr = (Vertex*)malloc(sizeof(Vertex));
    int data;
    cout << "Enter Vertex Value : " << endl;
    cin >> data;
    ptr->data = data;
    ptr->next = NULL;
    ptr->EdgeList = NULL;
    ptr->visited = false;

    if (head == NULL){

        head = ptr;
        return;
    }


    Vertex* curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = ptr;
    
}


Vertex* SearchVertex(int value){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return NULL;
    }
   
    Vertex* curr = head;
    while (curr != NULL){
        if (curr->data == value){
            return curr;
        }
        curr = curr->next;
    }
    if (curr  == NULL){
        cout << "Vertex not found" << endl;
    }
    return curr;
}




void AddEdge_Of_Undirected(){

      int source;
         cout << "Enter The Source Vertex : " << endl;
         cin >> source;

         int dest;
         cout << "Enter The Destination Vertex : " << endl;
         cin >> dest;



   Vertex *searchSource = SearchVertex(source);
   Vertex *searchDest = SearchVertex(dest);


    Edge* ptr1 = (Edge*)malloc(sizeof(Edge));
    ptr1->ver = searchDest;
    ptr1->next = NULL;

   
 if(searchSource->EdgeList == NULL){

    searchSource->EdgeList = ptr1;
   }
     else{

        Edge *temp = searchSource->EdgeList;

           while(temp->next != NULL){
            temp = temp->next;
           }
           temp->next = ptr1;
       
           
   }
    Edge* ptr2 = (Edge*)malloc(sizeof(Edge));
    ptr2->ver = searchSource;
    ptr2->next = NULL;

   if(searchDest->EdgeList == NULL){

    searchDest->EdgeList = ptr2;
    
   }
     else{

        Edge *temp = searchDest->EdgeList;
           while(temp->next != NULL){
            temp = temp->next;
           }
           temp->next = ptr2;
      
   }

  
 
   }





 void PrintConnectedVertices_Of_Undirected() {

    Vertex* curr = head;
    while (curr != NULL) {
        cout << "Vertex: " << curr->data << endl;
        Edge* edge = curr->EdgeList;
        while (edge != NULL) {
            cout << "    Edge: " << curr->data << " to " << edge->ver->data << endl;
            edge = edge->next;
        }
        curr = curr->next;
    }
 
}



   // Function to print path using DFS
   void findPath_Of_Undirected(int src, int dest)
{
  Vertex *stack[10];
  // find src node
  Vertex *srcNode = head;
  while (srcNode != NULL)
  {
    if (srcNode->data == src)
    {
      break;
    }
    srcNode = srcNode->next;
  }
  // find dest node
  Vertex *destNode = head;
  while (destNode != NULL)
  {
    if (destNode->data == dest)
    {
      break;
    }
    destNode = destNode->next;
  }
  if (destNode == NULL)
  {
    cout << "Connection not Exist ";
    return;
  }

  Vertex *currVertex = srcNode;
  do
  {
    Edge *currEdge = currVertex->EdgeList;
    while (currEdge != NULL && currEdge->ver->visited)
    {
      currEdge = currEdge->next;
    }
    currVertex->visited = true;
    if (currEdge == NULL)
    {
      currVertex = pop(stack, 10);
    }
    else
    {
      push(currVertex, stack, 10);
      currVertex = currEdge->ver;
    }
  } while (currVertex != destNode);
  cout << currVertex->data;
  while (top != -1)
  {
    Vertex *tmp = pop(stack, 10);

    cout << " <- " << tmp->data;
  }
  cout << endl;
  currVertex = head;
  while (currVertex != NULL)
  {
    currVertex->visited = false;
    currVertex = currVertex->next;
  }
}


void printVertex()
{
  Vertex *curr = head;
  cout << "The Vertices are : " ;
  while (curr != NULL)
  {
    cout <<   curr->data << " " ;
    curr = curr->next;
  }
}



int Degree(){



if(head==NULL){
    cout<<"there is no entry"<<endl;
    return -1;
}
 int  count=0;
int searchVertex;
cout << "Enter Vertex Value" << endl;
cin >> searchVertex;

Vertex *curr=head;
while (curr!=NULL)
{
    if(curr->data == searchVertex){
             break;
        }
     curr=curr->next;
}
if (curr == NULL)
  {
    cout << "this representation vertex not found in the graph" << endl;
    return -1;
  }
    Edge *temp = curr->EdgeList;
    while (temp!=NULL)
    {    
        count++;
        temp = temp->next;
    }
   return count;  
   

}


//Directed Graph



void AddEdge_Of_Directed(){

      int source;
         cout << "Enter The Source Vertex : " << endl;
         cin >> source;

         int dest;
         cout << "Enter The Destination Vertex : " << endl;
         cin >> dest;



   Vertex *searchSource = SearchVertex(source);
   Vertex *searchDest = SearchVertex(dest);


    Edge* ptr1 = (Edge*)malloc(sizeof(Edge));
    ptr1->ver = searchDest;
    ptr1->next = NULL;

   
 if(searchSource->EdgeList == NULL){

    searchSource->EdgeList = ptr1;
   }
     else{

        Edge *temp = searchSource->EdgeList;

           while(temp->next != NULL){
            temp = temp->next;
           }
           temp->next = ptr1;
       
           
   }
   
   
   }






int OutDegree(){



if(head==NULL){
    cout<<"there is no entry"<<endl;
    return -1;
}
 int  count=0;
int searchVertex;
cout << "Enter Vertex Value for Outdegree";
cin >> searchVertex;

Vertex *curr=head;
while (curr!=NULL)
{
    if(curr->data == searchVertex){
             break;}
              curr=curr->next;
}
if (curr == NULL)
  {
    cout << "this representation vertex not found in the graph" << endl;
    return -1;
  }
    Edge *temp = curr->EdgeList;
    while (temp!=NULL)
    {    
        count++;
        temp = temp->next;
    }
   return count;  
   

}

int InDegree() {
    if (head == NULL) {
        cout << "Graph is empty" << endl;
        return -1;
    }
int searchVertex;
cout << "Enter Vertex Value for Indegree";
cin >> searchVertex;
    Vertex* curr = head;
    int count = 0;

    while (curr != NULL) {
        Edge* edge = curr->EdgeList;
        while (edge != NULL) {
            if (edge->ver->data == searchVertex) {
                count++;
            }
            edge = edge->next;
        }
        curr = curr->next;
    }

    return count;
}





void BFS(int src) {
    if (head == NULL) {
        cout << "Graph is empty" << endl;
        return;
    }

    // Dynamically allocate memory for the visited array
    // bool* visited = new bool[10] {false};

    // Create an array to act as a queue
    Vertex* queue[10];
    int front = 0, rear = -1;

    // Find the source node
    Vertex* srcNode = SearchVertex(src);

    if (srcNode == NULL) {
        cout << "Source vertex not found" << endl;
        // delete[] visited; // Deallocate memory
        return;
    }

    cout << "Breadth First Search starting from vertex " << src << ": ";

    // Enqueue the source node and mark it as visited
    queue[++rear] = srcNode;
    srcNode->visited = true;

    // Traverse until the queue is empty
    while (front <= rear) {
        // Dequeue a vertex from the queue
        Vertex* currVertex = queue[front++];
        cout << currVertex->data << " ";

        // Visit all adjacent vertices of the dequeued vertex
        Edge* currEdge = currVertex->EdgeList;
        while (currEdge != NULL) {
            if (!(currEdge->ver->visited)) {
                // Mark the adjacent vertex as visited before enqueuing
                currEdge->ver->visited = true;
                // Enqueue the adjacent vertex
                queue[++rear] = currEdge->ver;
            }
            currEdge = currEdge->next;
        }
    }
    cout << endl;

    // Deallocate memory for the visited array
    // delete[] visited;
     // Reset visited flag for all vertices
    Vertex* resetVertex = head;
    while (resetVertex != NULL) {
        resetVertex->visited = false;
        resetVertex = resetVertex->next;
    }
}



void DFS(int src) {
    if (head == NULL) {
        cout << "Graph is empty" << endl;
        return;
    }

    Vertex* stack1[10];
    int top = -1;
    Vertex* srcNode = SearchVertex(src);

    if (srcNode == NULL) {
        cout << "Source vertex not found" << endl;
        return;
    }

    cout << "Depth First Search starting from vertex " << src << ": ";

    
    stack1[++top] = srcNode;
    srcNode->visited = true;
    cout << srcNode->data << " "; // Print the source vertex
    
    while (top != -1) {
        Vertex* currVertex = stack1[top--];

        Edge* currEdge = currVertex->EdgeList;
        while (currEdge != NULL) {
            if (!(currEdge->ver->visited)) {
                cout << currEdge->ver->data << " "; // Print the connected vertex
                
                    stack1[++top] = currEdge->ver;

                currEdge->ver->visited = true;
            }
            currEdge = currEdge->next;
        }
    }
    cout << endl;

    // Reset visited flag for all vertices
    Vertex* resetVertex = head;
    while (resetVertex != NULL) {
        resetVertex->visited = false;
        resetVertex = resetVertex->next;
    }
}




int main (){
         string a;
        cout << "What type of Graph do you want to build (Directed or Undirected)" <<endl;
          cin>>a;


    int n;
    do {
        
        if(a=="undirected" || a == "Undirected" || a == "UNDIRECTED"){
           cout << endl << "Enter 1 to Add Vertex of Undirected " << endl << "Enter 2 to Add an Edge of Undirected" << endl << "Enter 3 to Print Vertex List of Undirected" << endl << "Enter 4 to Print Connected Vertices of Undirected" << endl <<  "Enter 5 to find path of Undirected" << endl << "Enter 6 to Find Degree of Undirected" << endl  << "Enter 7 to traverse by BFS" << endl << "Enter 8 to traverse by DFS" << endl << "Enter 9 to Quit" << endl;
        cin >> n;

        
        if (n == 1){
            AddVertex();
        } else if (n == 2){
      
             AddEdge_Of_Undirected();
          
        } else if (n == 3){
            printVertex();
        }  else if (n == 4){
            PrintConnectedVertices_Of_Undirected();
     
        } else if (n == 5){
            int src;
            cout<<"enter source";
            cin>>src;
            int dest;
            cout<<"enter destination";
            cin>>dest;
            findPath_Of_Undirected(src, dest);
           
        }
         else if (n == 6){
          int degree = Degree();
            cout<< "The Degree Of the Vertex is : " <<  degree << endl;
            
        }
          
          else if (n == 7){
              int src;
              cout<<"enter any vertex";
              cin>>src;
              BFS(src);
            
            }
             else if (n == 8){
              int src;
              cout<<"enter any vertex";
              cin>>src;
              DFS(src);
        }     
        }
        else{
           cout <<"Enter 1 to Add Vertex of Directed " << endl << "Enter 2 to Add an Edge of Directed" << endl << "Enter 3 to Print Vertex List of Directed" << endl << "Enter 4 to Print Connected Vertices of Directed" << endl <<  "Enter 5 to find path of Directed" << endl << "Enter 6 to Find InDegree and OutDegree of Directed" << endl  << "Enter 7 to traverse by BFS" << endl << "Enter 8 to traverse by DFS" << endl << "Enter 9 to Quit" << endl;
        cin >> n;
           if (n == 1){
            AddVertex();
        } else if (n == 2){
      
             AddEdge_Of_Directed();
          
        } else if (n == 3){
            printVertex();
        }  else if (n == 4){
            PrintConnectedVertices_Of_Undirected();
     
        } else if (n == 5){
            int src;
            cout<<"enter source";
            cin>>src;
            int dest;
            cout<<"enter destination";
            cin>>dest;
            findPath_Of_Undirected(src, dest);
           
        }
         else if (n == 6){
          int Outdegree=OutDegree();
            cout<< "The Out Degree Of Vertex is : "  << Outdegree << endl;
             int Indegree=InDegree();
            cout<< "The InDegree Of Vertex is : "  << Indegree << endl;
        }

           else if (n == 7){
              int src;
              cout<<"enter any vertex";
              cin>>src;
              BFS(src);
            
            }
             else if (n == 8){
              int src;
              cout<<"enter any vertex";
              cin>>src;
              DFS(src);
            
        }  

        }
    } while (n != 9);
}


