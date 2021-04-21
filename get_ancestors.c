#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){
	if(argc < 2){
		
		printf(2, "You Must Enter One Number!\n");
		exit();
	}

	if(argc == 2){
        char ans[100];
        strcpy(ans, "");
		int saved_ebx, number = atoi(argv[1]);
        asm volatile(   
			"movl %%ebx, %0;" // saved_ebx = ebx
			"movl %1, %%ebx;" // ebx = number
			: "=r" (saved_ebx)
			: "r"(number)
		);
        int child1_pid = fork();
        if (child1_pid != 0){
            printf(1, "My id: %d\n", getpid());
            get_ancestors(number, ans, 100);
            printf(1, "my parent id: %s\n", ans);
            wait();
        }
        asm("movl %0, %%ebx" : : "r"(saved_ebx)); // ebx = saved_ebx -> restore
		exit();  	
    }
    printf(1 , "You Must Enter One Number. Bad Read\n");
    exit();
}