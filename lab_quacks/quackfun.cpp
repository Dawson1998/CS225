/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
template <typename T>
T sum(stack<T>& s)
{

    // Your code here
    if(s.empty())
    {
      return T();
    }
    else
    {
      T temp = s.top();
      s.pop();
      T total = temp+sum(s);
      s.push(temp);
      return total;
    }
    return T(); // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types

}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{
    static int count0,count1;
    // @TODO: Make less optimistic
    if(input.empty())
    {
      return true;
    }
    stack<char> temp;
    while(input.empty()!=true)
    {
      temp.push(input.front());
      input.pop();
    }
    while(temp.empty()!=true)
    {
      if(temp.top()=='[')
      {
        count0++;
      }
      else if(temp.top()==']')
      {
        count1++;
      }
      temp.pop();
    }
    if(count0==count1)
    {
      return true;
    }
    else
    {
      return false;
    }
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;
    queue<T> qtemp;
    queue<T> out;
    int a = 1;
    int b = 1;
    while(q.empty()!=true)
    {
      int odd = a%2;
      T temp = q.front();
      q.pop();
      b--;
      if(odd==0)
      {
        s.push(temp);
      }
      else
      {
        qtemp.push(temp);
      }
      if(q.size()==0 || b==0)
      {
        if(odd==0)
        {
          while(s.empty()!=true)
          {
            out.push(s.top());
            s.pop();
          }
        }
        else
        {
          while(qtemp.empty()!=true)
          {
            out.push(qtemp.front());
            qtemp.pop();
          }
        }
        a++;
        b=a;
      }
    }
    while(out.empty()!=true)
    {
      q.push(out.front());
      out.pop();
    }
    // optional: queue<T> q2;

    // Your code here
}

/**
 * Checks if the parameter stack and queue are the same. A stack and a queue
 * are considered to the "the same" if they contain only elements of exactly
 * the same values in exactly the same order.
 *
 * @note You may assume the stack and queue contain the same number of items!
 *
 * @note The back of the queue corresponds to the top of the stack!
 *
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 *
 * @param s The stack to compare
 * @param q The queue to compare
 * @return  true if the stack and the queue are the same; false otherwise
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
  if(s.empty())
  {
    return true;
  }
    bool retval = true; // optional
    T temp1 = s.top(); // rename me
    s.pop();
    if(verifySame(s,q)==true)
    {
      retval=true;
    }
    else
    {
      retval=false;
    }
    //T temp2 ; // rename :)
    s.push(temp1);
    // Your code here
    if(retval==true && s.top()==q.front())
    {
      retval = true;
    }
    else
    {
      retval = false;
    }
    q.push(q.front());
    q.pop();
    return retval;
}

}
