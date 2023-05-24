#include "Linknode.hpp"
#include <iostream>

template <typename T> class Linklist;
/// <summary>
/// 迭代器
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
struct Linklist_iterator
{
public:
    friend Linklist<T>;
    Linklist_iterator()
    {}
    ~Linklist_iterator()
    {}
    //重载运算符
    bool operator==(Linklist_iterator other);
    bool operator!=(Linklist_iterator other);
    Linklist_iterator& operator=(const Linklist_iterator& it);                //赋值运算符重载
    T& operator*();                                                           //解引用重载
    T& operator->();
    Linklist_iterator& operator++();                                         //令iterator指向容器下一个位置
    Linklist_iterator operator++(int);                                       //令iterator指向容器下一个位置
protected:
    Linknode<T>* node;
};


/// <summary>
/// 
/// </summary>
template <typename T>                                           //使用模板
class Linklist
{
public:
    using iterator = Linklist_iterator<T>;
	Linklist()
        : size{}
	{}
    ~Linklist()
    {}

	size_t Length();                                                        //求表长
    bool Insert(Linknode<T>* elem, Linknode<T>* location);                  //插入元素
	bool Delete(Linknode<T> elem);                                          //删除元素
	bool Modity(T orginal, T val);                                          //修改元素
    Linknode<T>* LocateElem(T elem);                                        //返回元素地址
    Linknode<T>* getEnd();                                                  //返回链表最后一个节点地址
    Linknode<T>* getBegin() { return head.getNext(); }                      //返回链表第一个节点地址


    bool it_Insert(iterator it, T elem);                                    //使用迭代器插入元素
    bool it_Delete(T elem);                                                 //use iterator to delete
    //iterator it_LocateElem(T elem)                                          //使用迭代器返回元素地址
    //{
    //    iterator it = begin();
    //    for (int i = 0; i < Length(); i++)
    //    {
    //        if (it.node->getData() == elem)
    //        {
    //            return it;
    //            break;
    //        }
    //        ++it;
    //    }
    //}
    iterator end() { return {}; }                                           //尾迭代器
    iterator begin()                                                        //头迭代器
    {
        iterator it;
        it.node = head.getNext();
        return it;
    }                                            
protected:
    bool insertBack(iterator it, Linknode<T>* elem);                        //后插操作
private:
	int size;													            //长度
    Linknode<T> head;											            //头节点
};

/// <summary>
/// 返回长度
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T>
size_t Linklist<T>::Length()
{
    return size;
}

/// <summary>
/// 后插法
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="elem">元素</param>
/// <param name="location">下标</param>
/// <returns></returns>
template <typename T>
bool Linklist<T>::Linklist::Insert(Linknode<T>* elem, Linknode<T>* location)
{
    if (location == nullptr)
    {
        return false;
    }
    else
    {
        elem->setNext(location->getNext());
        location->setNext(elem);
        size++;
        return true;
    }
}

template<typename T>
bool Linklist<T>::it_Insert(iterator it, T elem)
{
    Linknode<T> elem_node(elem);
    insertBack(it, &elem_node);
    return true;
}

template<typename T>
inline bool Linklist<T>::Delete(Linknode<T> elem)
{
    Linknode<T>* p = head.getNext();
    while (p != nullptr)
    {
        if (p->getData() == elem.getData())
        {
            p->setData(p->getNext()->getData());
            p->setNext(p->getNext()->getNext());
            delete p->getNext();
            size--;
            return true;
        }
        p = p->getNext();
    }
    return false;
}

template<typename T>
inline bool Linklist<T>::it_Delete(T elem)
{
    iterator it = it_LocateElem(elem);
    if (it.node->getNext() == nullptr)
    {
        delete it.node; 
        return true;
    }
    it.node->setData(it.node->getNext()->getData());
    it.node->setNext(it.node->getNext()->getNext());
    delete it.node->getNext();
    return true;
}

template<typename T>
inline bool Linklist<T>::Modity(T origal, T val)
{
    Linknode<T>* location = LocateElem(origal);
    location->setData(val);
    return true;
}

template<typename T>
Linknode<T>* Linklist<T>::LocateElem(T elem)
{
    Linknode<T>* p = head.getNext();
    while (1)
    {
        if (p == nullptr)
            break;
        if (p->getData() == elem)
            break;
        p = p->getNext();
    }
    return p;
}

template<typename T>
inline Linknode<T>* Linklist<T>::getEnd()
{
    Linknode<T>* p = &head;
    while (1)
    {
        if (p->getNext() == nullptr)
            break;
        p = p->getNext();
    }
    return p;
}

template<typename T>
inline bool Linklist<T>::insertBack(iterator it, Linknode<T>* elem)
{
    if (it == this->end())
    {
        this->getEnd()->setNext(elem);
        size++;
    }
    else
    {
        elem->setNext(it.node->getNext());
        it.node->setNext(elem);
        size++;
    }
    return true;
}

template<typename T>
bool Linklist_iterator<T>::operator==(Linklist_iterator<T> other)
{
    return node == other.node;
}

template<typename T>
bool Linklist_iterator<T>::operator!=(Linklist_iterator<T> other)
{
    return node == other.node;
}

template<typename T>
Linklist_iterator<T>& Linklist_iterator<T>::operator=(const Linklist_iterator<T>& it)
{
    node = it.node;
    return *this;
}


template<typename T>
T& Linklist_iterator<T>::operator*()
{
    return node->getData();
}

template<typename T>
T& Linklist_iterator<T>::operator->()
{
    return operator*();//*(*this);
}

template<typename T>
Linklist_iterator<T>& Linklist_iterator<T>::operator++()
{
    if (node != nullptr)
        node = node->getNext();
    return *this;
}

template<typename T>
Linklist_iterator<T> Linklist_iterator<T>::operator++(int)
{
    auto temp = *this;
    ++(*this);
    return temp;
}