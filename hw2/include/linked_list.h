#ifndef _SRC_LIST_H
#define _SRC_LIST_H

/**
 * @file linked_list.h
 * SRC_LIST API
 *
 * This file defines the public SRC_LIST API and ABI. All identifiers are
 * prefixed either with **list_** or **LIST_**.
 */

/**
 * @private
 * Internal linked-list node representation
 */
struct _list_node {
	/** Pointer to next node */
	struct _list_node *_next;
	/** Pointer to previous node */
	struct _list_node *_prev;

	/** node payload */
	int _value;
};

/**
 * Doubly-Linked Linked-List.
 */
struct list {
	/** @private
	 * Pointer to head node */
	struct _list_node *_head;
	/** @private
	 * Pointer to tail node */
	struct _list_node *_tail;

	/** @private
	 * total list length */
	int _length;
};

/**
 * Create a new list
 *
 * @return pointer to new list
 */
extern struct list *list_new(void);

/**
 * Delete list and data
 *
 * @return non-zero exit status
 */
extern void list_delete(struct list *l);

/**
 * Determine whether list is empty or not.
 *
 * @return true if list is has no elements
 */
extern bool list_empty(struct list const * const l);

/**
 * Returns OS max size of a list
 *
 * @return max size
 */
extern int list_max_size(struct list *l);

/**
 * Element access
 *
 * @param[in] l The list to be processed.
 * @param[in] n The element to be returned.
 * @return the element
 */
extern int list_at(struct list *l, int n);

/**
 * Front of list
 *
 * @param[in] l The list to be processed.
 * @return the zero-th element in list
 */
extern int list_front(struct list *l);

/**
 * Back of list
 *
 * @param[in] l The list to be processed.
 * @return the last element in list
 */
extern int list_back(struct list *l);

/**
 * Assign data to list[n]
 *
 * @param[in] l The list to be processed.
 * @param[in] n n-th element
 * @param[in] data data to be inserted
 * @return the data inserted
 */
extern int list_assign(struct list *l, int n, int data);

/**
 * Push to front of list
 *
 * @param[in] l The list to be processed.
 * @param[in] data data to be inserted
 * @return the data inserted
 */
extern int list_push_front(struct list *l, int data);

/**
 * Pop the first element of list.
 *
 * @param[in] l The list to be processed.
 * @return the element removed
 */
extern int list_pop_front(struct list *l);

/**
 * Append to end of list.
 *
 * @param[in] l The list to be processed.
 * @param[in] data data to be inserted
 * @return the data inserted
 */
extern int list_push_back(struct list *l, int data);

/**
 * Pop the last element of list
 *
 * @param[in] l The list to be processed.
 * @return the element removed
 */
extern int list_pop_back(struct list *l);

/**
 * Insert data to list at pos n.
 *
 * @param[in,out] l The list to be processed.
 * @param[in] n n-th element
 * @param[in] data data to be inserted
 * @return the data inserted
 */
extern int list_insert(struct list *l, int n, int data);

/**
 * Insert a list at a certain position
 *
 * @param[in,out] dst target list
 * @param[in] src source list
 * @param[in] pos position in source list
 * @return pointer to source list
 */
extern struct list *list_insert_list(struct list *dst, struct list *src, int pos);

/**
 * Erase elements of a list
 *
 * @param[in,out] l list to be erased
 * @param[in] start from i
 * @param[in] finish to j not including j
 * @return list without the erased elements
 */
extern struct list *list_erase(struct list *l, int start, int finish);

/**
 * Clear the list. i.e. Set all elements to 0.
 *
 * @param[in] l The list to be processed.
 * @return non-zero exit status
 */
extern int list_clear(struct list *l);

/**
 * Remove the first occurence of data in the list.
 *
 * @param[in] l the list to process.
 * @param[in] data the data search for.
 * @return index of removed node.
 * @retval -1 if data is not in list
 */
extern int list_remove(struct list *l, int data);

/**
 * Remove the last occurence of data in the list.
 *
 * @param[in] l the list to process.
 * @param[in] data the data search for.
 * @return index of removed node.
 * @retval -1 if data is not in list
 */
extern int list_rremove(struct list *l, int data);

#endif /* _SRC_LIST_H */