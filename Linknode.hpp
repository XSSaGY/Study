#pragma once

template <typename T>                                           //使用模板
class Linknode
{
public:
    Linknode()                                                  //委托构造
        : Linknode({})
    {}
    Linknode(T value)                                           //值在方括号中
        : data{ value }, next{ nullptr }
    {}

    
    Linknode<T>* getNext() { return next; }                      //返回next值
    T& getData() { return data; }                                //返回data值
    void setNext(Linknode<T>* next);                             //修改next的值
    void setData(T data);                                        //修改data值
    Linknode<T> operator =(const Linknode<T> a) const;           //重载=
    friend bool operator==(Linknode<T> node1, T val)             //重载==运算符
    {
        if (node1.getData() == val)
            return true;
        return false;
    }
    ~Linknode() = default;                                       //析构
protected:

private:
    T data;
    Linknode<T>* next;                   
};

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