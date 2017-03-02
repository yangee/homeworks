#ifndef _SRC_ARRAY_UTILS_H
#define _SRC_ARRAY_UTILS_H

/**
 * @file array_utils.h
 * SRC_ARRAY_UTILS API
 *
 * This file defines the public SRC_ARRAY_UTILS API and ABI. All identifiers
 * are prefixed either with **array_** or **ARRAY_**.
 */

/**
 * Generate new random array
 *
 * @param[in,out] data the target location to write the random array. If *data
 * is NULL, then a new integer array will be allocated and data, and n will be
 * overwritten to reflect the new allocated length and buffer.
 * @param[in] n the length of the array to generate.
 * @return the number of elements written to the array.
 * @retval -1 failed to create new array.
 */
extern int array_new_random(int **data, int *n);

/**
 * Convert an array to a string of the following format.
 * - NULL -> "[ ]"
 * - { -1, 0, 1, 2, 3 } -> "[ -1, 0, 1, 2, 3 ]"
 *
 * @param[out] target the location to write the string. If *target is NULL,
 * then a new character array will be allocated and target, and len will be
 * overwritten to reflect the allocated length and new buffer.
 * @param[in, out] len the size of buffer allocated for the string. If data is
 * provided and len is insufficient, the target will be over-written with a
 * pointer to a new buffer with sufficient capacity to hold the string. The
 * previous buffers memory must be released by the invoking program.
 * @param[in] data the location of the array to print.
 * @param[in] n the number of elements in the array.
 * @return On success, will return the number of bytes written to target
 * excluding the terminating '\0'.
 * @retval -1 failed to write to target string.
 */
extern int array_to_string(char **target, size_t *len, int const * const data, int n);

/**
 * Find the maximimum element of an array.
 *
 * @param[in] data the location of the array.
 * @param[in] n the length of the array.
 * @return the value of the maximum element of the array.
 */
extern int array_max(int const * const data, int n);

/**
 * Find the maximimum element of an array.
 *
 * @param[in] data the location of the array.
 * @param[in] n the length of the array.
 * @return the index of the maximum element of the array.
 */
extern int array_max_index(int const * const data, int n);

/**
 * Find the maximimum element of an array.
 *
 * @param[in] data the location of the array.
 * @param[in] n the length of the array.
 * @return a pointer to the maximum element of the array.
 */
extern int *array_max_ptr(int const * const data, int n);

/**
 * Does an in-place reversal of the array.
 *
 * @param[in] data the location of the array
 * @param[in] n the length of the array.
 */
extern void array_reverse(int *data, int n);

#endif /* _SRC_ARRAY_UTILS_H */