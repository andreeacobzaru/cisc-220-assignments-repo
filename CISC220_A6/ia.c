#include <stdlib.h>
#include <stdio.h>
#include "ia.h"

/*
 * Reads count int values from f storing the values in 
 * the specified array.
 */
void ia_readn(FILE *f, size_t count, int *arr) {
    // You just need a loop that read count values from f into the array pointed at by arr. 
    // Use fscanf to read a single int value each iteration of the loop.
    for (size_t i = 0; i < count; i++) {
        fscanf(f, "%d", &arr[i]);
    }
}


/*
 * Writes sz int values from arr into f one value per line.
 */
void ia_write(FILE *f, size_t arr_sz, const int *arr) {
    // You just need a loop that writes arr_sz values from arr into the file f.
    // Use fprintf to write a single int value followed by a newline \n character each iteration of the loop.
    for (size_t i = 0; i < arr_sz; i++) {
        fprintf(f, "%d\n", arr[i]);
    }
}

/*
 * Reads int values from f returning a pointer to the first 
 * element of a new array containing the read values. Writes
 * the number of read values into the object pointed at by sz.
 * Returns NULL if no int values can be read from f.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 *
 * This function assumes that the file position of f is
 * the beginning of the file.
 */
int *ia_read(FILE *f, size_t *sz) {
    // Read the file f twice. The first time, simply count the number of values that are in the file.
    // After reading the file once, use the function rewind to reset the file position to the beginning of the file.
    // Then, dynamically allocate an array to hold the values and read the file a second time storing the values in the array.
    int value;
    *sz = 0;
    while (fscanf(f, "%d", &value) != EOF) {
        (*sz)++;
    }
    if (*sz == 0) {
        return NULL;
    }
    rewind(f);
    int *arr = malloc(*sz * sizeof(int));
    if (!arr) {
        fprintf(stderr, "ia_read: malloc error\n");
        return NULL;
    }
    for (size_t i = 0; i < *sz; i++) {
        fscanf(f, "%d", &arr[i]);
    }
    return arr;
}


/*
 * Compresses the contents of the n element array arr
 * returning a pointer to the first element of a new array
 * containing the compressed array. Writes the size of the
 * compressed array into the object pointed at by enc_sz.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 */
int *ia_encode(size_t n, const int *arr, size_t *enc_sz) {
    int *new_arr = malloc((n * 2) * sizeof(int));
    if (!new_arr) {
        fprintf(stderr, "ia_encode: malloc error\n");
        return NULL;
    }
    int *new_arr_ptr = new_arr;
    int run_length = 1;
    for (size_t i = 0; i < n; i++) {
        while(((i + 1) < n) && (arr[i] == arr[i + 1])) {
            run_length++;
            i++;
        }
        *new_arr_ptr++ = run_length;
        *new_arr_ptr++ = arr[i];
        run_length = 1;
    }
    *enc_sz = new_arr_ptr - new_arr;
    new_arr = realloc(new_arr, *enc_sz * sizeof(int));
    if (!new_arr) {
        fprintf(stderr, "ia_encode: realloc error\n");
        return NULL;
    }
    return new_arr;
}

/*
 * Uncompresses the n element compressed array enc returning
 * a pointer to the first element of a new array
 * containing the uncompressed array. Writes the size of the
 * uncompressed array into the object pointed at by dec_sz.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 */
int *ia_decode(size_t n, const int *enc, size_t *dec_sz) {
    // To uncompress an array, make one pass of the array to find the size of the uncompressed array.
    // Then make a second pass of the array to uncompress the values.
    *dec_sz = 0;
    for (size_t i = 0; i < n; i += 2) {
        *dec_sz += enc[i];
    }
    int *dec_arr = malloc(*dec_sz * sizeof(int));
    if (!dec_arr) {
        fprintf(stderr, "ia_decode: malloc error\n");
        return NULL;
    }
    int *dec_arr_ptr = dec_arr;
    size_t run_length;
    int run_val;
    size_t i = 0;
    while (i < n) {
        run_length = enc[i++];
        run_val = enc[i++];
        for (size_t j = 0; j < run_length; j++) {
            *dec_arr_ptr++ = run_val;
        }
    }
    return dec_arr;
}


