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

 #define DUMP_SLIST(s)  \
      iterate_slist(s); \

void slist_init(slist_t *list);
void slist_add(slist_t *list, slist_t *elm);
void slist_remove(slist_t *list, slist_t *elm);
void iterate_slist(slist_t *list);
