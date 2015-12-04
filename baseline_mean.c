#include "stdio.h"
//Takes input from a file and stores it in input_array
int input(long double* input_array, char* input) {
	FILE *fp;
	fp=fopen(input,"r");
	fscanf(fp,"%Lg",&input_array[0]);
	int i=1;
	while(!feof(fp)) {
		fscanf(fp,"%Lg",&input_array[i]);
		i++;
	}
	fclose(fp);
	return i-1;
}
//Puts samples and time output in the file
void output(long double* input_array, int size, char* output) {
	FILE *fp;
	int j=0;
	fp=fopen(output,"w");
	for(j=0;j<size;j++) {
		fprintf(fp,"%Lg\n",input_array[j]);
	}
	fclose(fp);
}

void meanBaseline(long double* input_array, int size) {
	int i=0;
	long double mean=0;
	for(i=0;i<size;i++) {
		mean += input_array[i];
	}
	mean = mean/(long double)size;
	for(i=0;i<size;i++) {
		if(input_array[i]!=0) 
			input_array[i] -= mean;
	}
}	

int main(int argc,char* argv[]) {
	if(argc != 3){
		printf("Please enter the input and output file respectively \n");
		return 0;
	}
	long double input_array[22000];
	int size;
	size = input(input_array, argv[1]);
	meanBaseline(input_array,size);
	output(input_array,size,argv[2]);
	return 0;
}

