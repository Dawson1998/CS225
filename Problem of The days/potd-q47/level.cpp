#include "MinHeap.h"
#include <math.h>
vector<int> lastLevel(MinHeap & heap)
{
        // Your code here
        std::vector<int> v;
        if(heap.elements.empty())
        {
          std::cout<<"hit";
          return v;
        }
        std::cout<<heap.elements.size();
        if(heap.elements.size()<=2)
        {
          std::cout<<"hit";
          v.push_back(heap.elements[1]);
          return v;
        }
        int height = 1;
        while(heap.elements.size()-1>pow(2,height)-1)
        {
          height++;
        }
        height = height-1;
        //std::cout<<height;
        for(size_t i = (int)pow(2,height);i<heap.elements.size();i++)
        {
          v.push_back(heap.elements[i]);
        }
        return v;
}
