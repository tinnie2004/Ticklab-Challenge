#include "main.h"

class getFile
{
    private: 
    long long m_line {};
    string m_data{};
    getFile* m_next{};

    public:
    
    //Cấp phát động 
    getFile* makeNode(long long line, string data)
    {
        getFile* temp = new getFile();
        temp->m_line = line;
        temp->m_data = data;
        temp->m_next = NULL;
        return temp;
    }

    //Số phần tử trong danh sách liên kết
    int Size(getFile* a)
    {
        int count = 0;
        while (a != NULL)
        {
            a = a->m_next; 
            ++count;
        }
        return count;
    }

    //insert a member at the last of linked list
    void insertLast(getFile* &a, long long line, string data)
    {
        getFile* tmp = makeNode(line, data);
        if (a == NULL)
        {
            a = tmp;
        }
        else
        {
            getFile* p = a;
            while(p->m_next != NULL)
            {
                p = p->m_next;
            }
            p->m_next = tmp;
        }
    }

    //Check linked list
    void print(getFile* a)
    {
        while (a != NULL)
        {
            cout << a->m_line << '\t' << a->m_data << endl;
            a = a->m_next;
        }
    }
};

void checkSyntax(string file_input, getFile* &head)
{
    //Read file and transfer to class getFile
    fstream MIPS_file;
    MIPS_file.open(file_input, ios::in);
    string filein;
    long long count = 1;
    while ( getline(MIPS_file, filein) )
    {
        head->insertLast(head, count, filein);
        ++count;
    }

    head->print(head);
}