#include <stdio.h>

/*
 * slist_priv.h
 *
 * Singly Linked List Implementation by Adam Kelly
 * Copyright (c) 2017 - All rights reserved.
 * License: GNU V2/V3
 *
 */

#define DEBUG 0
#define debug_print(f_, ...) do { if (DEBUG) \
        printf((f_), __VA_ARGS__); } while (0)
