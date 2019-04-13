/**
 * @file dhhashtable.cpp
 * Implementation of the DHHashTable class.
 */

#include "dhhashtable.h"
//using hashes::hash;
//using std::list;
//using std::pair;
template <class K, class V>
DHHashTable<K, V>::DHHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new std::pair<K, V>*[size];
    should_probe = new bool[size];
    for (size_t i = 0; i < size; i++) {
        table[i] = NULL;
        should_probe[i] = false;
    }
    elems = 0;
}

template <class K, class V>
DHHashTable<K, V>::~DHHashTable()
{
    destroy();
}

template <class K, class V>
DHHashTable<K, V> const& DHHashTable<K, V>::operator=(DHHashTable const& rhs)
{
    if (this != &rhs) {
        destroy();

        copy(rhs);
    }
    return *this;
}

template <class K, class V>
DHHashTable<K, V>::DHHashTable(DHHashTable<K, V> const& other)
{
    copy(other);
}


template <class K, class V>
void DHHashTable<K, V>::destroy()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table; table = nullptr;
    delete[] should_probe; should_probe = nullptr;
}

template <class K, class V>
void DHHashTable<K, V>::copy(const DHHashTable<K, V>& other)
{
    table = new std::pair<K, V>*[other.size];
    should_probe = new bool[other.size];
    for (size_t i = 0; i < other.size; i++) {
        should_probe[i] = other.should_probe[i];
        if (other.table[i] == NULL)
            table[i] = NULL;
        else
            table[i] = new std::pair<K, V>(*(other.table[i]));
    }
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void DHHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     * @note Remember to resize the table when necessary (load factor >=
     *  0.7). **Do this check *after* increasing elems!!** Also, don't
     *  forget to mark the cell for probing with should_probe!
     */
     /*elems++;
     if(shouldResize()) resizeTable();
     size_t place = hashes::hash(key,size);
     size_t jump = hashes::secondary_hash(key,size);
     size_t curr = place;
     size_t inc = 0;
     while(should_probe[curr])
     {
       ++inc;
       curr = (place+jump*inc)%size;
     }
     if(table[curr]==NULL)
     {
       table[curr]=new std::pair <K,V>(key,value);
     }
     else
     {
       table[curr]->first = key;
       table[curr]->second = value;
       size_t a = 1;
       while(true)
       {
         size_t newindex = (place + a*jump)%size;
         if(table[newindex]==NULL)
         {
           table[place]=new std::pair <K,V>(key,value);
           should_probe[place]=true;
           break;
         }
         a++;
       }
     }
     should_probe[place]=true;*/
     size_t index = hashes::hash(key,size);

       // if collision occurs
       if (table[index] != NULL)
       {
           // get index2 from second hash
           size_t index2 = hashes::secondary_hash(key,size);
           size_t i = 1;
           while (1)
           {
               // get newIndex
               size_t newIndex = (index + i * index2) % size;

               // if no collision occurs, store
               // the key
               if (table[newIndex] == NULL)
               {
                   table[newIndex] = new std::pair <K,V>(key,value);
                   return;
                   break;
               }
               i++;
           }
       }

       // if no collision occurs
       else
           table[index] = new std::pair <K,V>(key,value);;



    //(void) key;   // prevent warnings... When you implement this function, remove this line.
    //(void) value; // prevent warnings... When you implement this function, remove this line.
}

template <class K, class V>
void DHHashTable<K, V>::remove(K const& key)
{
    /**
     * @todo Implement this function
     */
     int i = findIndex(key);
     if(i != -1)
     {
       delete table[i];
       table[i]=NULL;
       elems--;
     }
     else
     {
       //not in table;
       return;
     }
     /*int place = findIndex(key);
     if(place == -1)
      return;
      should_probe[place] = false;*/
}

template <class K, class V>
int DHHashTable<K, V>::findIndex(const K& key) const
{
    /**
     * @todo Implement this function
     */
     size_t place = hashes::hash(key,size);
     size_t same = place;
     size_t jump = hashes::secondary_hash(key, size);
     while(should_probe[place]==true)
     {
       if(table[place]!=NULL)
       {
         if(table[place]->first == key)
         {
           return place;
         }
       }
       place = (place+jump);
       if(place==same)
       {
         return -1;
       }
     }

    return -1;
}

template <class K, class V>
V DHHashTable<K, V>::find(K const& key) const
{
    int idx = findIndex(key);
    if (idx != -1)
        return table[idx]->second;
    return V();
}

template <class K, class V>
V& DHHashTable<K, V>::operator[](K const& key)
{
    // First, attempt to find the key and return its value by reference
    int idx = findIndex(key);
    if (idx == -1) {
        // otherwise, insert the default value and return it
        insert(key, V());
        idx = findIndex(key);
    }
    return table[idx]->second;
}

template <class K, class V>
bool DHHashTable<K, V>::keyExists(K const& key) const
{
    return findIndex(key) != -1;
}

template <class K, class V>
void DHHashTable<K, V>::clear()
{
    destroy();

    table = new std::pair<K, V>*[17];
    should_probe = new bool[17];
    for (size_t i = 0; i < 17; i++)
        should_probe[i] = false;
    size = 17;
    elems = 0;
}

template <class K, class V>
void DHHashTable<K, V>::resizeTable()
{
    size_t newSize = findPrime(size * 2);
    std::pair<K, V>** temp = new std::pair<K, V>*[newSize];
    delete[] should_probe;
    should_probe = new bool[newSize];
    for (size_t i = 0; i < newSize; i++) {
        temp[i] = NULL;
        should_probe[i] = false;
    }

    for (size_t slot = 0; slot < size; slot++) {
        if (table[slot] != NULL) {
            size_t h = hashes::hash(table[slot]->first, newSize);
            size_t jump = hashes::secondary_hash(table[slot]->first, newSize);
            size_t i = 0;
            size_t idx = h;
            while (temp[idx] != NULL)
            {
                ++i;
                idx = (h + jump*i) % newSize;
            }
            temp[idx] = table[slot];
            should_probe[idx] = true;
        }
    }

    delete[] table;
    // don't delete elements since we just moved their pointers around
    table = temp;
    size = newSize;
}
