#include "qstr.h"
#include "a5.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t strfreq(const char *s, char c) {
    if (!s) {
        return 0;
    }
    size_t count = 0;
    while (*s) {
        if (*s == c) {
            count++;
        }
        s++;
    }
    return count;
}

char *strrepeat(const char *s, size_t n) {
    if (n == 0 || !s) {
        return NULL;
    }
    char *dest = malloc(strlen(s) * n + 1);
    if (!dest) {
        return NULL;
    }
    dest[0] = '\0';
    for (size_t i = 0; i < n; i++) {
        strcat(dest, s);
    }
    return dest;
}

void qstr_echo(struct qstr *s) {
    if (!s) {
        return;
    }
    char *temp_data = malloc(s->capacity);
    if (!temp_data) {
        fprintf(stderr, "qstr_echo->data allocation error");
        return;
    }
    strcpy(temp_data, s->data);

    size_t new_capacity = s->length * 2 + 1;
    char *buf = realloc(s->data, new_capacity);
    if (!buf) {
        fprintf(stderr, "qstr_echo->data reallocation error");
        free(temp_data);
        return;
    }
    s->data = buf;
    s->capacity = new_capacity;

    strcat(s->data, temp_data);
    s->length = strlen(temp_data) * 2;
    free(temp_data);
    temp_data = NULL;
}

void qstr_rmlast(struct qstr *s, char c) {
    if (!s) {
        return;
    }
    int index = -1;
    for (int i = s->length - 1; i >= 0; i--) {
        if (s->data[i] == c) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        size_t n_tomove = s->length - index + 1;  
        memmove(s->data + index, s->data + index + 1, n_tomove);
        s->length -= 1;
    }
}

struct qstr *qstr_split_at(struct qstr *s, size_t index) {
    if (!s || index > s->length) {
        return NULL;
    }
    struct qstr *new_s = qstr_alloc(s->capacity - index);
    if (new_s) {
        strcpy(new_s->data, s->data + index);
        new_s->length = s->length - index;
        s->data[index] = '\0';
        s->length = index;
    } else {
        fprintf(stderr, "qstr_split_at->data allocation error");
    }
    return new_s;
}

int main(int argc, char *argv[]) {
    // size_t n = strfreq("Hello, World!", 'l');
    // printf("%zu\n", n);

    // char *s = strrepeat("hello", 3);
    // puts(s);

    // char str[] = "hello";
    // struct qstr *qs = qstr_fromcstr(str);
    // qstr_echo(qs);
    // puts(qstr_cstr(qs));
    // qstr_echo(qs);
    // puts(qstr_cstr(qs));

    // char str[] = "hello";
    // struct qstr *qs = qstr_fromcstr(str);
    // qstr_echo(qs);                           // hellohello
    // qstr_rmlast(qs, 'h');
    // puts(qstr_cstr(qs));

    // char str[] = "0123456789";
    // struct qstr *qs = qstr_fromcstr(str);
    // struct qstr *split_qs = qstr_split_at(qs, 8);
    // printf("Original qstr after split: %s\n", qstr_cstr(qs)); // Output: "01234"
    // printf("New qstr after split: %s\n", qstr_cstr(split_qs)); // Output: "56789"
    // qstr_destroy(qs);
    // qstr_destroy(split_qs);

    // char str[] = "0123456789";
    // struct qstr *qs = qstr_fromcstr(str);
    // struct qstr *split_qs = qstr_split_at(qs, 11); // Should return NULL
    // if (!split_qs) {
    //     puts("Split index out of bounds!");
    // }


    return 0;
}