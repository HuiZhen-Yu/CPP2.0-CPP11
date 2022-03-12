#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    map<const char *, const char *> mp;
    const char *key[3] = {"img", "system", "ip"};
    const char *value[3] = {"d:/a.img", "win7", "193.68.3"};

    /* make_pair���� */
    for (int i = 0; i < 2; i++)
    {
        mp.insert(make_pair(key[i], value[i]));
    }

    /* pair<const char*,const char*> ���� */
    mp.insert(pair<const char *, const char *>(key[2], value[2]));

    /* ������뷽ʽ */
    mp["addr"] = "�й�";

    /* ������ȡԪ�� */
    for (map<const char *, const char *>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }
    /* range for */
    for (auto i : mp)
    {
        cout << i.first << "\t" << i.second << endl;
    }

    char key1[20];
    cout << "�����밴key���ң�";
    cin.getline(key1, 20);
    //����Ԫ��
    for (map<const char *, const char *>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        if (strcmp(iter->first, key1) == 0)
        {
            cout << iter->first << "���ҳ����ˣ�"
                 << "��Ӧ��ֵΪ��" << iter->second << endl;
        }
    }

    //��һ��ɾ����ʽ
    // findֻ�����ڲ������齨������ʽ�����Ҳ�֧��������cin��
    map<const char *, const char *>::iterator iter = mp.find("addr");
    if (iter != mp.end())
    {
        cout << iter->first << "����key���ҳ����ˣ�"
             << "��Ӧ��valueΪ��" << iter->second << endl;
        cout << "��ʼɾ��Ԫ�أ�" << endl;
        mp.erase(iter);
        // break;
    }

    //�ڶ��ַ�ʽɾ��
    //����keyɾ��Ԫ��
    char drop_key[20];
    //����valueɾ��Ԫ��
    char drop_value[20];
    cout << "�����밴keyɾ����";
    cin.getline(drop_key, 20);
    cout << "�����밴valueɾ����";
    cin.getline(drop_value, 20);
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        if (strcmp(iter->first, drop_key) == 0)
        {
            cout << iter->first << "����key���ҳ����ˣ�"
                 << "��Ӧ��valueΪ��" << iter->second << endl;
            cout << "��ʼɾ��Ԫ�أ�" << endl;
            mp.erase(iter);
            break;
        }
        if (strcmp(iter->second, drop_value) == 0)
        {
            cout << iter->second << "value���ҳ����ˣ�"
                 << "��Ӧ��keyΪ��" << iter->first << endl;
            cout << "��ʼɾ��Ԫ�أ�" << endl;
            mp.erase(iter);
            break;
        }
    }
    cout << "------ɾ��Ԫ���Ժ�--------\n";
    //ѭ��ȡ��Ԫ��
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }
    system("pause");
    return 0;
}
