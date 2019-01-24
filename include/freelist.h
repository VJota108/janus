#ifndef _FREELIST_H_
#define _FREELIST_H_

#include <pthread.h>

// implementation of a threadsafe free list
struct freelist_t {
  struct freelist_t *next;
  void *data;
};

struct freelist_repo_t {
  /* TODO: Bad naming :( fix later */
  struct freelist_t *free; // This is actually the list of items that have been borrowed
  struct freelist_t *busy; // This is actually the list of items that are "free"
  pthread_mutex_t lock;
  struct freelist_t *_data;
};

/* Could deadlock if there aren't enough networks available. */
void *freelist_get(struct freelist_repo_t *ntr);
void freelist_return(struct freelist_repo_t *ntr, void *net);

struct freelist_repo_t *freelist_create(int size);
void freelist_free(struct freelist_repo_t *ntr);

#endif // _FREELIST_H_
