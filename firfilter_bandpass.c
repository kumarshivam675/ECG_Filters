#include "stdio.h"
#include "math.h"
#include "stdlib.h"


void design_bandpass_filter(long double *fir_filter,int n, float f1, float f2)
{
	int m=(n-1)/2,i;
	for(i=0;i<n;i++)
	{
		if(i==m)
			fir_filter[i]=(0.54-(0.46*(cos(2*M_PI*i/(n-1)))))*2*(f2-f1);
		else
			fir_filter[i]=((0.54-(0.46*(cos(2*M_PI*i/(n-1)))))*((sin(f2*2*M_PI*(i-m))-sin(f1*2*M_PI*(i-m)))/(M_PI*(i-m))));
	}
}


void filter(long double *fir_filter, long double* input, long double* output, int n, int len)
{
	int i,j,m=(n-1)/2;
	for(i=0;i<len;i++)
		for(j=0;j<n;j++)
		{
			if(i>=j)
				output[i]+=fir_filter[j]*input[i-j];
		}
}


int main(int argc, char *argv[])
{
	if( argc > 3 || argc < 3)
	{
		printf("Use Proper arguments. Give input and output files respectively\n");
		exit(0);
	}
	FILE *fp,*fp2;
	fp=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	long double input_array[30000],output_array[30000];
	int i=0;
	do
   	{
      		fscanf(fp,"%Lg",&input_array[i] );
		i++;
   	}
   	while(!feof(fp));
   	int j;
   	int taps=101;
	long double fir_filter[taps];
	long int len = i-1;
	long double sampling_freq = 250;
	long double cutoff_freq1 = 10;
	long double cutoff_freq2 = 20;
	design_bandpass_filter(fir_filter,taps,cutoff_freq1/(sampling_freq),cutoff_freq2/(sampling_freq));
	filter(fir_filter,input_array,output_array,taps,len);
	for(j=0;j<len;j++)
		fprintf(fp2,"%Lg\n",output_array[j]);
	fclose(fp);
	fclose(fp2);
	return 0;
}
