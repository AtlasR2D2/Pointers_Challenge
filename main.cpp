#include <iostream>

using namespace std;

void print(const int *const array,size_t size);
int *apply_all(const int *const array1,size_t size1,const int *const array2,size_t size2);

int main(){
	
	int array1 [] {1,2,3,4,5};
	int array2 [] {10,20,30};
	
	cout << "Array 1: ";
	print(array1,5);
	
	cout << "Array 2: ";
	print(array2,3);
	
	int *results = apply_all(array1,5,array2,3);
	
	cout << "Result: ";
	print(results,15);
	
	delete [] results;
	
	return 0;
}

void print(const int *const array,size_t size){
	cout << "[";
	for (size_t i {0};i<size;++i) {
		cout << array[i];
		if (i != size - 1)
			cout << ", ";
	}
	cout << "]"; 
	cout << endl;
}

int *apply_all(const int *const array1,size_t size1,const int *const array2,size_t size2){
	int *new_storage {nullptr};
	
	new_storage = new int [size1 * size2];
	for (size_t i {0};i<size1;++i){
		for (size_t j {0};j<size2;++j){
			*(new_storage+i*size2+j)=array1[i] * array2[j];
		}
	}
	return new_storage;
}