/*
 * slist.h
 *
 * Singly Linked List Implementation by Adam Kelly
 * Copyright (c) 2017 - All rights reserved.
 * License: GNU V2/V3
 *
 */

 typedef struct slist {
     void *next;
     int count;
 } slist_t;

typedef int (slist_cb_t)(slist_t *elm1, slist_t *elm2);

 #define DUMP_SLIST(s)  \
      iterate_slist(s); \

void slist_init(slist_t *list);
void slist_add(slist_t *list, slist_t *elm);
void slist_remove(slist_t *list, slist_t *elm);
slist_t *slist_find(slist_t *list, slist_t *search_elm, slist_cb_t *compare);
void iterate_slist(slist_t *list);
