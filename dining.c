#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
sem_t chopstick[5];
void *phil(void *);
void eat(int);
int main()
{
  int n[5];
  pthread_t t[5];
  for (int i = 0; i < 5; i++)
  {
    sem_init(&chopstick[i], 0, 1);
  }
  for (int i = 0; i < 5; i++)
  {
    n[i] = i;
    pthread_create(&t[i], NULL, phil, (void *)&n[i]);
  }
  for (int i = 0; i < 5; i++)
  {
    pthread_join(t[i], NULL);
  }
}
void *phil(void *n)
{
  int ph = *(int *)n;
  printf("Philosopher %d wants to eat\n", ph);
  printf("Philosopher %d tries to pick up the left chopstick\n", ph);
  sem_wait(&chopstick[ph]);
  printf("Philosopher %d picks up the left chopstick \n", ph);
  sem_wait(&chopstick[(ph + 1) % 5]);
  printf("Philosopher %d picks up the right chopstick\n", ph);
  eat(ph);
  sleep(2);
  printf("Philosopher %d has finished eating\n", ph);
  sem_post(&chopstick[(ph + 1) % 5]);
  printf("Philosopher %d leaves the right chopstick\n", ph);
  sem_post(&chopstick[ph]); // signal increment
  printf("Philosopher %d leaves the left chopstick\n", ph);
}
void eat(int ph)
{
  printf("Philosopher %d begins to eat!\n", ph);
}