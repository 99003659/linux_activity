#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

void handler_for_int(int signo) {
  printf("You can't interrupt me\n");
  exit(0);
}
void handler_for_quit(int signo) {
  printf("You can't quit me\n");
  exit(0);
}
void handler_for_tstp(int signo) {
  printf("You can't suspend me\n");
  exit(0);
}
void handler_for_term(int signo) {
  printf("You may terminate me, but please wait\n");
  exit(0);
}

int main() {
 int pid; 
  
     //get child process
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0)
		{                            //child
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;); 
    } 
  
	 if (pid == 0)
	 {
  printf("Welcome\n");// getpid());
  signal(SIGINT, handler_for_int);
  signal(SIGQUIT, handler_for_quit);
  signal(SIGTERM, handler_for_term);
  signal(SIGTSTP, handler_for_tstp);
  for(;;);
  }
   else 
    { 
        printf("\nPARENT: sending SIGHUP\n\n");  //pid hold id of child
        kill(pid, SIGHUP); 
  
        sleep(1); 
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(1);
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(1); 
    } 
  return 0;
}
