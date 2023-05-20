#include "Linknode.hpp"

template <typename T> class Linklist;
/// <summary>
/// ������
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
    //���������
    bool operator==(Linklist_iterator other);
    bool operator!=(Linklist_iterator other);
    Linklist_iterator& operator=(const Linklist_iterator& it);                //��ֵ���������
    T& operator*();                                                           //����������
    T& operator->();
    Linklist_iterator& operator++();                                         //��iteratorָ��������һ��λ��
    Linklist_iterator operator++(int);                                       //��iteratorָ��������һ��λ��
protected:
    Linknode<T>* node;
};


/// <summary>
/// 
/// </summary>
template <typename T>                                           //ʹ��ģ��
class Linklist
{
public:
    using iterator = Linklist_iterator<T>;
	Linklist()
        : size{}
	{}
    ~Linklist()
    {}

	size_t Length();                                                        //���
    bool Insert(Linknode<T>* elem, Linknode<T>* location);                  //����Ԫ��
	bool Delete(Linknode<T> elem);                                          //ɾ��Ԫ��
	bool Modity(Linknode<T>* location, Linknode<T> elem);                   //�޸�Ԫ��
    Linknode<T>* LocateElem(T elem);                                        //����Ԫ�ص�ַ
    Linknode<T>* getEnd();                                                  //�����������һ���ڵ��ַ
    Linknode<T>* getBegin() { return head.getNext(); }                      //���������һ���ڵ��ַ
    iterator begin();                                                       //ͷ������
    iterator end() { return {}; }                                           //β������
private:
	int size;													            //����
    Linknode<T> head;											            //ͷ�ڵ�
};

/// <summary>
/// ���س���
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T>
size_t Linklist<T>::Length()
{
    return size;
}

/// <summary>
/// ��巨
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="elem">Ԫ��</param>
/// <param name="location">�±�</param>
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

template<typename T>
Linklist<T>::iterator Linklist<T>::begin()
{
    iterator it;
    it.node = head.getNext();
    return it;
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
