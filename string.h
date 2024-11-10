#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<cstring>
#include<assert.h>
namespace bit
{
    class string
    {
    public:
        friend std::ostream& operator<<(std::ostream& _cout, const bit::string& s);
        friend std::istream& operator>>(std::istream& _cin, bit::string& s);
        typedef char* iterator;
        static size_t npos;
    public:
        string(const char* str);
        string(const string& s);
        string& operator=(const string& s);
        ~string();
        //////////////////////////////////////////////////////////////
        // iterator
        iterator begin() const;
        iterator end() const;
        /////////////////////////////////////////////////////////////
        // modify
        void push_back(char c);
        string& operator+=(char c);
        void append(const char* str);
        string& operator+=(const char* str);
        void clear();
        void swap(string& s);
        const char* c_str()const;
        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const;
        size_t capacity()const;
        bool empty()const;
        void resize(size_t n, char c = '\0');
        void reserve(size_t n);
        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index);
        const char& operator[](size_t index)const;
        /////////////////////////////////////////////////////////////
        //relational operators
        bool operator<(const string& s);
        bool operator<=(const string& s);
        bool operator>(const string& s);
        bool operator>=(const string& s);
        bool operator==(const string& s);
        bool operator!=(const string& s);
        // ����c��string�е�һ�γ��ֵ�λ��
        size_t find(char c, size_t pos = 0) const;
        // �����Ӵ�s��string�е�һ�γ��ֵ�λ��
        size_t find(const char* s, size_t pos = 0) const;
        // ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);
        // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
        string& erase(size_t pos, size_t len);
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };

}