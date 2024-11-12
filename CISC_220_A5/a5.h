#ifndef A5_H
#define A5_H

#include <stdlib.h>

size_t strfreq(const char *s, char c);

char *strrepeat(const char *s, size_t n);

void qstr_echo(struct qstr *s);

void qstr_rmlast(struct qstr *s, char c);

struct qstr *qstr_split_at(struct qstr *s, size_t index);

#endif