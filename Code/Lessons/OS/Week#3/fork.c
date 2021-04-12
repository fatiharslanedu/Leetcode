#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
int fd[2], nbytes;
pid_t childpid;
char str[1000];
char readbuffer[1000];
int a[5] = {6,4,4,5,3};
int i=0, j=3, result=1;

pipe(fd);

if((childpid = fork()) == -1)
{
perror("fork");
exit(1);
}

if(childpid == 0)
{
/* Child process closes up input side of pipe */
close(fd[0]);

for(i=0;i<5; i++)
result += result*a[ i]*j;

sprintf(str, "%d\n", result);
/* Send "str" through the output side of pipe */
write(fd[1], str, (strlen(str)+1));
close(fd[1]);
exit(0);
}
else
{
/* Parent process closes up output side of pipe */
close(fd[1]);

/* Read in a string from the pipe */
nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
printf("%s", readbuffer);
close(fd[0]);
}

return(0);
}