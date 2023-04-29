#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

void left_part(int left_depth){ //recursive function to print  left childs of a parent

    if(left_depth==0) return;
    int temp_parent_id = (int) getpid(); //gets temporary parent id to use in output
    int rc3 = fork();
    
    if(rc3<0){
        exit(1);
    }
    else if(rc3==0){
        printf("Left child (id: %d) of %d\n", (int) getpid(), temp_parent_id); //if rc is child, it prints
        left_part(--left_depth); 
    }
    else{
        int wc = wait(NULL); //parent waits for child to terminate
    }

}

void q2_tree(int right_depth, int left_depth){ //same as q1 but uses left_part function to print left childs

    int parent_pid = (int) getpid(); //gets parent ID to show in output
    int temp_left_depth = left_depth; //temporary left depth to use in left_part function
    int rc = fork();
    if(rc<0){
        exit(1);
    }

    else if(rc==0){ //first child created with fork system call is the left one
        printf("Left child (id: %d) of %d\n", (int) getpid(), parent_pid);
        left_part(--temp_left_depth); //after printing the first child, it goes to the left_part
                                        //function to create its left childs
    }
    
    else if(rc>0 && right_depth!=0){

        int rc2 = fork();

        if(rc2<0){
            exit(1);
        }

        else if(rc2==0){ // right child
            printf("Right child (id: %d) of %d\n", (int) getpid(), parent_pid);
            q2_tree(--right_depth, left_depth); //used recursive function to create every left and right child
        }
        else{
            int wc = wait(NULL); //parent waits for child to terminate
        }
    }
}
    
int main(){

    int right_depth;
    int left_depth;
    printf("Print the right depth of the tree: ");
    scanf("%d", &right_depth);
    printf("Print the left depth of the tree: ");
    scanf("%d", &left_depth);

    q2_tree(right_depth, left_depth);

}