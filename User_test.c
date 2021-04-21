#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[]) 
{
    printf(1, "What system call do you like to test? \n");
    printf(1, "1. test get_descendants\n");
    printf(1, "2. test get_ancestors\n");


    char buf[1024];
    read(0, buf, 1024);
    if (atoi(buf) == 1)
    {
      char ans[100];
      strcpy(ans, "");

      int child1_pid = fork();
      if (child1_pid != 0){
        printf(1, "My id: %d\n", getpid());
        get_descendants(getpid(), ans, 100);
        printf(1, "my child id %d: %s\n", getpid(), ans);
        wait();
      }
    }
    else if (atoi(buf) == 2)
    {
      char ans[100];
      strcpy(ans, "");

      int child1_pid = fork();
      if (child1_pid != 0){
        printf(1, "my id: %d\n", getpid());
        get_ancestors(1, ans, 100);
        printf(1, "my parent id: %s\n", ans);
        wait();
      }
    }
    exit();
}