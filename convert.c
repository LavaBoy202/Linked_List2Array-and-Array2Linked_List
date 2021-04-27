//A9Q1
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "cs136-trace.h"

// array_to_list(a, len) creates a new linked list with the items in
//   the same order as they occur in a (so a[0] is first in the list)
// note: if a is NULL then len == 0 (and vice versa) and an empty list is
//       returned
// requires: a is a valid array of length len or NULL (when len == 0)
//           len >= 0
// effects: allocates memory: call list_destroy
// time: O(n)
struct llist *array_to_list(const int a[], int len) {
  assert(len >= 0);
  if (len > 0) {
    assert(a);
  }
  struct llist *listt = list_create();
  for (int i = len - 1;i >= 0; i--){
    add_front(a[i], listt);
  }
  return listt;
}

// list_to_array(lst, len) creates and returns a new array with the contents
//   of lst in the same order as they occur in lst so lst->front is in a[0]
// note: modifies *len to store the length of the array
//       if lst is empty, *len becomes 0 and NULL is returned
// effects: may allocte memory (caller must free)
//          modifies *len
// time: O(n)
int *list_to_array(const struct llist *lst, int *len) {
  assert(lst);
  assert(len);
  const struct llnode *node = lst->front;
  while (node) {
    ++*len;
    node = node->next;
  }
  int *a = malloc(*len * sizeof(int));
  const struct llnode *nodes = lst->front;
  int count = 0;
  while (nodes) {
    a[count] = nodes->item;
    nodes = nodes->next;
    count++;
  }
  trace_int(*len);
  if (*len == 0) {
    a = realloc(a, 0 * sizeof(int));
  }
  return a;
}


/////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THE FOLLOWING FUNCTIONS
/////////////////////////////////////////////////////////////////////////////

// see convert.h for documentation

struct llist *list_create(void) {
  struct llist *lst = malloc(sizeof(struct llist));
  lst->front = NULL;
  return lst;
}

void list_destroy(struct llist *lst) {
  assert(lst);
  struct llnode *curnode = lst->front;
  struct llnode *nextnode = NULL;
  while (curnode) {
    nextnode = curnode->next;
    free(curnode);
    curnode = nextnode;
  }
  free(lst);
}

void add_front(int i, struct llist *lst) {
  assert(lst);
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->item = i;
  newnode->next = lst->front;
  lst->front = newnode;
}

void list_print(const struct llist *lst) {
  assert(lst);
  struct llnode *curnode = lst->front;
  if (curnode == NULL) {
    printf("[empty]\n");
    return;
  }
  printf("[");
  while (curnode) {
    printf("%d", curnode->item);
    curnode = curnode->next;
    if (curnode) {
      printf("->");
    }
  }
  printf("]\n");
}
