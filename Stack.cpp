#include <iostream>
#include <string>
using namespace std;
typedef struct node{
    char data;
    struct node *link;
}Node;
class Stack{
    int size;
    public:
        Node *top;
        Stack();
        void push(char value);   
        char pop();
        int length(){
            return size;
        };
        char showTop(){
            if(top == NULL)
                exit(-1);
            return top->data;
        }
        bool isEmpy(){
            if(top != NULL)
                return false;
            else 
                return true;
        }
};
Stack::Stack(){
    size = 0;
    top = NULL;
}
void Stack :: push(char value){
    Node *temp = new Node();
    temp->data = value;
    temp->link = top;
    top = temp;
    this->size += 1;
}
char Stack :: pop(){
    if(top == NULL){
        cout<<"pilha vazia \n";
        exit(-1);
    }
    int value = this->top->data;
    Node *aux = this->top->link;
    delete(this->top);
    top = aux;
    this->size -=1;
    return value;
}
bool isOpenCharacter(char ch){
    if(ch == '}' || ch == ']'|| ch == '>' || ch == ')')
        return false;
    else
        return true;
}
bool isExp(char ch){
    if(ch == '}' || ch == ']'|| ch == '>' || ch == ')')
        return true;
    if(ch == '{' || ch == '[' || ch == '<' || ch == '(')
        return true;
    else 
        return false;
}
void keying(Stack *open, Stack *close,char ch){
   if(isExp(ch)){
       if(isOpenCharacter(ch)){
           open->push(ch); 
       }
        else{
            close->push(ch);
        }
    }
}
bool checkPossible(Stack *open,Stack *close){
    return open->length() == close->length();
}
bool sameType(char open , char close){
    if(open == '<' && close == '>')
        return true;
    if(open == '{' && close == '}')
        return true;
    if(open == '[' && close == ']')
        return true;
    if(open == '(' && close == ')')
        return true; 
    else
        return false;
}
void resolution(char *in){
    Stack *open = new Stack();
    Stack *close = new Stack();
    int count = 0;
    for(int i = 0; in[i] != '\0';i++){
         keying(open,close,in[i]);
         if(!open->isEmpy() && !close->isEmpy()){
             if(!sameType(open->pop(),close->pop()))
                 count+=1;
         } 
    }
    if(!checkPossible(open,close)){
        cout<<"Impossible"<<"\n";
    }
    else
        cout<<count<<"\n";

    delete(open);
    delete(close);
}

int main(){
    char str[1000000];
    scanf("%[^\n]",str);  
    resolution(str);
    return 0;
}