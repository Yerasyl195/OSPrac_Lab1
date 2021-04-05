#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int c = 0;

void *mythread(void *dummy)
{
  pthread_t mythid;
  mythid = pthread_self();
  c = c + 1;
  printf("Thread %d, Calculation result = %d\n", mythid, c);
  return NULL;
}

int main()
{
  pthread_t thid, thid_2, mythid;
  int result;

  result = pthread_create( &thid, (pthread_attr_t *)NULL, mythread, NULL);
  if (result != 0) {
    printf ("Error on thread create (second thread), return value = %d\n", result);
    exit(-1);
  }
  printf("Second thread created, thid = %d\n", thid);

  result = pthread_create( &thid_2, (pthread_attr_t *)NULL, mythread, NULL);
  if (result != 0) {
    printf ("Error on thread create (third thread), return value = %d\n", result);
    exit(-1);
  }
  printf("Third thread created, thid2 = %d\n", thid_2);

  mythid = pthread_self();
  c = c + 1;
  printf("Thread %d, Calculation result = %d\n", mythid, c);

  pthread_join(thid, (void **)NULL);
  pthread_join(thid_2, (void **)NULL);

  return 0;
}
