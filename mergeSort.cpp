
#include <iostream>
#include <vector>
using namespace std; 
void print(vector<int> *vet){
    for (int x : *vet) 
        cout << x << " "; 
    cout<<"\n";
}
void copy(vector <int> *vet,vector <int> *vetCopy,int keyVet,int keyVetCopy){
    cout<<"value "<<*(vetCopy->begin()+keyVetCopy);
    for(int k = keyVet,i=keyVetCopy; i < vetCopy->size();k++,i++)
        vet[k] = vetCopy[i];
}
void merge(vector <int> *vet,vector <int> *left,vector <int> *right){
    int i = 0,j = 0,k = 0;
    int p = left->size();
    int q = right->size();
    cout<<p<<" : p "<<"\n";
    cout<<q<<": q "<<"\n";

    while(i < p && j < q){
        cout<<"aqui"<<*(vet->begin()+k);
        if(left[i]<=right[j]){
            vet[k]=left[i];
            i++;
        }else{
            vet[k]=right[j];
            j++;
        }
       
        k++;
    }
    if(!(i<p)){
        copy(vet,right,k,j);
    }
    else{
        copy(vet,left,k,i);
    }
    cout<<"----Vet\n";
    print(vet);
}

void mergeSort(vector <int> *vet){
    int size = vet->size();
    cout<<"tamanho "<<size<<"\n";
    if (size > 1){
        vector<int> left;
        vector<int> right;
        left.assign(vet->begin(),vet->begin()+size/2);
        right.assign(vet->begin()+ size/2,vet->end());
        print(&left);
        print(&right);
        mergeSort(&left);
        mergeSort(&right);
        merge(vet,&left,&right);
    }
}
int main() {    
    int arr[] = {8,3,2,9,7,1,5,4}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    vector<int> vect(arr, arr + n); 
    mergeSort(&vect);
    
    return 0; 
} 