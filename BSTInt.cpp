
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  BSTNodeInt * prev = curr;
  
  while (curr) { //bug1
    if (item < curr->data ) {
      prev = curr;
      curr = curr->left;
      
    }
    else if (curr->data < item) {
      prev = curr;

      curr = curr->right;
    }
    else {
      return false;
    }
  }
  curr = prev;
  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else {
    curr->right = newNode;
    newNode->parent = curr;
  }

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */


unsigned int max1(int a1, int b1)
{
   if(a1 > b1)
	return a1;
   if( a1 < b1)
	return b1;
   return a1;
}


unsigned int height1(BSTNodeInt* n)
{
   
   if(n== NULL)
	return -1;
   	
   return 1+ max1(height1(n->right), height1(n->left));
}

unsigned int BSTInt::height() const{
   BSTNodeInt *n = root;
   int c = height1(n);
   return c;
}


/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  if( root != NULL)
  	return false;
  return true;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  if( n == NULL)
	return;
  deleteAll(n->left);
  deleteAll(n->right);
	
  delete n;
  
}
