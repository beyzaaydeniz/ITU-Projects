#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

void q1_tree(int right_depth){

    int parent_pid = (int) getpid(); //gets parent ID to show in output
    int rc = fork();
    if(rc<0){
        exit(1);
    }

    else if(rc==0){ //first child created with fork system call is the left one
        printf("Left child (id: %d) of %d\n", (int) getpid(), parent_pid);
    }
   
    else if(rc>0 && right_depth!=0){

        int rc2 = fork(); //creates right child

        if(rc2<0){
            exit(1);
        }

        else if(rc2==0){ // right child
            printf("Right child (id: %d) of %d\n", (int) getpid(), parent_pid);
            q1_tree(--right_depth); //used recursive function to create every left and right child
        }
        else{ //parent waits for child to terminate
            int wc = wait(NULL);
        }
    }
}

int main(){
    int right_depth;
    printf("Print the right depth of the tree: ");
    scanf("%d", &right_depth);
    printf("Root: %d\n", getpid());
    q1_tree(right_depth);
}