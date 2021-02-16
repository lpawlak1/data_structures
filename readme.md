# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`array_container`](#classarray__container) | 
`class `[`container`](#classcontainer) | Interface used in all structures.
`class `[`link_vector`](#classlink__vector) | A class that forms a 2-way linked list.
`class `[`list`](#classlist) | 
`class `[`queue`](#classqueue) | basic LIFO structure
`class `[`stack`](#classstack) | Basic FIFO structure.
`class `[`vector`](#classvector) | 
`struct `[`node`](#structnode) | 2 way linked list stores value, next node ,previous node

# class `array_container` 

```
class array_container : public container
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual bool `[`clear`](#classarray__container_1af1c0cc85d2c1564c9b59c8079118b405)`()` | Method from 'container' class that deletes every item in container 
`protected T * `[`tab_`](#classarray__container_1afe25702e7418dada645592e35e5a2324) | 
`protected int `[`container_size_`](#classarray__container_1a13bdb43a7c0f2576bcfbaa27dfc99f39) | 
`protected int `[`initial_size_`](#classarray__container_1ae8a27e124e6a2fa39c2e75b16f34a785) | 
`protected float `[`load_factor_`](#classarray__container_1a6c00bcc5746694d36795a6e8b283d91e) | 
`protected  `[`array_container`](#classarray__container_1aa666d057bac6792270fcd5fc11222f46)`()` | Used to make constructor protected.
`protected  `[`array_container`](#classarray__container_1a68dcb17fa82b8bcc588a6f05e0ca58ae)`(int initial_size)` | Used to make destructor protected.
`protected T * `[`rewrite_append`](#classarray__container_1a1e601637e7079de8e1e241d659f46784)`(T value)` | Method used for rewriting data to a new array and appending `value` at the end od array 
`protected T * `[`rewrite`](#classarray__container_1a598cc0645e6460c79dd95221882cf0cd)`(int size,int first_index)` | Method used for rewriting into a new `size` starting from a `first_index`

## Members

#### `public virtual bool `[`clear`](#classarray__container_1af1c0cc85d2c1564c9b59c8079118b405)`()` 

Method from 'container' class that deletes every item in container 
#### Returns
* success as true and false otherwise

#### `protected T * `[`tab_`](#classarray__container_1afe25702e7418dada645592e35e5a2324) 

#### `protected int `[`container_size_`](#classarray__container_1a13bdb43a7c0f2576bcfbaa27dfc99f39) 

#### `protected int `[`initial_size_`](#classarray__container_1ae8a27e124e6a2fa39c2e75b16f34a785) 

#### `protected float `[`load_factor_`](#classarray__container_1a6c00bcc5746694d36795a6e8b283d91e) 

#### `protected  `[`array_container`](#classarray__container_1aa666d057bac6792270fcd5fc11222f46)`()` 

Used to make constructor protected.

#### `protected  `[`array_container`](#classarray__container_1a68dcb17fa82b8bcc588a6f05e0ca58ae)`(int initial_size)` 

Used to make destructor protected.

#### `protected T * `[`rewrite_append`](#classarray__container_1a1e601637e7079de8e1e241d659f46784)`(T value)` 

Method used for rewriting data to a new array and appending `value` at the end od array 
#### Parameters
* `value` of type T as what to append to array after rewriting

#### `protected T * `[`rewrite`](#classarray__container_1a598cc0645e6460c79dd95221882cf0cd)`(int size,int first_index)` 

Method used for rewriting into a new `size` starting from a `first_index`
#### Parameters
* `size` new size of the container 

* `first_index` from which index to start rewriting 

#### Returns
* A pointer to a new array

# class `container` 

Interface used in all structures.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline int `[`size`](#classcontainer_1a26a2a8c3b2a8bf477211a2ea7615fcb0)`() const` | Method to show how much data it holds 
`public inline bool `[`empty`](#classcontainer_1a031413531a513d564354f826646444bb)`() const` | Check if container is empty 
`public bool `[`clear`](#classcontainer_1ab468b180057f3f910e863bcb64cb2411)`()` | Used to delete every element in container, is pure-virtual and implemented in child classes 
`protected int `[`size_`](#classcontainer_1a34797eb3dbde10dab2312b7c3b69b4bc) | stores how many elements are in container
`protected  `[`container`](#classcontainer_1a1bacfe1cc90545205ef538bd4e743898)`() = default` | Constructor in protected, only for child classes.
`protected  `[`~container`](#classcontainer_1ab2d043b6e831f6ea7cd479604010a6ae)`() = default` | Destructor in protected, only for child classes.

## Members

#### `public inline int `[`size`](#classcontainer_1a26a2a8c3b2a8bf477211a2ea7615fcb0)`() const` 

Method to show how much data it holds 
#### Returns
* integer of size

#### `public inline bool `[`empty`](#classcontainer_1a031413531a513d564354f826646444bb)`() const` 

Check if container is empty 
#### Returns
* bool meaning what the state is

#### `public bool `[`clear`](#classcontainer_1ab468b180057f3f910e863bcb64cb2411)`()` 

Used to delete every element in container, is pure-virtual and implemented in child classes 
#### Returns
* bool of success

#### `protected int `[`size_`](#classcontainer_1a34797eb3dbde10dab2312b7c3b69b4bc) 

stores how many elements are in container

#### `protected  `[`container`](#classcontainer_1a1bacfe1cc90545205ef538bd4e743898)`() = default` 

Constructor in protected, only for child classes.

#### `protected  `[`~container`](#classcontainer_1ab2d043b6e831f6ea7cd479604010a6ae)`() = default` 

Destructor in protected, only for child classes.

# class `link_vector` 

```
class link_vector
  : public list< T >
  : public container
```  

A class that forms a 2-way linked list.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual bool `[`clear`](#classlink__vector_1a9dba75eef89e9d3d5b81cbbcd7dc86b0)`()` | Used to delete every element in container, is pure-virtual and implemented in child classes 
`public virtual void `[`insert`](#classlink__vector_1af2cc42f1867164b83ed907249a51da82)`(int index,T value)` | **See also**: [list](#classlist)
`public virtual void `[`push_front`](#classlink__vector_1ade05da51ab95b141c8acede6a656a24b)`(T value)` | **See also**: [list](#classlist)
`public virtual void `[`push_back`](#classlink__vector_1a2da065fc74e74621bff5493135375caf)`(T value)` | **See also**: [list](#classlist)
`public virtual T `[`pop_front`](#classlink__vector_1a7f173a607883cc4100316d135a1a7aa5)`()` | **See also**: [list](#classlist)
`public virtual T `[`pop_back`](#classlink__vector_1adf48ca768a6c4e08cda44e6e6df459b9)`()` | **See also**: [list](#classlist)
`public virtual T `[`pop`](#classlink__vector_1a51715233f11754e251f0a65eab0d1a7f)`(int index)` | **See also**: [list](#classlist)
`public virtual T `[`operator[]`](#classlink__vector_1a0fecc40c272e9492116fa42de468cc15)`(int index)` | **See also**: [list](#classlist)
`public virtual void `[`replace`](#classlink__vector_1a947d1545edd1ff292a5d246c8537835c)`(int index,T value)` | **See also**: [list](#classlist)
`protected `[`node`](#structnode)`< T > * `[`first_`](#classlink__vector_1afd852dc66101d1b8ebd7a88ce1884dd0) | Means first node.
`protected `[`node`](#structnode)`< T > * `[`last_`](#classlink__vector_1abe985b0f2083d61dbb1aa363a5adb315) | Means last node.

## Members

#### `public virtual bool `[`clear`](#classlink__vector_1a9dba75eef89e9d3d5b81cbbcd7dc86b0)`()` 

Used to delete every element in container, is pure-virtual and implemented in child classes 
#### Returns
* bool of success

#### `public virtual void `[`insert`](#classlink__vector_1af2cc42f1867164b83ed907249a51da82)`(int index,T value)` 

**See also**: [list](#classlist)

#### `public virtual void `[`push_front`](#classlink__vector_1ade05da51ab95b141c8acede6a656a24b)`(T value)` 

**See also**: [list](#classlist)

#### `public virtual void `[`push_back`](#classlink__vector_1a2da065fc74e74621bff5493135375caf)`(T value)` 

**See also**: [list](#classlist)

#### `public virtual T `[`pop_front`](#classlink__vector_1a7f173a607883cc4100316d135a1a7aa5)`()` 

**See also**: [list](#classlist)

#### `public virtual T `[`pop_back`](#classlink__vector_1adf48ca768a6c4e08cda44e6e6df459b9)`()` 

**See also**: [list](#classlist)

#### `public virtual T `[`pop`](#classlink__vector_1a51715233f11754e251f0a65eab0d1a7f)`(int index)` 

**See also**: [list](#classlist)

#### `public virtual T `[`operator[]`](#classlink__vector_1a0fecc40c272e9492116fa42de468cc15)`(int index)` 

**See also**: [list](#classlist)

#### `public virtual void `[`replace`](#classlink__vector_1a947d1545edd1ff292a5d246c8537835c)`(int index,T value)` 

**See also**: [list](#classlist)

#### `protected `[`node`](#structnode)`< T > * `[`first_`](#classlink__vector_1afd852dc66101d1b8ebd7a88ce1884dd0) 

Means first node.

#### `protected `[`node`](#structnode)`< T > * `[`last_`](#classlink__vector_1abe985b0f2083d61dbb1aa363a5adb315) 

Means last node.

# class `list` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`insert`](#classlist_1acdde89666e07196ddbb39ac0482b6006)`(int index,T value)` | Inserts a `value` at a certain `index`
`public void `[`push_front`](#classlist_1a1e8635c5ee3533f6d841894eeeb94f9a)`(T value)` | Puts a `value` at start of the container 
`public void `[`push_back`](#classlist_1a634c323c4fa3a7102c3e4762ad825eb4)`(T value)` | Puts a `value` at end of the container 
`public T `[`pop_front`](#classlist_1a34833b7e966e0cc1b3746fe28546c163)`()` | Removes value at the beginning of list 
`public T `[`pop_back`](#classlist_1a2368998c0832dff59c9c255942fc1b6d)`()` | Removes value at the end of list 
`public T `[`pop`](#classlist_1aed2c7759fed7860e72735ce1d41b75d2)`(int index)` | Removes value from retain index of the list 
`public T `[`operator[]`](#classlist_1a186a45b3df349053e694362e1d8150ca)`(int index)` | Picks value from desired index 
`public void `[`replace`](#classlist_1a5f0043cc6b645c07ff4f6f97ebcbd289)`(int index,T value)` | Replacing a value at certain index 
`protected  `[`list`](#classlist_1a229d7aa12c41a71a58d897910b734f10)`() = default` | Used to make constructor protected.
`protected  `[`~list`](#classlist_1ab988ead8591246fc136101e27d9a137d)`() = default` | Used to make destructor protected.

## Members

#### `public void `[`insert`](#classlist_1acdde89666e07196ddbb39ac0482b6006)`(int index,T value)` 

Inserts a `value` at a certain `index`
#### Parameters
* `index` at which value has to be assigned 

* `value` *self-explanatory*

#### `public void `[`push_front`](#classlist_1a1e8635c5ee3533f6d841894eeeb94f9a)`(T value)` 

Puts a `value` at start of the container 
#### Parameters
* `value` *self-explanatory*

#### `public void `[`push_back`](#classlist_1a634c323c4fa3a7102c3e4762ad825eb4)`(T value)` 

Puts a `value` at end of the container 
#### Parameters
* `value` *self-explanatory*

#### `public T `[`pop_front`](#classlist_1a34833b7e966e0cc1b3746fe28546c163)`()` 

Removes value at the beginning of list 
#### Returns
* T value

#### `public T `[`pop_back`](#classlist_1a2368998c0832dff59c9c255942fc1b6d)`()` 

Removes value at the end of list 
#### Returns
* T value

#### `public T `[`pop`](#classlist_1aed2c7759fed7860e72735ce1d41b75d2)`(int index)` 

Removes value from retain index of the list 
#### Parameters
* `index` integer from which spot value will be picked 

#### Returns
* T value

#### `public T `[`operator[]`](#classlist_1a186a45b3df349053e694362e1d8150ca)`(int index)` 

Picks value from desired index 
#### Parameters
* `index` 

#### Returns
* T value

#### `public void `[`replace`](#classlist_1a5f0043cc6b645c07ff4f6f97ebcbd289)`(int index,T value)` 

Replacing a value at certain index 
#### Parameters
* `index` integer for place in list 

* `value` for what this should be replaced

#### `protected  `[`list`](#classlist_1a229d7aa12c41a71a58d897910b734f10)`() = default` 

Used to make constructor protected.

#### `protected  `[`~list`](#classlist_1ab988ead8591246fc136101e27d9a137d)`() = default` 

Used to make destructor protected.

# class `queue` 

```
class queue
  : public container
```  

basic LIFO structure

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`enqueue`](#classqueue_1ab3efbd708a3353d2d433eb9ab5fd81f9)`(T value)` | Puts element on the back of the queue 
`public T `[`dequeue`](#classqueue_1ab9f67346069105686326aba9069b767e)`()` | Removes element from the front 
`public T `[`peek`](#classqueue_1aaf8364062092adf3c12a0b362fd9ddff)`()` | Peeks at the first element and dont remove it from queue 
`public virtual bool `[`clear`](#classqueue_1a5253239ea33d427a998def95db59a2fb)`()` | Used to delete every element in container, is pure-virtual and implemented in child classes 
`protected `[`node`](#structnode)`< T > * `[`first_`](#classqueue_1a36915ac956d20e00fbd6ea61b6f5d015) | First element in queue.
`protected `[`node`](#structnode)`< T > * `[`last_`](#classqueue_1a002a8e4465f4dadbe1c77b357e319d07) | Last element in queue.

## Members

#### `public bool `[`enqueue`](#classqueue_1ab3efbd708a3353d2d433eb9ab5fd81f9)`(T value)` 

Puts element on the back of the queue 
#### Parameters
* `value` of type T is put on back 

#### Returns
* bool of success

#### `public T `[`dequeue`](#classqueue_1ab9f67346069105686326aba9069b767e)`()` 

Removes element from the front 
#### Returns
* T value

#### `public T `[`peek`](#classqueue_1aaf8364062092adf3c12a0b362fd9ddff)`()` 

Peeks at the first element and dont remove it from queue 
#### Returns
* T value

#### `public virtual bool `[`clear`](#classqueue_1a5253239ea33d427a998def95db59a2fb)`()` 

Used to delete every element in container, is pure-virtual and implemented in child classes 
#### Returns
* bool of success

#### `protected `[`node`](#structnode)`< T > * `[`first_`](#classqueue_1a36915ac956d20e00fbd6ea61b6f5d015) 

First element in queue.

#### `protected `[`node`](#structnode)`< T > * `[`last_`](#classqueue_1a002a8e4465f4dadbe1c77b357e319d07) 

Last element in queue.

# class `stack` 

```
class stack : public container
```  

Basic FIFO structure.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`push`](#classstack_1ac159e433f914cc3b139ac5bf4757cc2f)`(T value)` | Pushes value on top of the stack 
`public T `[`pop`](#classstack_1a94052aea6bcba50cd07e92e7759ed89d)`()` | Pops the top value from the stack 
`public T `[`peek`](#classstack_1a2f6deb236bd64b5d6eb0239fa3644d38)`()` | Peeks the top value from the stack 
`public virtual bool `[`clear`](#classstack_1a6299e7dbaa8b6acda6d81afc8c429384)`()` | Used to delete every element in container, is pure-virtual and implemented in child classes 

## Members

#### `public bool `[`push`](#classstack_1ac159e433f914cc3b139ac5bf4757cc2f)`(T value)` 

Pushes value on top of the stack 
#### Parameters
* `value` of type T to be pushed on top 

#### Returns
* bool of success

#### `public T `[`pop`](#classstack_1a94052aea6bcba50cd07e92e7759ed89d)`()` 

Pops the top value from the stack 
#### Returns
* T value

#### `public T `[`peek`](#classstack_1a2f6deb236bd64b5d6eb0239fa3644d38)`()` 

Peeks the top value from the stack 
#### Returns
* T value of the top value

#### `public virtual bool `[`clear`](#classstack_1a6299e7dbaa8b6acda6d81afc8c429384)`()` 

Used to delete every element in container, is pure-virtual and implemented in child classes 
#### Returns
* bool of success

# class `vector` 

```
class vector
  : public list< T >
  : public array_container< T >
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`vector`](#classvector_1a00d237f22fd5eb1aa9a536993e82e54f)`()` | Default constructor.
`public  `[`vector`](#classvector_1a56ff8fcd1027b7fe8ebfd2fa5374a72c)`(int initial_size)` | Constructor with possibility 
`public virtual void `[`insert`](#classvector_1add1574d33c1cd483e884c3a2407e5f17)`(int index,T value)` | Inserts a `value` at a certain `index`
`public virtual void `[`push_back`](#classvector_1aeb2862fd65a498dff1fe9fe33e10f0c6)`(T value)` | Puts a `value` at end of the container 
`public virtual void `[`push_front`](#classvector_1ad518e0984424dc4f40f9385bb903c90e)`(T value)` | Puts a `value` at start of the container 
`public virtual T `[`pop_front`](#classvector_1ad9497cdf12d5129d08839ff0c1095a0e)`()` | Removes value at the beginning of list 
`public virtual T `[`pop_back`](#classvector_1aa84f457691605dc9b938f37f37405367)`()` | Removes value at the end of list 
`public virtual T `[`pop`](#classvector_1a55a784cd1e25b283f7e83629563cf4d1)`(int index)` | Removes value from retain index of the list 
`public virtual T `[`operator[]`](#classvector_1af455451ddc0b0ec5dfea43ca103a5578)`(int index)` | Picks value from desired index 
`public virtual void `[`replace`](#classvector_1a5789743a6fd58e495206144f8db41cd6)`(int index,T value)` | Replacing a value at certain index 

## Members

#### `public  `[`vector`](#classvector_1a00d237f22fd5eb1aa9a536993e82e54f)`()` 

Default constructor.

#### `public  `[`vector`](#classvector_1a56ff8fcd1027b7fe8ebfd2fa5374a72c)`(int initial_size)` 

Constructor with possibility 
#### Parameters
* `initial_size` for container

#### `public virtual void `[`insert`](#classvector_1add1574d33c1cd483e884c3a2407e5f17)`(int index,T value)` 

Inserts a `value` at a certain `index`
#### Parameters
* `index` at which value has to be assigned 

* `value` *self-explanatory*

#### `public virtual void `[`push_back`](#classvector_1aeb2862fd65a498dff1fe9fe33e10f0c6)`(T value)` 

Puts a `value` at end of the container 
#### Parameters
* `value` *self-explanatory*

#### `public virtual void `[`push_front`](#classvector_1ad518e0984424dc4f40f9385bb903c90e)`(T value)` 

Puts a `value` at start of the container 
#### Parameters
* `value` *self-explanatory*

#### `public virtual T `[`pop_front`](#classvector_1ad9497cdf12d5129d08839ff0c1095a0e)`()` 

Removes value at the beginning of list 
#### Returns
* T value

#### `public virtual T `[`pop_back`](#classvector_1aa84f457691605dc9b938f37f37405367)`()` 

Removes value at the end of list 
#### Returns
* T value

#### `public virtual T `[`pop`](#classvector_1a55a784cd1e25b283f7e83629563cf4d1)`(int index)` 

Removes value from retain index of the list 
#### Parameters
* `index` integer from which spot value will be picked 

#### Returns
* T value

#### `public virtual T `[`operator[]`](#classvector_1af455451ddc0b0ec5dfea43ca103a5578)`(int index)` 

Picks value from desired index 
#### Parameters
* `index` 

#### Returns
* T value

#### `public virtual void `[`replace`](#classvector_1a5789743a6fd58e495206144f8db41cd6)`(int index,T value)` 

Replacing a value at certain index 
#### Parameters
* `index` integer for place in list 

* `value` for what this should be replaced

# struct `node` 

2 way linked list stores value, next node ,previous node

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public T `[`value`](#structnode_1a1aad25a1286bfb4e3870c8fb435718cd) | Stores value of type T.
`public `[`node`](#structnode)` * `[`next`](#structnode_1a7c8adb6c07d7574a94a1247285df4c29) | Stores next node.
`public `[`node`](#structnode)` * `[`previous`](#structnode_1a898762e2da82f323ae81ff60487ff42c) | Stores previous node.

## Members

#### `public T `[`value`](#structnode_1a1aad25a1286bfb4e3870c8fb435718cd)

Stores value of type T.

#### `public `[`node`](#structnode)` * `[`next`](#structnode_1a7c8adb6c07d7574a94a1247285df4c29) 

Stores next node.

#### `public `[`node`](#structnode)` * `[`previous`](#structnode_1a898762e2da82f323ae81ff60487ff42c)

Stores previous node.

Generated by [Moxygen](https://sourcey.com/moxygen)
