#include "Linknode.hpp"

template <typename T>                                           //使用模板
class Linklist
{
public:
	Linklist()
        : size{}
	{}

	size_t Length();                                                        //求表长
    bool Insert(Linknode<T>* elem, Linknode<T>* location);                  //插入元素
	bool Delete(Linknode<T> elem);                                          //删除元素
	bool Modity(Linknode<T>* location, Linknode<T> elem);                   //修改元素
    Linknode<T>* LocateElem(T elem);                                        //返回元素地址
    Linknode<T>* getEnd();                                                  //返回链表最后一个节点地址
    Linknode<T>* getBegin() { return head.getNext(); }                      //返回链表第一个节点地址

    ~Linklist()
    {}
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
        Linknode<T> temp;
        //temp.setData(location->getData());
        temp.setNext(location->getNext());
        //location->setData(elem.getData());
        location->setNext(elem);
        //elem.setData(temp.getData());
        elem->setNext(temp.getNext());
        size++;
        return true;
    }
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
inline bool Linklist<T>::Modity(Linknode<T>* location, Linknode<T> elem)
{
    location->setData(elem.getData());
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