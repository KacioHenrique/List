//
//  main.cpp
//  Hash
//
//  Created by Kacio on 12/09/19.
//  Copyright © 2019 Kacio. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#define input 15
#define com 3
#define M 101

long long int sumString(string str){
    long long int sum = 0;
    int i = 1;
    for (std::string::iterator it=str.begin();it!=str.end(); ++it,i++){
        sum+=(int)*it * i;
    }
    
    return sum;
}

class Hash{
    public:
    string table[M];
    int size;
    Hash(){
        this->size = 0;
    }
    int hash(string key){
        return h(key) % M;
    };
    long long int h(string key){
        return (sumString(key)*19) % M;
    };
    void insert(string value,int index){
        if(this->table[index].empty()){
            this->table[index] = value;
            this->size++;
        }
        else{
            cout<<"null"<<"\n";
        }
    }
    void deleteHash(string key){
        if(!this->table[this->hash(key)].empty()){
            this->table[this->hash(key)].clear();
            this->size--;
        }
    }
    void show(){
        cout<<this->size<<"\n";
        for(int i = 0 ; i < M ;i++){
            if(!this->table[i].empty())
                cout<<i<<":"<<this->table[i]<<"\n";
        }
    }
};

void colision(Hash &dicio,string key){
    int j = 1;
    while(j<20 ){
        
    }
}
typedef struct comand{
    string type;
    string name;
}Comand;

Comand *create(char *text){
    Comand *comand = new Comand();
    return comand;
}
Comand *split(string str){
    Comand *comands = new Comand();
    comands->type = str.substr(0,str.find(":"));
    comands->name = str.substr(str.find(":")+1,str.length());
    return comands;
}
void resulotion(Comand *in ,Hash &dicio){
    if(in->type != "ADD"){
        dicio.deleteHash(in->name);
    }
    else{
        dicio.insert(in->name, dicio.hash(in->name));
    }
}
int main(int argc, const char * argv[]) {
    Hash dicio = Hash();
    int n;
    string text;
    cin>>n;
    while (n) {
        cin>>text;
        resulotion(split(text),dicio);
        n--;
    }
    dicio.show();
}
