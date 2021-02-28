doxygen Doxyfile
moxygen  --output README.md ./doxydoc/xml/
sed -i 's/classarray__container/class-array_container/g' README.md  
sed -i 's/classbst/class-bst/g' README.md  
sed -i 's/classcontainer/class-container/g' README.md  
sed -i 's/classlink__vector/class-link_vector/g' README.md  
sed -i 's/classlist/class-list/g' README.md  
sed -i 's/classqueue/class-queue/g' README.md  
sed -i 's/classsorted__list/class-sorted_list/g' README.md  
sed -i 's/classstack/class-stack/g' README.md  
sed -i 's/classvector/class-vector/g' README.md  
sed -i 's/structleaf/struct-leaf/g' README.md  
sed -i 's/structnode/struct-node/g' README.md  
sed -i 's/structqueue__node/struct-queue_node/g' README.md  
sed -i 's/structstack__node/struct-stack_node/g' README.md  
rm -rf ./doxydoc

