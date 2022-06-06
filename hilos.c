# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<pthread.h>
struct timeval start , end ;
long secs_used, micros_used;

void * hilo ( void * arg ) {
	gettimeofday (&end , NULL ) ;
	secs_used =( end.tv_sec -  start.tv_sec) ;
	micros_used= ((secs_used *1000000)+ end.tv_usec) - (start.tv_usec) ;

	printf (" micros usados:%d\n" , micros_used) ; /* Tiempo medio en m i c r o s e g u n d o s */


}
int main () {
	pthread_t h ;

	gettimeofday (&start, NULL );
	pthread_create (& h , NULL , hilo , NULL ) ;
    	pthread_join (h , NULL );
	
}	
