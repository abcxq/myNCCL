#ifndef arry_h
#define arry_h

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>


//typedef struct node *link;
struct tagnode {
		unsigned char item; 
		struct tagnode *next;
};

typedef struct tagnode node;
typedef struct tagnode *link;
typedef struct tagnode *Array;
typedef struct tagnode *Item;

//typedef *link Array;
//typedef *link Item;

Array array_new(void);      // return the Array name 
Item array_first(Array name);   // get the first Item of Array 
Item array_last(Array name);    // get the last Item of Array
int array_length(Array name);   // count the size of Array elements
void array_insert(Array name, int index, char data);    // Inserts the given values before the element with the given index. -1 is the last element.
void array_delete_at(int index, Array name);    // Deletes the element at the specified index, returning that element, or nil if the index is out of range.
void array_clear(Array name);   // Removes all elements from Array name.
int array_index(Array name,char data); // Returns the index of the first object in ary such that the object is == to obj.
Array array_reverse(Array name);    // Returns a new array containing self¡®s elements in reverse order.   

Array array_sort(Array name, int (*compar)(Item n1, Item n2));  // Sort the array by function pointed to compar




#endif
