#include<stdio.h>
#include<stdlib.h>
typedef struct Arrays{
	int* array;
	int size;
	int length;
}Array;

void creat(Array* a,int size){
	a->array = calloc(size,sizeof(int));
	a->size = size;
	a->length = 0;
}

void add(Array* a,int element){
	if(a->length == a->size){
		(a->size)++;
		a->array = realloc(a->array,a->size*sizeof(int));
	}
	a->array[(a->length)++] = element;
}

void insert(Array* a,int element,int position){
	if( position > a->size){return;}
	if(a->length == a->size){
		(a->size)++;
		a->array = realloc(a->array,a->size*sizeof(int));
	}
	for(int i = a->length ; i>=position ; i--){
		(a->array)[i+1] = (a->array)[i];
	}
	(a->array)[position] = element;
	(a->length)++;
}

void del(Array* a,int position){
	for(int i = position ; i<= a->length ; i++){
		a->array[i] = a->array[i+1];
	}
	a->length--;
}

int main(){
	printf("| Demo dynamic array using C |\n");
	/*Testing*/
	Array a;
	printf("Creating an empty array...\n");
	creat(&a,1);
	printf("oringinal length : %d\n\nAdding 10 elements...\n",a.length);
	for(int i=0;i<10;i++){
		add(&a,i);
	}
	printf("new size : %d\nArray elements: ",a.length);
	
	for(int i=0;i<a.length;i++){
		printf("%d ",(a.array)[i]);
	}
	printf("\n");
	printf("\nRemoving the element at the index 3 ...\n");
	del(&a,3);
	printf("Inserting 4 at the 9th index...\n");
	insert(&a,4,9);
	printf("new size : %d\nArray elements: ",a.length);
	
	for(int i=0;i<a.length;i++){
		printf("%d ",(a.array)[i]);
	}
	printf("\n");
	return 0;
}
