#ifndef _SRC_LIST_UTILS_H
#define _SRC_LIST_UTILS_H

/**
 * @file linked_list_utils.h
 * SRC_LIST_UTILS API
 *
 * This file defines the public SRC_LIST_UTILS API and ABI. All identifiers
 * are prefixed either with **list_** or **LIST_**.
 */

/**
 * Generate new random list
 *
 * @param[in,out] l the target list. If *l is NULL, then a new integer list
 * will be allocated and l will be overwritten to reflect the new allocated
 * list.
 * @param[in] n the length of the list to generate.
 * @return the number of elements written to the list.
 * @retval -1 failed to create new list.
 */
extern int list_new_random(struct list *l, int n);

/**
 * Convert an list to a string.
 *
 * Conversion should follow the following format.
 * - NULL, {} -> "[ ]"
 * - { -1, 0, 1, 2, 3 } -> "[ -1, 0, 1, 2, 3 ]"
 *
 * @param[out] target the location to write the string. If *target is NULL,
 * then a new character array will be allocated and target, and len will be
 * overwritten to reflect the allocated length and new buffer.
 * @param[in, out] len the size of buffer allocated for the string. If target
 * is provided and len is insufficient, the target will be over-written with a
 * pointer to a new buffer with sufficient capacity to hold the string. The
 * previous buffers memory must be released by the invoking program.
 * @param[in] l the list to print.
 * @return On success, will return the number of bytes written to target
 * excluding the terminating '\0'.
 * @retval -1 failed to write to target string.
 */
extern int list_to_string(char **target, size_t *len, struct list const * const l);

/**
 * Find the maximimum element of an list.
 *
 * @param[in] l the location of the list.
 * @return the value of the maximum element of the list.
 */
extern int list_max(struct list const * const l);

/**
 * Find the maximimum element of an list.
 *
 * @param[in] l the list.
 * @return the index of the maximum element of the list.
 */
extern int list_max_index(struct list const * const l);

/**
 * Does an in-place reversal of the list.
 *
 * @param[in] l the location of the list
 */
extern void list_reverse(struct list *l);

#endif /* _SRC_LIST_UTILS_H */