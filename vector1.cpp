#include "vector1.h"

int* vector1::rewrite_append(int a)
{
    int* ret = new int[size1 + how_add];
    for (int i = 0;i < size1;i++){
        ret[i] = tab[i];
    }
    size1 += how_add;
    ret[last_index+1] = a;
    last_index+=1;
    delete(tab);
    return ret;
}
int* vector1::rewrite(int size, int first_index){
    int* ret = new int[size];
    int j = 0;
    for (int i = first_index;i < size && i <= last_index;i++){
        ret[j] = tab[i];
        j+=1;
    }
    size1 = size;
    last_index = j-1;
    delete(tab);
    return ret;
}
vector1::vector1(){
    tab = new int[10];
    vector1::how_add = 10;
    vector1::size1 = 10;
    vector1::last_index = -1;
}
bool vector1::append(int a)
{
    if (size1 > last_index+1)
    {
        tab[last_index+1] = a;
        last_index += 1;
        return true;
    }
    tab = rewrite_append(a);
    return true;

}
int vector1::size(){
    return last_index + 1;
}
int vector1::get(int index){
    if (index >=0 && index <= last_index)
    {
        return tab[index];
    }
    else{
        return 0;
    }
}
bool vector1::push_back(int value){
    return append(value);
}
bool vector1::push_front(int value){
    return insert(0,value);
}
bool vector1::insert(int index,int value){
    if (index >= 0 && index <= last_index){
        int i = index;
        int temp = value;
        int temp2 = 0;
        while(i<=last_index){
            temp2 = tab[i];
            tab[i] = temp;
            temp = temp2;
            i+=1;
        }
        append(temp);
    }
    else if (index == 0 && last_index == -1){
        append(value);    
    }
    return true;
}
bool vector1::pop(int index){
    if (index >= 0 && index < last_index){
        int i = index;
        while(i<last_index){
            tab[i] = tab[i+1];
            i+=1;
        }
        last_index--;
    }
    return true;
}
bool vector1::pop_back(){
    return pop(last_index);
}
bool vector1::pop_front(){
    return pop(0);
}
bool vector1::empty(){
    if (last_index == -1)
    {
        return true;
    }
    else{
        return false; 
    }
}
bool vector1::shrink(int size, int first_index){
    if (first_index > last_index)
    {
        return false;
    }
    if(size1 > last_index+1){
        vector1::tab = vector1::rewrite(size,first_index);
        vector1::size1 = size;
        vector1::last_index = size-1;
    }
    return 1;
}
bool vector1::shrink_to_fit(){
    if (last_index + 1 != size1)
    {
        return shrink(last_index+1,0);
    }
    return true;
}
bool vector1::clear(){
    delete(tab);
    tab = new int[how_add];
    size1 = how_add;
    last_index = -1;
    return 1;
}