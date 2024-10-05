#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    if (argc == 1) {
        printf("No program to exec!\n");
        exit(1);
    }

    char** arguments = NULL;
    arguments = malloc(sizeof(char*) * (argc));
    if (arguments == NULL) {
        perror("malloc error");
        exit(1);
    }
    for (int i = 0; i < argc - 2; i++) {
        arguments[i] = argv[i+2];
    }
    arguments[argc - 1] = NULL;

    pid_t child_id, finished_procces;
    int status;

    child_id = fork();
    switch(child_id) {
    case 0:

        execv(argv[1], arguments);    
        perror("fork error");
        exit(1);
    
    case -1:
        perror("fork error");
        exit(1);

    default:
        finished_procces = wait(&status);
        
        if (finished_procces == -1) {
            perror("wait error");
            exit(1);
        }

        if (WIFEXITED(status)){
            printf("Child`s ending code = %d\n", WEXITSTATUS(status));
        }

    }
    free(arguments);
    exit(0);
}