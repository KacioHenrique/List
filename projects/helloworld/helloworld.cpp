#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	size_t ileft = 0, iright = 0;
	vector<int> results;
	while (ileft < left.size() && iright < right.size())
	    if (left[ileft] < right[iright])
	        results.push_back(left[ileft++]);
	    else
	        results.push_back(right[iright++]);
	while (ileft  < left.size() ) results.push_back(left [ileft++ ]);
	while (iright < right.size()) results.push_back(right[iright++]);
	return results;
}

vector<int> mergeSort(vector<int>& arr) {
	if (arr.size() <= 1)
		return arr;
	int len = arr.size() / 2;
	vector<int> left (arr.begin(),       arr.begin() + len);
	vector<int> right(arr.begin() + len, arr.end()        );
	return merge(mergeSort(left), mergeSort(right));
}

long int sum(vector<int> vet,int begin,int last){
    long int resut = 0;
    for(int i = begin ; i < last;i++){
        resut+=vet[i]; 
    }
    return resut;
}
int main() {
    vector<int> vet;
    int nChocolate;
    int cupons;
    int value;
    cin>>nChocolate;
    for(int i = 0 ; i < nChocolate;i++){
        cin>>value;
        vet.push_back(value);
    }
    cin>>cupons;
    for(int i = 0 ; i < cupons; i++) 
}