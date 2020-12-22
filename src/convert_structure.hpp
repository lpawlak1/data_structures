#ifndef CONV_STRUCTURE_HPP
#define CONV_STRUCTURE_HPP

#include "link_vector.hpp"
#include "vector.hpp"
#include "queue.hpp"
#include "stack.hpp"

namespace convert_structure{
    template<typename T>
    vector<T>* convert_to_vector(link_vector<T>* link_vec){
        auto* vec = new vector<T>(link_vec->size());
        for(auto i =0;i<link_vec->size();i++)
        {
            vec->push_back((*link_vec)[i]);
        }
        return vec;
    }
    template<typename T>
    vector<T>* convert_to_vector(queue<T>* que){
        auto* vec = new vector<T>(que->size());
        while(!que->empty())
        {
            vec->push_back(que->dequeue());
        }
        return vec;
    }
    template<typename T>
    vector<T>* convert_to_vector(stack<T>* stac)
    {
        auto* vec = new vector<T>(stac->size());
        for(auto i=0;i<stac->size();i++)
        {
            vec->push_front(stac->pop());
        }
        return vec;
    }
}

#endif