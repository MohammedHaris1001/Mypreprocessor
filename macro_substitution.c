#include"header.h"
void macro_substitution(FILE *fp,FILE *fp1)
{
	char macro[100][100];
	char value[100][100];
	char arg[100][100][100];
	int argc[100]={0};
	int count=0;


	char line[1000];
	while(fgets(line,sizeof(line),fp))
	{
		char *p=line;
		while(*p==' ')
			p++;
		if(strncmp(p,"#define",7)==0)
		{
			int i=7;
			int j=0;
			while(p[i]==' ')
				i++;
			while(p[i]!=' ' && p[i]!='\n' && p[i]!='(')
				macro[count][j++]=p[i++];
			macro[count][j]='\0';

			if(p[i]=='(')
			{
				i++;
				while(p[i]!='\n' && p[i]!=')')
				{
					j=0;
					while(p[i]==' ' || p[i]==',')
						i++;
					while(p[i]!=')' && p[i]!='\n' && p[i]!=',')
					{
						arg[count][argc[count]][j++]=p[i++];
					}
					arg[count][argc[count]][j]='\0';
					if(j>0)
						argc[count]++;
				}
				if(p[i]==')')
					i++;
			}

			while(p[i]==' ')
				i++;
			j=0;
			while(p[i]!='\n')
				value[count][j++]=p[i++];
			value[count][j]='\0';
			count++;

		}
		else
		{
			int i=0;
			while(line[i]!='\0')
			{
				int flag=0,k,len;
				for(k=0;k<count;k++)
				{
					len=strlen(macro[k]);
					if(strncmp(&line[i],macro[k],len)==0 &&
							(i==0 || (line[i-1]<'a' || line[i-1]>'z') && (line[i-1]<'A' || line[i-1]>'Z') && (line[i-1]<'0' || line[i-1]>'9') && line[i-1]!='_') && (line[i+len]<'a' || line[i+len]>'z') && (line[i+len]<'A' || line[i+len]>'Z') && (line[i+len]<'0' || line[i+len]>'9') && line[i+len]!='_')
					{
						if(argc[k]==0)
						{
							fputs(value[k],fp1);
							i=i+len;
						}
						else
						{
							char actual[100][100];
							int a=0,b,x;
							int after_name=i+len;
							i=after_name;
							while(line[i]==' ')
								i++;
							if(line[i]!='(')
							{
								fputs(macro[k],fp1);
								i=after_name;
								flag=1;
								break;
							}
							i++;

							while(line[i]!=')'  && line[i]!='\0')
							{
								b=0;
								while(line[i]==' ' || line[i]==',')
									i++;
								while(line[i]!=',' && line[i]!=')' && line[i]!='\0')
									actual[a][b++]=line[i++];
								actual[a][b]='\0';
								a++;
							}
							if(line[i]==')')
								i++;
							x=0;
							while(value[k][x] != '\0')
							{
								int replaced = 0;

								for(int y = 0; y < argc[k]; y++)
								{
									len = strlen(arg[k][y]);

									if(strncmp(&value[k][x], arg[k][y], len) == 0 &&
											(x == 0 || !((value[k][x-1] >= 'a' && value[k][x-1] <= 'z') ||
												     (value[k][x-1] >= 'A' && value[k][x-1] <= 'Z') ||
												     (value[k][x-1] >= '0' && value[k][x-1] <= '9') ||
												     value[k][x-1] == '_')) &&
											!((value[k][x+len] >= 'a' && value[k][x+len] <= 'z') ||
												(value[k][x+len] >= 'A' && value[k][x+len] <= 'Z') ||
												(value[k][x+len] >= '0' && value[k][x+len] <= '9') ||
												value[k][x+len] == '_'))
									{
										fputs(actual[y], fp1);
										x += len;
										replaced = 1;
										break;
									}
								}

								if(replaced == 0)
								{
									fputc(value[k][x], fp1);
									x++;
								}
							}
						}
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					fputc(line[i],fp1);
					i++;
				}
			}
		}
	}	
}
