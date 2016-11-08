template <typename TYPE>
class LinkedStack {
    class Box {
    public:
        TYPE Data;
        Box* pNext;
        Box(TYPE, Box* = NULL);
    };
    
public:
    LinkedStack();
    ~LinkedStack();
    
public:
    void Push(const TYPE & Element);
    bool Pop(TYPE& Element);
    TYPE& Peek();
    void RemoveAll();
    
    size_t GetSize() const;
    bool IsEmpty() const;
    
private:
    void Init();
    void Destroy();
    
private:
    Box* pTop;
    size_t Used;
};


template <typename TYPE>
LinkedStack<TYPE>::Box::Box(TYPE Data, Box* pNext)
{
    this->Data = Data;
    this->pNext = pNext;
}

template <typename TYPE>
LinkedStack<TYPE>::LinkedStack()
{
    Init();
}

template <typename TYPE>
LinkedStack<TYPE>::~LinkedStack()
{
    Destroy();
}

template <typename TYPE>
void LinkedStack<TYPE>::Init()
{
    pTop = 0;
    Used = 0;
}

template <typename TYPE>
void LinkedStack<TYPE>::Destroy()
{
    Box* p;
    
    while (pTop)
    {
        p = pTop;
        pTop = pTop->pNext;
        delete p;
    }
    
    Init();
}


template <typename TYPE>
void LinkedStack<TYPE>::Push(const TYPE & Element)
{
    //TODO: Push an element to the top of the stack
}

template<typename TYPE>
bool LinkedStack<TYPE>::Pop(TYPE & Element)
{
    //TODO: Pop an element (remove from stack and pass it to Element)
    //return true if an element was returned, false if not
}


template<typename TYPE>
TYPE& LinkedStack<TYPE>::Peek()
{
    //TODO: return the element on top of the stack, without removing it
}

template <typename TYPE>
void LinkedStack<TYPE>::RemoveAll()
{
    //TODO: Empty the stack
}

template<typename TYPE>
size_t LinkedStack<TYPE>::GetSize() const
{
    //TODO: Return the number of elements currently in the stack
}

template<typename TYPE>
bool LinkedStack<TYPE>::IsEmpty() const
{
    //TODO: Check whether the stack is empty
}
