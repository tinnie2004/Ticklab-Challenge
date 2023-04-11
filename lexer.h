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
    string getData();
    long long getLine();
    getFile* getNode();
};

class LabelList
{
public:
    long long line{};
    string label {};
    LabelList* next {};
public:
    void insertLast(LabelList* &a, long long line, string label);
    LabelList* makeNode(long long line, string label);
    LabelList* getNode();
};
struct Label
{
    long long test_line;
    string label_test;
    Label* next;
};

void find_label(Label* &test, getFile* a);
void insertLast(Label* &a, long long line, string word);
Label* makeNode(long long line, string word);

void checkSyntax(string file_input, getFile* &head, Label* &label, LabelList* &labellist);
bool isLabel(Label* l);
#endif