#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include<time.h>

void* current_time(void* arg){
    char* pv = arg;
    time_t t;  
    time(&t);
    printf("\n %s:- Date and time): %s",pv, ctime(&t));
}


int main(){
    void* status;
    pthread_t pt1, pt2, pt3, pt4, pt5;// thread handle

    pthread_create(&pt1,NULL,current_time,"TIME1");
    sleep(2);
	pthread_create(&pt2,NULL,current_time,"TIME2");
    sleep(2);
    pthread_create(&pt3,NULL,current_time,"TIME3");
    sleep(2);
    pthread_create(&pt4,NULL,current_time,"TIME4");
    sleep(2);
	pthread_create(&pt5,NULL,current_time,"TIME5");
    sleep(2);
    pthread_join(pt1,&status);
	pthread_join(pt2,NULL);
    pthread_join(pt3,NULL);
	pthread_join(pt4,NULL);
    pthread_join(pt5,NULL);


    printf("thread exit status is :%ld\n", (long)status);
	printf("main--thank you\n");
	return 0;
 
	
}