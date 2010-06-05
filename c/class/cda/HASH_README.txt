-------------------------------------------------------------------------------
File: HASH_README.txt

Description: Public Readme Document for HASH Module - Project 5

Revision History
Date         Programmer Name     Description
-----------  ------------------  ----------------
02-Mar-2001  Charles Fordyce        1.0
------------------------------------------------------------------------------
------------------------------------------------------------------------------
				Module Notes			
------------------------------------------------------------------------------

	The HASH module is a hash table implementation.  Candidates for items
who may occupy the table must follow the HASH_ITEM_t type definition in the 
hash.h (public header) file.  As you'll notice, the first element of the item 
structure is an enqueable (ENQ) item.  I chose this particular data type so that  
I could implement the HASH using the CHAINING method.  The CHAINING method is 
revered among hash table implementations for several reasons.  First, since
the table will be utilized to hold pointers to the items, the table will remain
small.  Second,using a linked list technique makes collision resolution a non-
issue.  Colliding items are collected in small linked lists.  Fetching an item 
from a list of collided items is a linear, but fast operation.  The reason
being that the linked lists of hash tables are usually very small.
        In addition, I've chosen a quality hashing function.  The HASH module
uses a prime number / modulus-based algorithm coupled with a hash table size 
that is also a prime.  I believe this combination will afford the module the 
best uniformity of distributed hashed keys across the table. 
	Another reason I chose CHAINING was to preclude the necessity of having 
to resize the table if it filled up.  The program will have to run out of memory 
for the table to fill up.  Finally, CHAINING turns the operation of deleting an
item a trivial task. Nothing more than removing an item from a simple linked 
list is required.  The implementation would not be complete unless the user 
was able to supply a destroy method for use inside the module.  The programmer
may pass this method as the last parameter in both the HASH_delete_item() and 
HASH_destroy_hash() methods.
       

------------------------------------------------------------------------------
			Public Methods Documentation
------------------------------------------------------------------------------

HASH.1.1  HASH_create_hash
  This method creates a new chained hash table and returns the ID of the table
  to be used in all subsequent hash table operations.  The hash table will be 
  initialized to be empty.

   Synopsis: 
     HASH_ID_t HASH_create_hash( const char *name );

   Where: 
     name  ==  a name for the table, name may be NULL.

   Returns: 
     The new hash table ID is returned.
   
   Exceptions: 
     Throws SIGABRT if table can't be created 
   
   Notes: 
     None.


HASH.1.2  HASH_add_item
  This method hashes the key of an item into the hash table.  The advantage of
  chaining resolves the complications of collision.

   Synopsis: 
     HASH_ITEM_p_t HASH_add_item( HASH_ID_t hash, HASH_ITEM_p_t item ); 


   Where: 
     hash  ==  the table to hash the item into.
     item  ==  the key/value to insert.

   Returns: 
     An item with the hashed key is returned.
   
   Exceptions: 
     None
   
   Notes:
     None.


HASH.1.3  HASH_find_item
  This method takes the unhashed key of an item to be looked up in the table.
  The item, with the value pointer set, is returned.
	 
   Synopsis: 
     HASH_ITEM_p_t HASH_find_item( HASH_ID_t hash, HASH_ITEM_p_t item );

   Where:
     hash   ==  the hash table to query
     item   ==  the item to find in the table, includes a key and a void 
                pointer for the value.

   Returns: 
     The item with the value pointer set.
   
   Exceptions: 
     None.
   
   Notes:
     None.


HASH.1.4  HASH_delete_item
  Removes a previously entered item from the table.  The caller may 
  optionally pass the address of a procedure to call prior to deleting
  the item in the table.  If specified, the value of the item will be 
  passed to this procedure.

   Synopsis: 
     HASH_ITEM_p_t HASH_delete_item( HASH_ID_t hash, 
                                     HASH_ITEM_p_t item,
                                     HASH_DESTROY_PROC_p_t destroy_proc );

   Where: 
     hash          ==  the hash table.
     item          ==  the item to be removed from the table.
     destroy_proc  ==  a user-defined process for deleting the value of the item. 

   Returns: 
     Returns NULL.
   
   Exceptions: 
     None.
   
   Notes:
     The caller may pass NULL for the destroy_proc parameter.
   


HASH.1.5  HASH_destroy_hash
  This method will destroy all items in a hash table, and then destroy the
  table. The caller may optionally pass the address of a procedure to call
  prior to destroying each item in the table; if specified, the value of each 
  destroyed item will be passed to this procedure.

   Synopsis: 
     HASH_ID_t HASH_destroy_hash( HASH_ID_t hash, 
                                  HASH_DESTROY_PROC_p_t destroy_proc );

   Where: 
     hash          ==  the hash table to be destroyed.
     destroy_proc  ==  a user-defined process for deleting the value of 
                       items in the table.	

   Returns: 
     NULL. 
   
   Exceptions: 
     None.
   
   Notes:
     The caller may pass NULL for the destroy_proc parameter. 