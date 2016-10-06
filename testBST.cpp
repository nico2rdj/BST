#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(102);
    v.push_back(-33);

    /* Create an instance of BST holding int */
    BSTInt b;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }
	
    
    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which  is incorrect." << endl;
        return -1;
    }

    /*Test empty. */
    BSTInt d;
    if( !d.empty()){
	cout << " empty issue" << endl;
	return -1;
    }

    d.insert(0);

    if( d.empty()){
	cout << " empty issue" << endl;
	return -1;
    }
	



    /* Test Height */
    cout << "Height is : " << b.height() << endl;	


    /* Test find return value. */
   
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    vector<int> v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(10);
    v1.push_back(14);
    v1.push_back(13);
    v1.push_back(-12);


    
    

    BSTInt c;


//Check if we can insert all our values
    for(int item : v) {
        bool pr = c.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }
    
   
    
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

// test successor()
    BSTIterator<int> foundIt = btemp.begin();

    cout << "iterator : " << *(foundIt) << endl;

    int mini = *foundIt;
    for( int item : v){
	cout << "iterator : " << *foundIt << endl;
        if(foundIt != btemp.end()){
	                if( *foundIt < mini){
	        cout << " iterator ++ does not work" << endl;
	        return -1;   
            }
        ++foundIt;
	mini = *foundIt;
	}
}
// test empty()
    BST<int> bemp;
    if( !(bemp.empty())){
	cout << " problem with the empty() " << endl;
	return -1;
    }
    bemp.insert(1);
    if( b.empty()){
	cout << " problem with empty() " << endl;
	return -1;
    }
    
            
 
//Check if we can insert the same value
    for(int item : v){ 
        if( c.insert(item) != false){
	    cout << " Failed when inserting the same value" << item << endl;
	return -1;
    }

//Check that all items are in the tree
    for(int item : v){
	if( c.find(item) == false){
		cout << " did not find item " << item << endl;
		return -1;
	}
    }



	

    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    cout << "All tests passed!" << endl;
    return 0;
}
}
