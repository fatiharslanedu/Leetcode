#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    while (1)
    {
        char *cmd = get_next_command();
        int child_pid = fork();
        if(child_pid == 0) {
            exec(cmd);
            panic("exec failed!");
        } else {
            wait(child_pid);
        }
    }
    
}