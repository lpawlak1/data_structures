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
        auto sizee = stac->size();
        auto* vec = new vector<T>(stac->size());
        for(auto i=0;i<sizee;i++)
        {
            vec->push_front(stac->pop());
        }
        return vec;
    }
    template<typename T>
    link_vector<T>* convert_to_link_vector(vector<T>* vec)
    {
        link_vector<T>* link = new link_vector<T>();
        for(auto i =0;i<vec->size();i++)
        {
            link->push_back((*vec)[i]);
        }
        return link;
    }
    template<typename T>
    link_vector<T>* convert_to_link_vector(queue<T>* que)
    {
        link_vector<T>* link = new link_vector<T>();
        auto sizee = que->size();
        for(auto i =0;i<sizee;i++)
        {
            link->push_back(que->dequeue());
        }
        return link;
    }
    template<typename T>
    link_vector<T>* convert_to_link_vector(stack<T>* stac)
    {
        auto* link = new link_vector<T>();
        auto sizee = stac->size();
        for(auto i =0;i<sizee;i++)
        {
            link->push_front(stac->pop());
        }
        return link;
    }
}

#endif