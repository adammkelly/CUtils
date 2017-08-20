#include <stdio.h>
#include <malloc.h>
#include "slist.h"

typedef struct test_slist {
  slist_t list_ptr;
  int data;
} test_t;

slist_t list;
slist_t list2;
test_t search;

int
search_compare(slist_t *elm1, slist_t *elm2)
{
    test_t *test1 = NULL,
           *test2 = NULL;

    test1 = (test_t *)elm1;
    test2 = (test_t *)elm2;

    return (test1->data == test2->data);
}

int main(int argc, char const *argv[]) {

  test_t *data = NULL,
         *data2 = NULL,
         *data3 = NULL,
         *data4 = NULL;

  slist_init(&list);
  slist_init(&list2);

  /* Add to list */
  data = malloc(sizeof (*data));
  if (data) {
    data->data = 1;
    slist_add(&list, &data->list_ptr);
  }

  /* Add to list */
  data2 = malloc(sizeof (*data2));
  if (data2) {
    data2->data = 2;
    slist_add(&list, &data2->list_ptr);
  }

  /* Add to list */
  data3 = malloc(sizeof (*data3));
  if (data3) {
    data3->data = 3;
    slist_add(&list, &data3->list_ptr);
  }

  search.data = 1;
  slist_t *found_ptr = slist_find(&list, &search.list_ptr, search_compare);

  printf("Found ptr element: %p\n", found_ptr);

  /* Add to list2 */
  data4 = malloc(sizeof (*data4));
  if (data4) {
    data4->data = 4;
    slist_add(&list2, &data4->list_ptr);
  }

  printf("============ FINAL DUMP - list count %d\n", list.count);
  DUMP_SLIST(&list);


  printf("Removing %p from list\n", data);
  slist_remove(&list, &data->list_ptr);

  printf("============ REMOVE DUMP - list count %d\n", list.count);
  DUMP_SLIST(&list);


  printf("============ LIST2 DUMP - list2 count %d\n", list2.count);
  DUMP_SLIST(&list2);

  return 0;
}
