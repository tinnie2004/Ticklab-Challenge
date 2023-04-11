#include "lexer.h"
// IMPLEMENT CLASS GETFILE 
    getFile* getFile::makeNode(long long line, string data)
    {
        getFile* temp = new getFile();
        temp->m_line = line;
        temp->m_data = data;
        temp->m_next = NULL;
        return temp;
    }

    //Số phần tử trong danh sách liên kết
    int getFile::Size(getFile* a)
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
    void getFile::insertLast(getFile* &a, long long line, string data)
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
    void getFile::print(getFile* a)
    {
        while (a != NULL)
        {
            cout << a->m_line << '\t' << a->m_data << endl;
            a = a->m_next;
        }
    }

    string getFile::getData() {return m_data;}
    long long getFile::getLine() {return m_line;}
    getFile* getFile::getNode() { return m_next; }


// IMPLEMENT CLASS LABEL LIST
LabelList* LabelList::makeNode(long long line, string word)
{
        LabelList* temp = new LabelList();
        temp->line = line;
        temp->label = word;
        temp->next = NULL;
        return temp;
}

void LabelList::insertLast(LabelList* &a, long long line, string word)
{
    LabelList* tmp = makeNode(line, word);
    if (a == NULL)
        a = tmp;

    else
    {
        LabelList* p = a;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}







/////////////////////////////////////////////////////////////////


void checkSyntax(string file_input, getFile* &head, Label* & label, LabelList* &labellist)
{
    //Read file and transfer to class getFile
    fstream MIPS_file;
    MIPS_file.open(file_input, ios::in);
    string filein;
    long long line = 1;
    while ( getline(MIPS_file, filein) )
    {
        head->insertLast(head, line, filein);
        ++line;
    }


    // Find words which is considered to be a label
    getFile* a = head;
        while ( a != NULL)
    {
        find_label(label, a);
        a=a->getNode();
    }
    
    // is Label? and store Labels
    Label* test = label;
    //while (test != NULL)
    //{
    //    cout << test->test_line << '\t' << test->label_test <<endl;
    //    test = test->next;
    //}
    while( test != NULL )
    {
        if ( isLabel(test) )
        {
            labellist->insertLast(labellist, test->test_line, test->label_test);
            test = test->next;
        }
        else 
        {
            cout << "Error: Line " << test->test_line << endl;
            return;
        }
    }

    LabelList* list = labellist;
    while (list != NULL)
    {
        cout << list->line << '\t' << list->label <<endl;
        list = list->next;
    }

    
    return;
}

void find_label(Label* &test, getFile* a)
{
    //Split each line in .asm file into word
    string str1 = a->getData();
    //char* str1_new = str1;
    char* word;
    /*int j = 0, ctr = 0;
    for (int i = 0; i <= strlen( str1 ); i++)
    {
        // if space or NULL found, assign NULL into word[ctr]
        if(str1[i]==' '||str1[i]=='\0' || str1[i] == '\t')
        {
            word[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            word[ctr][j]=str1[i];
            j++;
        }
    }*/

    // Find words which is considered to be labels
    //for (int i = 0; i < ctr; i++)
    //{
        char *find;
        find = strchr(str1.c_str(), ':');
        if (find != NULL)
        {   
            for (int i = 0; i <= str1.length(); i++)
            {
                word[i] = str1[i];
            }

            while( word[0] == ' ')
            {
                for(int i = 0; i < strlen(word); i++)
                {
                    word[i] = word[i+1];
                }
            }

            while( word[strlen(word) - 1] == ':' || word[strlen(word) - 1] == ' ')
            {
                word[strlen(word) - 1] = '\0';
            }

            string s = word;
            //cout << s << endl;
            insertLast(test, a->getLine(), s);
            //delete word;
        }
    //}
}

void insertLast(Label* &a, long long line, string word)
{
    Label* tmp = makeNode(line, word);
    if (a == NULL)
        a = tmp;

    else
    {
        Label* p = a;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

Label* makeNode(long long line, string word)
{
        Label* temp = new Label();
        temp->test_line = line;
        temp->label_test = word;
        temp->next = NULL;
        return temp;
}

bool isLabel(Label* l)
{
    if ( !( ( l->label_test[0] >= 65 && l->label_test[0] <= 90 ) || ( l->label_test[0] >= 97 && l->label_test[0] <= 122 ) ) )
        return 0;
    for (int i = 1; i < l->label_test.length(); i++)
    {
        if ( !( ( l->label_test[i] >= 65 && l->label_test[i] <= 90 ) || ( l->label_test[i] >= 97 && l->label_test[i] <= 122 ) || ( l->label_test[i] >= 48 && l->label_test[i] <= 57 ) || l->label_test[i] == '_' ) )
        return 0;    
    }

    return 1;
}
