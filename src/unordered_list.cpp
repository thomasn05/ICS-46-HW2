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

void UnorderedArrayList::insert(const string &word)
{
    this->buf[this->size++] = word;
}

bool UnorderedArrayList::is_empty()
{
    return this->size == 0;
}

bool UnorderedArrayList::is_full()
{
    return this->size >= this->capacity;
}

void UnorderedArrayList::print(ostream &out)
{
    for (int i = 0; i < this->size; i++)
    {
        out << this->buf[i] << endl;
    }
}

ostream &operator<<(ostream &out, UnorderedList &L)
{
    L.print(out);
    return out;
}
