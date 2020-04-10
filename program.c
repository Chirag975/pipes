#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	char str[100];
	printf("Your string :");
	int i=0;
	while(i<10){
	scanf("%c",&str[i]);
	i++;}
	int fd[2];
	write(fd[1],str,strlen(str));
	printf("for wiring in pipe pid is %d: ",getpid());
	int y=strlen(str);
	printf("\nWritten in pipe :%s\n",str);
	for(i=0;i<strlen(str);i++)
		{
		if((int)str[i]>=65 && (int)str[i]<=90)
			{
				str[i]=(int)str[i]+32;
			}
		else if((int)str[i]>=97 && (int)str[i]<=122)
			{
				str[i]=(int)str[i]-32;
			}
		}
	close(fd[0]);
	read(fd[0],str,strlen(str));
	printf("\n\nfor reading in pipe pid is %d for reading in pipe  ",getpid());
	printf("\n\nreading file  :%s\n",str);
}
