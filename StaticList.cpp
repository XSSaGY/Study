#include <iostream>

using namespace std;

constexpr int MAXLENGTH{ 10 };                                                               //����
/// <summary>
/// ��̬˳���
/// </summary>
class Static_list
{
public:
    bool InitList(Static_list &L);                                                           //��ʼ����
    int Length(Static_list L);                                                               //���
    bool ListInsert(Static_list & L, int location, int elem);                                //����в���Ԫ��
    bool ListDelete(Static_list& L, int location, int& e);                                   //�ڱ���ɾ��Ԫ��
    int LocateElem(Static_list L, int elem);                                                 //��ֵ���ұ���Ԫ��
private:
    int data[MAXLENGTH];
    int length;                                                                              //��ĳ���
};
/// <summary>
/// ��ʼ����
/// </summary>
/// <param name="L">������Static_list���͵ı�</param>
/// <returns>true</returns>
bool Static_list::InitList(Static_list &L) {
    L.length = 0;
    for (int i = 0; i < MAXLENGTH; i++)
    {
        L.data[i] = 0;
    }
    return true;
}
/// <summary>
/// ���ر���
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
int Static_list::Length(Static_list L)
{
    return L.length;
}
/// <summary>
/// ����в���Ԫ��
/// </summary>
/// <param name="L">˳���</param>
/// <param name="location">Ҫ�����λ��</param>
/// <param name="elem">Ҫ�����Ԫ��</param>
/// <returns>�ɹ�����trueʧ�ܷ���false</returns>
bool Static_list::ListInsert(Static_list& L, int location, int elem)
{
    if (location > MAXLENGTH && location > L.length)
    {
        cout << "location is illegal\n";
        return false;
    }
    for (int i = L.length; i >= location; i--)
        L.data[i] = L.data[i - 1];
    L.data[location] = elem;
    L.length++;
    return true;
}
/// <summary>
/// ɾ������Ԫ��
/// </summary>
/// <param name="L">��</param>
/// <param name="location">ɾ��Ԫ�ص�λ��</param>
/// <param name="e">ɾ��Ԫ�ص�ֵ</param>
/// <returns>�ɹ�trueʧ��false</returns>
bool Static_list::ListDelete(Static_list& L, int location, int& e)
{
    if (location >= L.length)
    {
        cout << "location is illegal\n";
        return false;
    }
    e = L.data[location];
    for (int i = location; i < L.length; i++)
        L.data[i] = L.data[i + 1];
    L.length--;
    return true;
}
/// <summary>
/// ��ֵ����
/// </summary>
/// <param name="L">��</param>
/// <param name="elem">���ҵ�Ԫ��</param>
/// <returns>�±�</returns>
int Static_list::LocateElem(Static_list L, int elem)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == elem)
            return i;
    }
}