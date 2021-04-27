// It is a transparent structure

struct llnode {
  int item;
  struct llnode *next;
};


struct llist {
  struct llnode *front;
};

// The following applies to all functions
// requires: all lst parameters are valid (not NULL)
// time: (n) is the number of items in the list or array

//////////////////////////////////////////////////////////////////////////////
// functions for you to implement
//////////////////////////////////////////////////////////////////////////////

// array_to_list(a, len) creates a new linked list with the items in
//   the same order as they occur in a (so a[0] is first in the list)
// note: if a is NULL then len == 0 (and vice versa) and an empty list is
//       returned
// requires: a is a valid array of length len or NULL (when len == 0)
//           len >= 0
// effects: allocates memory: call list_destroy
// time: O(n)
struct llist *array_to_list(const int a[], int len);

// list_to_array(lst, len) creates and returns a new array with the contents
//   of lst in the same order as they occur in lst so lst->front is in a[0]
// note: modifies *len to store the length of the array
//       if lst is empty, *len becomes 0 and NULL is returned
// effects: may allocte memory (caller must free)
//          modifies *len
// time: O(n)
int *list_to_array(const struct llist *lst, int *len);

//////////////////////////////////////////////////////////////////////////////
// provided functions
//////////////////////////////////////////////////////////////////////////////

// list_create() creates a new, empty list
// effects: allocates memory: call list_destroy
struct llist *list_create(void);

// list_destroy(lst) destroys lst
// effects: deallocates memory (lst is no longer valid)
// time: O(n)
void list_destroy(struct llist *lst);

// add_front(i, lst) adds i to the front of lst
// effects: modifies lst
void add_front(int i, struct llist *lst);

// list_print(lst) prints out lst to output
// effects: produces output
void list_print(const struct llist *lst);
