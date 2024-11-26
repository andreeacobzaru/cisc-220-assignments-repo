#ifndef IA_H
#define IA_H

#include <stdio.h>

/*
 * Reads count int values from f storing the values in 
 * the specified array.
 */
void ia_readn(FILE *f, size_t count, int *arr);

/*
 * Writes sz int values from arr into f one value per line.
 */
void ia_write(FILE *f, size_t arr_sz, const int *arr);

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
int *ia_read(FILE *f, size_t *sz);

/*
 * Compresses the contents of the n element array arr
 * returning a pointer to the first element of a new array
 * containing the compressed array. Writes the size of the
 * compressed array into the object pointed at by enc_sz.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 */
int *ia_encode(size_t n, const int *arr, size_t *enc_sz);

/*
 * Uncompresses the n element compressed array enc returning
 * a pointer to the first element of a new array
 * containing the uncompressed array. Writes the size of the
 * uncompressed array into the object pointed at by dec_sz.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 */
int *ia_decode(size_t n, const int *enc, size_t *dec_sz);



#endif