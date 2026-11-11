#include"header.h"
void file_inclusion(FILE *fp,FILE *fp1)
{
	char line[1000];
	while(fgets(line,sizeof(line),fp))
	{
		char *p=line;
		while(*p==' ')
			p++;
		if(strncmp(p,"#include",8)==0)
		{
			char fname[100];
			int i=8;
			while(p[i]==' ')
				i++;
			if(p[i]=='<' || p[i]=='"')
			{
				char start=p[i];
				char end;
				if(p[i]=='<')
					end='>';
				else
					end='"';
				i++;

				int j=0;
				while(p[i]!=end && p[i]!='\0')
				{
					fname[j]=p[i];
					i++;
					j++;
				}
				fname[j]='\0';
				FILE *fd;
				fd=fopen(fname,"r");
				if(fd==0)
				{
					fputs(line,fp1);
				}
				else
				{
				char ch;
				while((ch=fgetc(fd))!=-1)
					fputc(ch,fp1);
				fclose(fd);
				}
			}
			else
				fputs(line,fp1);
		}
		else
			fputs(line,fp1);
	}
}

