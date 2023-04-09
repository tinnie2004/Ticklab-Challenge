#include "main.h"
#ifndef __LEXER_H__
#define __LEXER_H__

class getFile
{
    private: 
    long long m_line {};
    string m_data{};
    getFile* m_next{};

    public:
    
    getFile* makeNode(long long line, string data);
    int Size(getFile* a);
    void insertLast(getFile* &a, long long line, string data);
    void print(getFile* a);

};

void checkSyntax(string file_input, getFile* &head);





#endif