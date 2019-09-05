#include <iostream>
#include <cstring>
using namespace std;
typedef struct node{
    char data;
    struct node *next;
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
        if(this->isEmpy()){
            this->current = this->tail = this->head = element;
        }
        else{
            if(this->current == this->tail){
                this->current->next = element;
                this->tail = element;
                this->current = element;
            }
        }
        this->size +=1; 
    }
    void showAll(){
        Node *aux = this->head;
        while(this->head != NULL){
            cout<<this->head->data;
            this->head = this->head->next;
        }
        cout<<"\n";
        this->head = aux;
    }
};
void append(List *list1 ,List *list2){
    list1->current->next = list2->head;
    list1->tail = list2->tail;
    list1->current = list2->tail;
}
List *homeF(int *position,List *mainList ,char *str){
    List *aux = new List();
    *position+=1;
    while(str[*position]!='\0' && str[*position] != ']' && str[*position] != '['){  
        if(str[*position]!=']'){
            aux->add(str[*position]);
        }
        *position+=1;
    }
    if(!aux->isEmpy()){
        append(aux,mainList);
        delete(mainList);
    }
    else{
        aux = mainList;
    }
    return aux;
}
void result(char *str){
    List * list = new List();
    for(int i = 0;str[i]!='\0';i++){
        if(str[i] == '['){
            list = homeF(&i,list,str);
        }
        else if(str[i] != ']'){
            list->add(str[i]);
        }
    }
    list->showAll();
    delete(list);
}
void preenche(char *str,List *list){
    for(int i = 0;str[i]!='\0';i++){
        list->add(str[i]);
    }
}
int main(){
    char str[1000001];
    scanf("%s", str);
    result(str);
    return 0;
}