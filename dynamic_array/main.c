#include<stdio.h>
#include<stdlib.h>

int* arr;
int size = 1;
int elements = 0;

void init(){
	arr = malloc(size*sizeof(int));
	for(int i=0;i<size;i++){
		*(arr+i)=0;
	}	
}

void add(int element){
	//check if array is full
	if(elements == size){
		size++; 
		int* arr_ = malloc(size*sizeof(int)); // creat new array with extended size
		//migrating old array to newly allocated array
		for(int i=0; i<size-1;i++){
			*(arr_+i) = *(arr+i);
		}
		//swaping pointers
		int* tmp;
		tmp = arr_;
		arr_ = arr;
		arr = tmp;
		free(arr_);
		*(arr+elements) = element; //adding the new element
	}else{
		*(arr+elements) = element;
	}
	elements++;
}

int main(){
	printf("| Demo dynamic array using C |\n");
	init();
	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	for(int i=0;i<size;i++){
		printf("%d\n",*(arr+i));
	}
	return 0;
}
