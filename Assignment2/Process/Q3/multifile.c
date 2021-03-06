#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	int ret;
    //int returni;
	int child1=fork();
	int child2,child3,child4,child5;
	char *p;
	char *pp;
	pp="./p.out";
	p="p.out"; 
	if(child1<0||child2<0||child3<0)
	{
	perror("fork");
	exit(1);
	}
	if(child1==0)
	{ 
	execlp("gcc","gcc","-c","cube.c",NULL);
	printf("Compilation of cube.c is completed\n");
    	}
    	else
    	{
    	waitpid(child1, &ret, 0);
    	}

	child2=fork();
	if(child2==0)
	{
    	execlp("gcc","gcc","-c","multiply.c",NULL);
	printf("Compilation of multiply.c is completed\n");
	}
    	else
    	{
	waitpid(child2, &ret, 0);
    	}
	child3=fork();
	if(child3==0)
	{
    	execlp("gcc","gcc","-c","test.c",NULL);
	printf("Compilation of test.c is completed\n");
	}
    	else
    	{
	waitpid(child3, &ret, 0);
    	}
	child4=fork();
	if(child4==0)
	{
  	execlp("gcc","gcc","cube.o","multiply.o","test.o","-o","p.out",NULL);
	printf("Linking is completed\n");
	printf("Execution:\n");
	}
    	else
    	{
	waitpid(child4, &ret, 0);
	  } 
	execl("./p.out", "./p.out", NULL); 	 
	exit(0);
}