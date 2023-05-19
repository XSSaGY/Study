#pragma once

/// <summary>
/// ��̬˳���
/// </summary>
class Dynamic_list
{
public:
    int Length();                                                            //���
    void Insert(int location, int elem);                                     //����в���Ԫ��
    bool Delete(int location);                                               //�ڱ���ɾ��Ԫ��
    int LocateElem(int elem);                                                //��ֵ���ұ���Ԫ��
    int& operator [](int index);
    const int& operator [](int index) const;
protected:
    /**
     * @brief ���ߴ粢��������
     * @param sz ��Ҫ�����³ߴ�
    */
    inline void check_resize(int sz);

private:
    int* m_data = nullptr;
    int m_len{};
    int m_cap{};


};
