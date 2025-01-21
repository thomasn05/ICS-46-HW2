// #include "Timer.h"
#include "unordered_list.h"

int UnorderedArrayList::find_index(const string &word)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->buf[i] == word)
            return i;
    }
    return -1;
}

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

bool UnorderedArrayList::find(const string &word)
{
    return this->find_index(word) >= 0;
}

void UnorderedArrayList::remove(const string &word)
{
    int index = this->find_index(word);

    if (index)
    {
        this->buf[index] = this->buf[this->size - 1];
        this->size--;
    }
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

void ListNode::print(ostream &out, ListNode *L)
{
    out << L->data;
}

ListNode *ListNode::find(const string &word, ListNode *L)
{
    ListNode *temp = L;
    while (temp)
    {
        if (temp->data == word)
            break;
        temp = temp->next;
    }
    return temp;
}

UnorderedLinkedList::~UnorderedLinkedList()
{
    while (this->head)
    {
        ListNode *temp = this->head;
        this->head = head->next;
        delete temp;
    }
}

void UnorderedLinkedList::insert(const string &word)
{
    this->head = new ListNode(word, this->head);
}

bool UnorderedLinkedList::find(const string &word)
{
    return (!ListNode::find(word, this->head));
}

bool UnorderedLinkedList::is_empty()
{
    if (!this->head)
        return 1;
    return 0;
}

bool UnorderedLinkedList::is_full()
{
    return 0;
}

void UnorderedLinkedList::print(ostream &out)
{
    ListNode *temp = this->head;
    while (temp)
    {
        ListNode::print(out, temp);
        temp = temp->next;
    }
}
