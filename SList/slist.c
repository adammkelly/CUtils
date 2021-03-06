#include "slist.h"
#include "slist_priv.h"

/*
 * slist.c - Caller is responsible for thread safety/locking.
 *
 * Singly Linked List Implementation by Adam Kelly
 * Copyright (c) 2017 - All rights reserved.
 * License: GNU V2/V3
 *
 */

void
slist_init(slist_t *list)
{
  list->next = NULL;
  list->count = 0;
  debug_print("List init done %p, next: %p!\n", list, list->next);
}

void
slist_add(slist_t *list, slist_t *elm)
{
    // Secure with a lock
    elm->next = list->next;
    list->next = elm;
    list->count++;
    debug_print("List add: %p\n", elm);
}

void
slist_remove(slist_t *list, slist_t *elm)
{
    slist_t *elm_list = list;
    slist_t *prev = NULL;

    // Need to lock from here
    for (elm_list; elm_list != NULL; elm_list = elm_list->next) {

      debug_print("%s: elmlist: %p, elm: %p\n", __FUNCTION__, elm_list, elm);

      if (elm_list == elm) {
        prev->next = elm_list->next;
        list->count--;
        break;
      }
      prev = elm_list;
    }
}

slist_t*
slist_find(slist_t *list, slist_t *search_elm, slist_cb_t *compare)
{
    slist_t *elm_list = list;
    slist_t *found = NULL;

    for (elm_list; elm_list != NULL; elm_list = elm_list->next) {

        debug_print("%s - Searching list - %p\n", __FUNCTION__, elm_list);

        if (compare(search_elm, elm_list)) {
            found = elm_list;
            break;
        }
    }

    return (found);
}

void
iterate_slist(slist_t *list)
{
    int i = 0;
    for (slist_t *l = list; l != NULL; l = l->next) {
      printf("%d: got %p count? %d\n", i, l, list->count);
      i++;
    }
}
