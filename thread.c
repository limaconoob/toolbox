#include <pthread.h>
#include <pthread.h>
#include <stdio.h>

void *inc_x2(void *x_void_ptr)
{ int *x_ptr = (int*)x_void_ptr;
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  *x_ptr += 2;
  printf("2::%d\n", *x_ptr);
  return NULL; }


void *inc_x(void *x_void_ptr)
{ int *x_ptr = (int*)x_void_ptr;
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  *x_ptr += 1;
  printf("1::%d\n", *x_ptr);
  return NULL; }

int main()
{ int x = 0, y = 0;
  pthread_t inc_x_thread;
  pthread_t inc_x2_thread;
  if (pthread_create(&inc_x_thread, NULL, inc_x, &x))
  { fprintf(stderr, "Error creating thread\n");
    return 1; }
  if (pthread_create(&inc_x2_thread, NULL, inc_x2, &x))
  { fprintf(stderr, "Error creating thread\n");
    return 1; }
  while (y < 100)
  { y += 1; }
  printf("y increment finished\n");
  if (pthread_join(inc_x_thread, NULL))
  { fprintf(stderr, "Error joining thread\n");
    return 2; }
  printf("x: %d, y: %d\n", x, y); }
