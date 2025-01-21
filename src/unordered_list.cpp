#include "Timer.h"
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

    if (index >= 0)
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
    out << L->data << endl;
}

ListNode *ListNode::find(const string &word, ListNode *L)
{
    while (L)
    {
        if (L->data == word)
            break;
        L = L->next;
    }
    return L;
}

void ListNode::delete_list(ListNode *L)
{
    while (L)
    {
        ListNode::delete_node(L);
    }
}

void ListNode::delete_node(ListNode *&L)
{
    ListNode *temp = L;
    L = L->next;
    delete temp;
}

void ListNode::remove(const string &word, ListNode *&L)
{
    ListNode *prev = L;
    ListNode *curr = L->next;
    while (curr)
    {
        if (curr->data == word)
        {
            prev->next = curr->next; 
            delete curr;             
            return;
        }
        prev = curr;       
        curr = curr->next; 
    }
}

UnorderedLinkedList::~UnorderedLinkedList()
{
    ListNode::delete_list(this->head);
}

void UnorderedLinkedList::insert(const string &word)
{
    this->head = new ListNode(word, this->head);
}

bool UnorderedLinkedList::find(const string &word)
{
    return ListNode::find(word, this->head);
}

void UnorderedLinkedList::remove(const string &word)
{
    if (!this->head)
        return;

    if (this->head->data == word)
    {
        ListNode::delete_node(this->head);
        return;
    }

    ListNode::remove(word, this->head);
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

void error(string word, string msg)
{
    cout << word << " " << msg << endl;
}

void insert_all_words(int k, string file_name, UnorderedList &L)
{
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = k * NWORDS / 10;
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.insert(word);
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tI = " << eTime << endl;
}

void find_all_words(int k, string file_name, UnorderedList &L)
{
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = k * NWORDS / 10;
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.find(word);
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tF = " << eTime << endl;
}

void remove_all_words(int k, string file_name, UnorderedList &L)
{
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = k * NWORDS / 10;
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.remove(word);
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tR = " << eTime << endl;
}

void measure_UnorderedList_methods(string file_name, UnorderedList &L)
{
    cout << L.name << endl;
    for (int k = 1; k <= 10; k++)
    {
        cout << "\tK = " << k << endl;
        insert_all_words(k, file_name, L);
        find_all_words(k, file_name, L);
        remove_all_words(k, file_name, L);
        if (!L.is_empty())
            error(L.name, "is not empty");
    }
}

void measure_lists(string input_file)
{
    UnorderedArrayList AL;
    UnorderedLinkedList LL;
    measure_UnorderedList_methods(input_file, AL);
    measure_UnorderedList_methods(input_file, LL);
}