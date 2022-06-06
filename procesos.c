#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

int main(){
  struct timeval start, end;
  long secs_used, micros_used;

  gettimeofday(&start, NULL);
  int pid =fork();
  if(pid == 0){
    gettimeofday(&end, NULL);
    secs_used=(end.tv_sec - start.tv_sec);
    micros_used = ((secs_used*1000000) + end.tv_usec) - (start.tv_usec);
    printf("microsegundos usados: %d\n", micros_used);
  }

  return 0;
}
