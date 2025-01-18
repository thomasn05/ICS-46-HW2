// #include "Timer.h"
#include "unordered_list.h"

UnorderedArrayList::UnorderedArrayList(int cap)
    : UnorderedList("Unordered_Array_List"), capacity(cap), size(0)
{
    this->buf = new string[cap];
}

UnorderedArrayList::~UnorderedArrayList()
{
    delete[] this->buf;
}

bool UnorderedArrayList::is_empty()
{
    return this->size == 0;
}

bool UnorderedArrayList::is_full()
{
    return this->size >= this->capacity;
}