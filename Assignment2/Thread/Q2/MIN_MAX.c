#include <stdio.h>
#include <string.h>
#include <pthread.h>

int array[1000] = {14, 2, 38, 41, 37, 49, 4, 17, 19, 8, 26, 10, 13, 28, 21, 27, 36, 15, 35, 47, 47, 32, 37, 21, 9, 32, 21, 40, 4, 15, 18, 18, 3, 38, 1, 38, 9, 38  
, 24, 28, 47, 0, 7, 9, 4, 24, 46, 23, 5, 33, 28, 45, 40, 1, 20, 48, 15, 27, 41, 24, 17, 9, 49, 11, 22, 3, 10, 16, 3, 12, 2, 32, 37, 42, 41, 9,  
 33, 36, 9, 33, 41, 43, 23, 25, 25, 17, 42, 305, 37, 16, 7, 7, 42, 41, 2, 46, 16, 47, 47, 36, 9, 18, 25, 12, 49, 21, 43, 45, 30, 23, 36, 16, 31  
, 6, 16, 32, 42, 9, 10, 17, 47, 3, 35, 32, 36, 14, 18, 17, 43, 31, 16, 11, 2, 4, 43, 42, 25, 47, 32, 40, 10, 14, 2, 41, 11, 25, 1, 5, 17, 2, 10, 21, 49, 39, 7, 42, 40, 43, 32, 0, 42, 49, 5, 17, 37, 13, 12, 48, 40, 28, 0, 31, 23, 32, 27, 30, 30, 41, 46, 7, 41, 14, 6, 13, 44, 4, 3, 9,   
3, 13, 35, 0, 3, 29, 40, 5, 20, 16, 31, 40, 15, 41, 7, 32, 14, 37, 40, 17, 33, 31, 5, 25, 24, 10, 48, 41, 3, 21, 29, 19, 22, 0, 39, 47, 32, 17  
, 17, 28, 39, 24, 30, 22, 6, 36, 5, 17, 23, 347, 27, 12, 43, 32, 19, 19, 23, 27, 2, 22, 10, 36, 43, 16, 39, 18, 14, 36, 29, 43, 44, 26, 27, 34,  
 39, 47, 37, 21, 28, 5, 29, 24, 8, 42, 39, 2, 31, 22, 28, 16, 5, 19, 38, 0, 28, 15, 37, 40, 3, 16, 14, 11, 44, 14, 34, 30, 41, 23, 19, 8, 22,   
36, 37, 14, 5, 23, 15, 6, 31, 19, 10, 11, 30, 10, 20, 20, 2, 23, 5, 13, 28, 11, 7, 41, 45, 15, 31, 47, 30, 40, 9, 37, 36, 46, 18, 15, 41, 15,   
15, 41, 40, 41, 43, 45, 37, 44, 47, 13, 13, 41, 14, 26, 43, 20, 49, 23, 49, 22, 15, 18, 9, 35, 31, 11, 41, 30, 15, 29, 33, 13, 34, 36, 48, 7,   
17, 0, 23, 32, 14, 20, 9, 13, 22, 39, 16, 218, 26, 33, 13, 21, 46, 5, 44, 13, 19, 45, 37, 42, 7, 33, 6, 25, 13, 46, 17, 23, 3, 42, 24, 32, 13,   
10, 19, 31, 37, 49, 21, 27, 12, 11, 13, 44, 6, 3, 29, 19, 46, 45, 25, 35, 4, 47, 4, 45, 43, 32, 11, 36, 36, 35, 36, 14, 25, 40, 26, 2, 40, 37,  
 45, 18, 36, 19, 39, 24, 45, 47, 20, 1, 47, 15, 45, 44, 29, 5, 17, 25, 10, 42, 45, 30, 42, 18, 38, 26, 37, 5, 1, 28, 8, 44, 37, 31, 36, 21, 21  
, 7, 3, 31, 48, 20, 38, 29, 38, 12, 23, 2, 32, 346, 30, 44, 22, 16,14, 2, 38, 41, 37, 49, 4, 17, 19, 8, 26, 10, 13, 28, 21, 27, 36, 15, 35, 47, 47, 32, 37, 21, 9, 32, 21, 40, 4, 15, 18, 18, 3, 38, 1, 38, 9, 38  
, 24, 28, 47, 0, 7, 9, 4, 24, 46, 23, 5, 33, 28, 45, 40, 1, 20, 48, 15, 27, 41, 24, 17, 9, 49, 11, 22, 3, 10, 16, 3, 12, 2, 32, 37, 42, 41, 9,  
 33, 36, 9, 33, 41, 43, 23, 25, 25, 17, 42, 30, 37, 16, 7, 7, 42, 41, 2, 46, 16, 47, 47, 36, 9, 18, 25, 12, 49, 21, 43, 45, 30, 23, 36, 16, 31  
, 6, 16, 32, 42, 9, 10, 17, 47, 3, 35, 32, 365, 14, 18, 17, 43, 31, 16, 11, 2, 4, 43, 42, 25, 47, 32, 40, 10, 14, 2, 41, 11, 25, 1, 5, 17, 2, 10, 21, 49, 39, 7, 42, 40, 43, 32, 0, 42, 49, 5, 17, 37, 13, 12, 48, 40, 28, 0, 31, 23, 32, 27, 30, 30, 41, 46, 7, 41, 14, 6, 13, 44, 4, 3, 9,   
3, 13, 35, 0, 3, 29, 40, 5, 20, 16, 31, 40, 15, 41, 7, 32, 14, 37, 40, 17, 33, 31, 5, 25, 24, 10, 48, 41, 3, 21, 29, 19, 22, 0, 39, 47, 32, 17  
, 17, 28, 39, 24, 30, 22, 6, 36, 5, 17, 23, 37, 27, 12, 43, 32, 19, 19, 23, 27, 2, 22, 10, 36, 43, 16, 39, 18, 14, 36, 29, 43, 44, 26, 27, 34,  
 39, 47, 37, 21, 28, 5, 29, 24, 8, 42, 1458, 2, 31, 22, 28, 16, 5, 19, 38, 0, 28, 15, 37, 40, 3, 16, 14, 11, 44, 14, 34, 30, 41, 23, 19, 8, 22,   
36, 37, 14, 5, 23, 15, 6, 31, 19, 10, 11, 30, 10, 20, 20, 2, 23, 5, 13, 28, 11, 7, 41, 45, 15, 31, 47, 30, 40, 9, 37, 36, 46, 18, 15, 41, 15,   
15, 41, 40, 41, 43, 45, 37, 44, 47, 13, 13, 41, 14, 26, 125, 20, 49, 23, 49, 22, 15, 18, 9, 35, 31, 11, 41, 30, 15, 29, 33, 13, 34, 36, 48, 7,   
17, 0, 23, 32, 14, 20, 9, 13, 22, 39, 16, 215, 26, 33, 13, 21, 46, 5, 44, 13, 19, 45, 37, 42, 7, 33, 6, 25, 13, 46, 17, 23, 3, 42, 24, 32, 13,   
10, 19, 31, 37, 49, 21, 27, 12, 11, 13, 44, 6, 3, 29, 19, 46, 45, 25, 35, 4, 47, 4, 45, 43, 32, 11, 36, 36, 35, 36, 14, 25, 40, 26, 2, 40, 37,  
 45, 18, 36, 19, 39, 24, 45, 47, 20, 1, 47, 15, 45, 44, 29, 5, 17, 25, 10, 42, 45, 30, 42, 18, 38, 26, 37, 5, 1, 28, 8, 44, 37, 31, 36, 21, 21  
, 7, 3, 31, 48, 20, 38, 29, 38, 12, 23, 2, 32, 36, 30, 44, 22, 16};

int x = 0;
int Max = 0;
int Min = 0;
int y = 200;

void* find_maxmin(void* arg){
    //     int i;
    // int array[500];
    // for(i = 0; i < 500; i++)
    // {
    //     array[i] = rand();
    // }

    char* pv = arg;
    printf("Welcome -- %s\n", pv);
    for(int i = x; i < y-1; i++){
        if(array[i] > array[i+1])
        {
            if(Max < array[i]){
                Max = array[i];
            }
        }

        else if(array[i] < array[i+1]){
            if(Min > array[i])
            {
                Min = array[i+1];
            }
        }
    }
    x += 200;
    y += 200;
    printf("Max = %d and Min = %d\n", Max, Min);
}



int main(){
    void* status;
    pthread_t pt1, pt2, pt3, pt4, pt5;// thread handle

    pthread_create(&pt1,NULL,find_maxmin,"0-200");
	pthread_create(&pt2,NULL,find_maxmin,"200-400");
    pthread_create(&pt3,NULL,find_maxmin,"400-600");
    pthread_create(&pt4,NULL,find_maxmin,"600-800");
	pthread_create(&pt5,NULL,find_maxmin,"800-1000");
    pthread_join(pt1,&status);
	pthread_join(pt2,NULL);
    pthread_join(pt3,NULL);
	pthread_join(pt4,NULL);
    pthread_join(pt5,NULL);


    printf("thread exit status is :%ld\n", (long)status);
	printf("main--thank you\n");
	return 0;
 
	}