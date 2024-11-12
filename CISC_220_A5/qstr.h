#ifndef QSTR_H
#define QSTR_H

// qstr.h

#include <stddef.h>

struct qstr {
    size_t length;
    size_t capacity;
    char *data;
};

/*
 * Default capacity of a newly allocated empty qstr.
 */
static size_t QSTR_DEFAULT_CAPACITY = 8;

/*
 * Returns a pointer to a newly allocated empty qstr.
 * Returns a null pointer if the qstr cannot be allocated.
 */
// struct qstr *qstr_new();

struct qstr *qstr_new(size_t n);

/*
 * Allocates a new struct qstr object having length 0 and a data array of the 
 * specified non-zero capacity with all elements initialized to zero.
 * Returns a pointer to the new object, or NULL if allocation fails.
 */
struct qstr *qstr_alloc(size_t capacity);

/*
 * Returns a pointer to a newly allocated qstr containing the characters
 * copied from a C-style string.
 * Returns an empty qstr if s is NULL.
 * Returns a null pointer if the qstr cannot be allocated.
 */
struct qstr *qstr_fromcstr(const char *s);

/*
 * Deallocates memory allocated for the struct pointed at by s. Both s
 * and its data buffer are deallocated.
 * Does nothing if s is NULL.
 */
void qstr_destroy(struct qstr *s);

char *qstr_cstr(const struct qstr *s);

#endif