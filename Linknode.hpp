#pragma once

template <typename T>                                           //ʹ��ģ��
class Linknode
{
public:
    Linknode()                                                  //ί�й���
        : Linknode({})
    {}
    Linknode(T value)                                           //ֵ�ڷ�������
        : data{ value }, next{ nullptr }
    {}
    //Linknode(int length, const T& value);                      //���쳤��Ϊlength,ֵΪvalue������
    Linknode<T>* getNext() { return next; }                      //����nextֵ
    T getData() { return data; }                                 //����dataֵ
    void setNext(Linknode<T>* next);                             //�޸�next��ֵ
    void setData(T data);                                        //�޸�dataֵ
    Linknode<T> operator =(const Linknode<T> a) const;           //����=
    Linknode<T> operator =(Linknode<T> a);
    ~Linknode() = default;                                       //����
protected:

private:
    T data;
    Linknode<T>* next;                   
};

//template<typename T>
//Linknode<T>::Linknode(int length, const T& value)
//    : Linknode{ value }
//{
//    for (int i = 1; i < length; i++)
//    {
//        Linknode<T> nullNode(value);
//        nullNode.next = next;
//        next = &nullNode;
//    }
//}

template<typename T>
inline void Linknode<T>::setNext(Linknode<T>* next)
{
    this->next = next;
}

template<typename T>
inline void Linknode<T>::setData(T data)
{
    this->data = data;
}

template<typename T>
inline Linknode<T> Linknode<T>::operator=(const Linknode<T> a) const
{
    

    return Linknode<T>();
}

template<typename T>
inline Linknode<T> Linknode<T>::operator=(Linknode<T> a)
{
    //data = a.data;
    //next = a.next;
    //return this;
}
