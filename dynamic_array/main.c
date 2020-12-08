#include<stdio.h>
#include<stdlib.h>
typedef struct Arrays{
	int* array;
	int size;
	int filled;
}Array;

void creat(Array* a,int size){
	a->array = calloc(size,sizeof(int));
	a->size = size;
	a->filled = 0;
}

void add(Array* a,int element){
	if(a->filled == a->size){
		(a->size)++;
		a->array = realloc(a->array,a->size*sizeof(int));
	}
	a->array[(a->filled)++] = element;
}


int main(){
	printf("| Demo dynamic array using C |\n");
	/*Testing*/
	Array a;
	creat(&a,1);
	printf("oringinal size : %d\n",a.size);
	for(int i=0;i<20;i++){
		add(&a,i);
	}

	printf("new size : %d\nArray elements: ",a.size);
	
	for(int i=0;i<a.size;i++){
		printf("%d ",(a.array)[i]);
	}
	printf("\n");
	return 0;
}
