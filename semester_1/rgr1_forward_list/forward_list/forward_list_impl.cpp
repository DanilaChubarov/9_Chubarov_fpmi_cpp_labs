#include "forward_list_impl.h"
ForwardList::ForwardList() : first_(nullptr) {}
size_t ForwardList::Size() const
{
	
	size_t size = 0;
    ForwardList::ForwardListIterator iter = begin();
	while (iter != end())
	{
		size++;
        iter++;
	}
	return size;
}
ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    Clear();
    if (rhs.first_ == nullptr) 
    {
        first_ = nullptr;
        return *this;
    }
    first_ = new Node(rhs.first_->value_);
    Node* current_this = first_;
    Node* current_rhs = rhs.first_->next_;
    while (current_rhs != nullptr)
    {
        current_this->next_ = new Node(current_rhs->value_);
        current_this = current_this->next_;
        current_rhs = current_rhs->next_;
    }

    return *this;
}
ForwardList::ForwardList(const ForwardList& rhs)
{
    first_ = new Node(rhs.first_->value_);
    Node* current_this = first_;
    Node* current_rhs = rhs.first_->next_;
    while (current_rhs != nullptr)
    {
        current_this->next_ = new Node(current_rhs->value_);
        current_this = current_this->next_;
        current_rhs = current_rhs->next_;
    }
}
ForwardList::ForwardList(size_t count, int32_t value)
{
    first_ = new Node(value);
    Node* current_this = first_;
    for (size_t i = 0; i < count-1; ++i)
    {
        current_this->next_ = new Node(value);
        current_this= current_this->next_;
    }

}
ForwardList::ForwardList(std::initializer_list<int32_t> init)
{
    if (init.size() == 0)
    {
        first_ = nullptr;
        return;
    }
    std::initializer_list<int32_t>::iterator iter = init.begin();
    first_ = new Node(*iter);
    Node* current_this = first_;
    ++iter;
    for (; iter != init.end(); ++iter)
    {
        current_this->next_ = new Node(*iter);
        current_this = current_this->next_;
    }
}
ForwardList::~ForwardList()
{
    Node* current = first_;
    while (current != nullptr)
    {
        Node* next = current->next_; 
        delete current;              
        current = next;             
    }
    first_ = nullptr; 
}
void ForwardList::PushFront(int32_t value)
{
    Node* new_first = new Node(value);
    new_first->next_ = first_;
    first_ = new_first;
}
void ForwardList::PopFront() 
{
    if (Size() == 0)
    {
        return;
    }
    Node* tmp= first_;
    first_ = first_->next_;
    delete tmp;
}
void ForwardList::Clear()
{
    Node* current = first_;
    while (current != nullptr)
    {
        Node* next = current->next_;
        delete current;
        current = next;
    }
    first_ = nullptr;
}
void ForwardList::Remove(int32_t value)
{
    while (first_ != nullptr && first_->value_ == value)
    {
        Node* tmp = first_;
        first_ = first_->next_;
        delete tmp;
    }
    Node* current = first_;
    while (current != nullptr && current->next_ != nullptr)
    {
        if (current->next_->value_ == value) {
            Node* temp = current->next_;
            current->next_ = current->next_->next_;
            delete temp;
        }
        else
        {
            current = current->next_;
        }
    }
}
bool ForwardList::FindByValue(int32_t value)
{
    Node* current = first_;
    while(current != nullptr)
    {
        if (current->value_ == value)
        {
            return true;
        }
        current = current->next_;
    }
    return false;
}
void ForwardList::Print(std::ostream& out)
{
    if (Size() == 0)
    {
        out << "";
        return;
    }
    ForwardList::ForwardListIterator iter = begin();
    for (size_t i = 0; i < Size()-1; ++i) 
    {
        out << *iter << " ";
        ++iter;
    }
    out << *iter;

}
int32_t ForwardList::Front() const
{
    return first_->value_;
}
