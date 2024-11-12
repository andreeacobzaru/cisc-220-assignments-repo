#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qstr.h"

/*
 * Allocates a new struct qstr object having length 0 and a data array of the 
 * specified non-zero capacity with all elements initialized to zero.
 * Returns a pointer to the new object, or NULL if allocation fails.
 */
struct qstr *qstr_alloc(size_t capacity) {
    struct qstr *q = malloc(sizeof(struct qstr));
    if (!q) {
        fprintf(stderr, "qstr allocation error");
        return NULL;
    }
    if (capacity == 0) {
        capacity = 1;
    }
    char *buf = calloc(capacity, 1);
    if (!buf) {
        free(q);
        fprintf(stderr, "qstr->data allocation error");
        return NULL;
    }
    q->length = 0;
    q->capacity = capacity;
    q->data = buf;
    return q;
}



struct qstr *qstr_new(size_t n) {
    return qstr_alloc(n + 1);
}


struct qstr *qstr_fromcstr(const char *s) {
    size_t len = strlen(s);
    struct qstr *q = qstr_alloc(len + 1);
    if (q) {
        q->length = len;
        strcpy(q->data, s);
    }
    return q;
}


char *qstr_cstr(const struct qstr *s) {
    char *buf = malloc(s->length + 1);
    strcpy(buf, s->data);
    return buf;
}

void qstr_destroy(struct qstr *s) {
    if (!s) {
        return;
    }
    free(s->data);
    s->length = 0;
    s->capacity = 0;
    s->data = NULL;
    free(s);
}

