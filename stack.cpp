/**
 * @file stack.cpp
 * Implementation of the Stack class.
 *
 * Modify and turn in this file for the PA!
 *
 */
/**
 * Default constructor. Remember to initialize any variables you need
 * and allocate any required memory. The initial size of `items` should
 * be DEFAULTCAPACITY defined in stack.h.
 *
 */

template <class T> Stack<T>::Stack()
{
  /**
   * @todo Your code here!
   */
    items = new T[DEFAULTCAPACITY];
    max_items = DEFAULTCAPACITY;
    num_items = 0;
}

/**
 * Destructor. Remember to free any memory allocated.
 *
 */
template <class T> Stack<T>::~Stack()
{
  /**
   * @todo Your code here!
   */
    delete[] items;
}

/**
 * Adds the parameter object to the top of the Stack. That is, the
 * element should go at the beginning of the list. Resize should be
 * called by multiplying current capacity EXPANSIONFACTOR defined in stack.h.
 *
 * @param value The object to be added to the Stack.
 */
template <class T> void Stack<T>::push(const T &newItem)
{
  /**
   * @todo Your code here!
   */
  if(this->size() < this->capacity()){  //num_items < max_items
    items[num_items] = newItem;
    num_items++;
  }else{
    //max_items = max_items * EXPANSIONFACTOR;
    resize(max_items*EXPANSIONFACTOR);
    // then do the pushes
    items[num_items] = newItem;
    num_items++;
  }

  // for(int i = 0; i< num_items; i++){
  //   cout<<items[i];
  // }
  // cout<<endl;
};

/**
 * Removes the object on top of the Stack, and returns it.
 * You may assume this function is only called when the Stack is not empty.
 * If the size of the stack changes to strictly less than 1 / SHRINKWHEN
 * (where SHRINKWHEN is defined in stack.h)after the item is removed,
 * the Stack should be resized by 1 / EXPANSIONFACTOR.
 * The capacity of the stack should never decrease below DEFAULTCAPACITY
 * to avoid corner cases where the stack size goes to zero.
 *
 * @return The element that was at the top of the Stack.
 */
template <class T> T Stack<T>::pop()
{
  /**
   * @todo Your code here! You will need to replace the following line.
   */
  if(!(this->size()==0)){
    T top = items[num_items-1]; //find the first element in the array
    if(num_items<max_items/SHRINKWHEN){
      //max_items = max_items/2;
      resize(max_items/EXPANSIONFACTOR);
      num_items--;
    }else{
      num_items--;
    }
    return top;
  }
};

/**
 * Finds the object on top of the Stack, and returns it to the caller.
 * Unlike pop(), this operation does not alter the Stack itself. It should
 * look at the beginning of the list. You may assume this function is only
 * called when the Stack is not empty.
 *
 * @return The element at the top of the Stack.
 */
template <class T> T Stack<T>::peek()
{
  /**
   * @todo Your code here! You will need to replace the following line.
   */
    if(!this->empty()){
      T top = items[num_items-1];
      return top;
    }
    T r;
    return r; 

};

/**
 * Determines if the Stack is empty.
 *
 * @return Whether or not the stack is empty (bool).
 */
template <class T> bool Stack<T>::empty() const
{
  /**
   * @todo Your code here! You will need to replace the following line.
   */
  if(this->size() == 0){
    return true;
  }else{ 
    return false;
  }
};

/**
 * Return the maximum number of items the stack can hold.
 *
 * Note: This is an implementation detail we would normally hide.
 * We include it here for testing purposes.
 *
 * @return Maximum number of items the stack can hold (int)
 */
template <class T> size_t Stack<T>::capacity() const
{
  /**
   * @todo Your code here! You will need to replace the following line.
   */
  return max_items;
};

/**
 * Return the number of items on the stack.
 *
 * @return Number of items on the stack (int)
 */
template <class T> size_t Stack<T>::size() const
{
  /**
   * @todo Your code here! You will need to replace the following line.
   */
  return num_items;
};

/**
 * Resize the the member variable `items`.
 * Don't forget to free up any memory that is no longer used.
 *
 * @param n The size of the stack after resizing
 */
template <class T> void Stack<T>::resize(size_t n)
{
  /**
   * @todo Your code here!
   */


  T * temp = new T[n];
  //items = new T[n];
  for(int i = 0; (i<num_items) && (i<n); i++){
    //items[i] = temp[i];
    temp[i] = items[i];
  }
  delete[] items;
  items = temp; 
  max_items = n;


  // T * temp = items;
  // items = new T[n];
  // for(int i = 0; i<num_items && i < n; i++){
  //   items[i] = temp[i];
  // }
  // delete[] items;
  // max_items = n;
};
