#include "link_vector.hpp"
int main(){
    link_vector<int> linkVector;
    for(auto i = 0; i < 2; i+=1){
        linkVector.push_back(i);
        linkVector.push_front(i);
    }
    linkVector.clear();
    return 0;
}
