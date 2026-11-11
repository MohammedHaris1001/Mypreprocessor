#include"header.h"
int main(int argc,char **argv)
{
	FILE *fp,*fp1;
	char s[100];
	if(argc!=2)
	{
		printf("usage: ./mypreprocessor input.c\n");
		return 1;
	}
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("file not present\n");
		return 1;
	}
	strcpy(s,argv[1]);
	s[strlen(s)-2]='\0';
	strcat(s,".i");

	fp1=fopen("temp1.i","w");
	if(fp1==0)
	{
		printf("file not present\n");
		fclose(fp);
		return 1;
	}
	comment_removal(fp,fp1);
	fclose(fp);
	fclose(fp1);


	fp=fopen("temp1.i","r");
	if(fp==0)
	{
		printf("file not present\n");
		return 1;
	}
	fp1=fopen("temp2.i","w");
	if(fp1==0)
	{
		printf("file not present\n");
		fclose(fp);
		return 1;
	}
	file_inclusion(fp,fp1);
	fclose(fp);
	fclose(fp1);

	fp=fopen("temp2.i","r");
	if(fp==0)
	{
		printf("file not present\n");
		return 1;
	}
	fp1=fopen(s,"w");
	if(fp1==0)
	{
		printf("file not present\n");
		fclose(fp);
		return 1;
	}
	macro_substitution(fp,fp1);
	fclose(fp);
	fclose(fp1);

	remove("temp1.i");
	remove("temp2.i");

	printf("preprocessed file generated: %s\n",s);
	return 0;
}



