#include "stdio.h"
#include "math.h"
int main( int argc, char *argv[] )
{
	if( argc > 3 || argc < 3)
	{
		printf("Use Proper arguments\n");
		exit(1);
	}
	FILE *fp,*fp2;
	fp=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	long double input_array[20000],output_array[20000];
	int i=0,j;
	do
   	{
      		fscanf(fp,"%Lg",&input_array[i] );
		i++;
   	}
   	while(!feof(fp));
   	long double sum=0;
   	for(i=0;i<12000;i++)
   		sum+=input_array[i];
   	sum/=12000;
   	for(i=0;i<12000;i++)
   	{
   		input_array[i]-=sum;
   		fprintf(fp2,"%Lg\n",input_array[j]);
   	}
   	fclose(fp);
   	fclose(fp2);
   	return 0;
}

