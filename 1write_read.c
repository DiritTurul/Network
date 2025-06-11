#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
void main()
{
int fd;
char *myfifo="fifo";
char message[1024];
char buffer[1024];
mkfifo(myfifo,0666);
while(1)
{
fd=open(myfifo,O_WRONLY);
memset(message,0,sizeof(message));
printf("Enter data for 2nd program :");
gets(message);
write(fd,message,1024);
close(fd);
if(strcmp(message,"exit")==0)
break;
fd=open(myfifo,O_RDONLY);
memset(buffer,0,sizeof(buffer));
read(fd,buffer,1024);
printf("Received data from 2nd program : %s\n",buffer);
close(fd);
if(strcmp(buffer,"exit")==0)
break;
}
}