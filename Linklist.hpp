#include "Linknode.hpp"

template <typename T>                                           //ʹ��ģ��
class Linklist
{
public:
	Linklist()
        : size{}
	{}

	size_t Length();                                                        //���
    bool Insert(Linknode<T>* elem, Linknode<T>* location);                  //����Ԫ��
	bool Delete(Linknode<T> elem);                                          //ɾ��Ԫ��
	bool Modity(Linknode<T>* location, Linknode<T> elem);                   //�޸�Ԫ��
    Linknode<T>* LocateElem(T elem);                                        //����Ԫ�ص�ַ
    Linknode<T>* getEnd();                                                  //�����������һ���ڵ��ַ
    Linknode<T>* getBegin() { return head.getNext(); }                      //���������һ���ڵ��ַ

    ~Linklist()
    {}
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