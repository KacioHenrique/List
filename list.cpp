#include <iostream>
using namespace std;

typedef struct node{
    char data;
    struct node *next;
    struct node *previous;
}Node;

class List{
    public:
        int size;
        Node * head;
        Node * tail;
        Node *current;
    List(){
        this->size = 0;
        this->head = this->tail = NULL;
        this->current = NULL;
    }
    bool isEmpy(){
        if(this->head == NULL && this->tail == NULL)
            return true;
        else 
            return false;
    }
    char movecurrentFoward(){
        char value = ' ';
        if(this->current != NULL){
            value = this->current->data;
            this->current = this->current->next;
        }
        return value;
    }
    char movecurrentBack(){
        char value = ' ';
        if(this->current != NULL){
            value = this->current->data;
            this->current = this->current->previous;
        }
        return value;
    }
    void setcurrentToEnd(){
        this->current = this->tail;
    }
    void setcurrentToBegin(){
        this->current = this->head;
    }
    void add(char data){
        Node *element = new Node();
        element->data = data;
        element->next = NULL;
        element->previous = NULL;
        if(this->isEmpy()){
            this->current = this->tail = this->head = element;
        }
        else{
            this->tail->next = element;
            element->previous = this->tail;
            this->tail = element;
            this->tail->next = NULL;
        }
        this->size +=1; 
    }
    void showAll(){
        Node *aux = this->head;
        while(this->head != NULL){
            cout<<this->head->data;
            this->head = this->head->next;
        }
        cout<<"\n ";
        this->head = aux;
    }
    
    char removeToBegin(){
        Node *element = this->head;
        char value = element->data;
        this->head = this->head->next;
        delete(element);
        this->head->previous = NULL;
        this->size -=1;
        return value;
    }
    char removeToEnd(){
        Node *element = this->tail;
        char value = element->data;
        this->tail = this->tail->previous;
        this->tail->next = NULL;
        delete(element);
        return value;
    }   
    void removeCurrentPosition(){
        Node *aux = this->current;
        if(this->current == this->head){
            this->removeToBegin();
            return;
        }
        else if(this->current == this->tail){
            this->removeToEnd();
            return;

        }
        else if(this->current != NULL){
            this->current->previous->next = aux->next;
            this->current->next->previous = aux->previous;
        }
        this->current = aux->previous;
        delete(aux);
    }
};
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
bool needReplace(List *l){
    l->setcurrentToBegin();
    char begin = l->removeToBegin();
    l->setcurrentToEnd();
    char end = l->current->data;
    while((l->current != l->tail)){
        if(sameType(begin,l->current->data)){
            cout<<begin<<" - "<<l->current->data<<"\n";
            l->removeCurrentPosition();
            return false;
        }
        cout<<l->movecurrentBack()<<"\n";
    }
    return true;
}
void addAllCharInList(List * l,char *str){
    for(int i = 0 ; str[i]!='\0';i++){
        if(str[i]!= ' ') 
            l->add(str[i]);
    }       
}

void result(List *l){
    int count = 0;
    bool p;
    
    while(!l->isEmpy()){
        cout<<p<<"\n";
        p = isOpenCharacter(l->head->data);
        if(!p){
            cout<<"Impossible";
            return;
        }
        else{
            if(needReplace(l)){
                count+=1;
            }
        }
    }
}
int main(){
    List *novo = new List();
    char str[1000001];
    cin.getline(str,1000001);
    addAllCharInList(novo,str);
    result(novo);
    return 0;
}