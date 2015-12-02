#include "stdio.h"
#include "math.h"

int input(long double* input_array, char* input) {
	FILE *fp;
	fp=fopen(input,"r");
	fscanf(fp,"%Lg",&input_array[0] );
	int i=1;
	while( !feof(fp) ) {
		fscanf(fp,"%Lg",&input_array[i] );
		i++;
	}
	fclose(fp);
	return i-1;
}

void differentiate (long double* input_array, int size, int freq) {
	int i=0;
	for(i=0;i<size-1;i++) { //Differentiation
		input_array[i]=(input_array[i+1]-input_array[i])*freq;
	}
	for(i=0;i<size-1;i++) { //Double differentiation
		input_array[i]=(input_array[i+1]-input_array[i])*freq;
	}
}

int findMaxIndex (long double* input_array, int prev, int current) {
	int i,index;
	long double max=-100;
	for(i=prev;i<current;i++) {
		if(input_array[i]>max) {
			max = input_array[i];
			index = i;
		}
	}
	if(max<=0)
		return -1;
	return index;
}

int peakDetect(long double* input_array, int* samples, float* time_samples, int size, int window_size, int freq) {
	int current=window_size-1, prev =0, max_index, j=0;
	while (current<size) {
		max_index = findMaxIndex(input_array,prev,current);
		if (max_index !=-1) {
			samples[j]=max_index-5;
			time_samples[j] = (float)samples[j]/(float)freq;
			j++;
		}

		prev = current+1;
		current = current + window_size;
	}
	return j;
}

int main(int argc,char* argv[]) {
	FILE *fp;
	if(argc != 3){
		printf("Please enter the input and output file respectively \n");
		return 0;
	}
	long double input_array[22000];
	int size, freq=250, sample_size, window_size = 175, i, j;
	int samples[200];
	float time_samples[200];
	size = input(input_array, argv[1]);
	differentiate(input_array,size,freq);
	sample_size = peakDetect(input_array,samples,time_samples,size,window_size,freq);
	fp=fopen(argv[2],"w");
	for(j=0;j<sample_size;j++) {
		fprintf(fp,"%d, %f\n",samples[j],time_samples[j]);
	}
	fclose(fp);
	return 0;
}
