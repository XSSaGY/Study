#include "DynamicList.h"
#include <iostream>

/// <summary>
/// ����в���Ԫ��
/// </summary>
/// <param name="len">Ҫ����ĳ���</param>
/// <returns>�ɹ�true ʧ��false</returns>
//bool Dynamic_list::Increase(int len)
//{
//    int* p = data;
//    data = new int[length + len];
//    for (int i = 0; i < length; i++)
//        *(data + i) = *(p + i);
//    length += len;
//    delete [] p;                  
//    return true;
//}

inline void Dynamic_list::check_resize(int sz)
{
    // m_cap ��ǰ����
    // m_size ��ǰ�ߴ�
    // m_data ������ʼ��ַ
    // m_mt д����
    if (sz <= m_cap)
        return;

    auto old_data = m_data;
    auto old_cap = m_cap;
    auto new_cap = m_cap;
    while (sz > new_cap)
        new_cap = new_cap * 2 + 1;
    auto new_data = new int[new_cap];    // may throw

    //std::lock_guard<mutex> guard(m_mt);

    m_cap = new_cap;
    m_data = new_data;

    for (int index = 0; index < m_len; ++index)
        *(m_data + index) = *(old_data + index);
    delete[] old_data;
}

int& Dynamic_list::operator[](int index)
{
    return m_data[index];
}

const int& Dynamic_list::operator[](int index) const
{
    return m_data[index];
}

/// <summary>
/// ���ر���
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
int Dynamic_list::Length()
{
    return m_len;
}
/// <summary>
/// ����в���Ԫ��
/// </summary>
/// <param name="L">˳���</param>
/// <param name="location">Ҫ�����λ��</param>
/// <param name="elem">Ҫ�����Ԫ��</param>
/// <returns>�ɹ�����trueʧ�ܷ���false</returns>
void Dynamic_list::Insert(int location, int elem)
{
    check_resize(m_len + 1);
    ++m_len;
    for (int i = m_len - 1; i > location; i--)
        m_data[i] = m_data[i - 1];
    m_data[location] = elem;
}
/// <summary>
/// ɾ������Ԫ��
/// </summary>
/// <param name="L">��</param>
/// <param name="location">ɾ��Ԫ�ص�λ��</param>
/// <param name="e">ɾ��Ԫ�ص�ֵ</param>
/// <returns>�ɹ�trueʧ��false</returns>
bool Dynamic_list::Delete(int location)
{
    if (location >= m_len)
        return false;
    --m_len;
    for (int i = location; i < m_len - 1; i++)
        m_data[i] = m_data[i + 1];
    return true;
}
/// <summary>
/// ��ֵ����
/// </summary>
/// <param name="L">��</param>
/// <param name="elem">���ҵ�Ԫ��</param>
/// <returns>�±�</returns>
int Dynamic_list::LocateElem(int elem)
{
    for (int i = 0; i < m_len; i++)
    {
        if (m_data[i] == elem)
            return i;
    }
    return -1;
}