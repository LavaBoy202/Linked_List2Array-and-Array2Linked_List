#include <assert.h>
#include <stdlib.h>
#include "array-tools.h"
#include "read-ints.h"
#include "convert.h"

int main(void) {
  int len_in = 0;
  int *arr_in = read_ints(&len_in);
  struct llist *lst = array_to_list(arr_in, len_in);
  list_print(lst);
  int len_out = 0;
  int *arr_out = list_to_array(lst, &len_out);
  assert(len_in == len_out);
  if (len_in > 0) {
    assert(arrays_equal(arr_in, arr_out, len_in));
    free(arr_in);
    free(arr_out);
  }
  list_destroy(lst);
}
