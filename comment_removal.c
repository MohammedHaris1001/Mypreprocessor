#include"header.h"
void comment_removal(FILE *fp,FILE *fp1)
{
	char ch,ch1;
	while((ch=fgetc(fp))!=-1)
	{
		if(ch=='/')
		{
			ch1=fgetc(fp);
			if(ch1=='/')
			{
				while((ch=fgetc(fp))!=-1)
				{
					if(ch=='\n')
					{
						fputc('\n',fp1);
						break;
					}
				}
			}
			else if(ch1=='*')
			{
				while((ch=fgetc(fp))!=-1)
				{
					if(ch=='\n')
						fputc('\n',fp1);
					else if(ch=='*')
					{
						ch1=fgetc(fp);
						if(ch1=='/')
							break;
						else if(ch=='\n')
							fputc('\n',fp1);
					}
				}
			}
			else
			{
				fputc(ch,fp1);
				if(ch1!=-1)
					ungetc(ch1,fp);
			}
		}
		else
			fputc(ch,fp1);
	}
}





