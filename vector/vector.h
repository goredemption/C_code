#pragma once
#include<string.h>
#include<iostream>
namespace bit
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;
        
        iterator begin() {
            return _start;
        }
        iterator end() {
            return _finish;
        }
        const_iterator cbegin() const {
            return _start;
        }
        const_iterator cend() const {
            return _finish;
        }
        // construct and destroy

        vector(){
            ;
        }

        vector(int n, const T& value = T()) {
            resize(n, value);
        }

        template<class InputIterator>

        vector(InputIterator first, InputIterator last) {
            reserve(last - first + 1);
            auto t_start = _start;
            while (first <= last) {
                *t_start = *first;
                first++;
                t_start++;
            }
        }

        vector(const vector<T>& v) {
            reserve(v.capacity());
            /*auto v_start = v._start;
            auto v_finish = v._finish;
            auto tstart = _start;
            while (v_start <= v_finish) {
                *tstart = *(v_start);
                tstart++;
                (v_start)++;
            }
            _finish = tstart;
            _endOfStorage = _start + v.capacity() - 1;*/
            for (int i = 0;i < v.size();i++) {
                _start[i] = v._start[i];
            }
            _finish = _start + v.size();
            _endOfStorage = _start + v.capacity();
        }

        vector<T>& operator= (vector<T> v) {
            if (capacity() >= v.capacity()) {
                for (int i = 0;i < v.size();i++) {
                    _start[i] = (v._start)[i];
                }
            }
            else {
                reserve(v.capacity());
                for (int i = 0;i < v.size();i++) {
                    _start[i] = (v._start)[i];
                }
            }
        }

        ~vector() {
            delete[] _start;
        }

        // capacity

        size_t size() const {
            return _finish - _start;
        }

        size_t capacity() const {
            return _endOfStorage - _start;
        }

        void reserve(size_t n) {
            if (n > capacity()) {
                //auto tstart = _start;
                //auto dstart = _start;
                //auto tfinish = _finish;
                //_start = new t[n];
                //while (tstart <= tfinish) {
                //    *_start = *tstart;
                //    _start++;
                //    tstart++;
                //}
                //delete[] dstart;
                //_finish = _start;
                ////using the original _start value
                //_endofstorage = dstart + n - 1;
                //_start = dstart;
              
                auto p_start = _start;
                int m = size();
                _start = new T[n];
                for (int i = 0;i < m;i++) {
                    _start[i] = p_start[i];
                }
                delete[] p_start;
                _finish = _start + m;
                _endOfStorage = _start + n;
            }
            else if (capacity() == 0) {
                _start = new T[5];
                _finish = _start;
                _endOfStorage = _start + 5;
            }
        }

        void resize(size_t n, const T& value = T()) {
            if (n > capacity()) {
                reserve(n);
                for (int i = size();i < n;i++) {
                    _start[i] = value;
                }
            }
            else if (n > size()) {
                for (int i = size();i < n;i++) {
                    _start[i] = value;
                }
            }
            else {
                auto t_start = _start;
				_start = new T[n];
                _finish = _start + n;
                for (int i = 0;i < n;i++) {
                    _start[i] = t_start[i];
                }
                _endOfStorage = _start + n;
                delete[] t_start;
            }
        }

        ///////////////access///////////////////////////////

        T& operator[](size_t pos) {
            return *(_start + pos);
        }
        const T& operator[](size_t pos)const {
            return *(_start + pos);
        }

        ///////////////modify/////////////////////////////
        void push_back(const T& x) {
            if (capacity() == size()) {
                reserve(2 * capacity());
            }
            *_finish = x;
            _finish++;
        }
        void pop_back() {
            --_finish;
        }
        void swap(vector<T>& v) {
            auto t_start = _start;
            auto t_finish = _finish;
            auto t_endOfStorage = _endOfStorage;
            _start = v._start;
            _finish = v._finish;
            _endOfStorage = v._endOfStorage;
            v._start = t_start;
            v._finish = t_finish;
            v._endOfStorage = t_endOfStorage;
        }
        iterator insert(iterator pos, const T& x) {
            int gap = pos - _start;
            if (capacity() == size()) {
                reserve(2 * capacity());
            }
            pos = _start + gap;
            iterator tmp = pos;
            iterator rear = end();
			while (rear > pos) {
				*rear = *(rear - 1);
				rear--;
			}
            *tmp = x;
            _finish++;
            return tmp;
        }
        iterator erase(iterator pos) {
            iterator tmp = pos;
            while (pos < _finish - 1) {
                *pos = *(pos + 1);
                pos++;
            }
            _finish--;
            return tmp;
        }

    

    private:
        iterator _start=nullptr; // 指向数据块的开始
        iterator _finish=nullptr; // 指向有效数据的尾
        iterator _endOfStorage=nullptr; // 指向存储容量的尾
    };
    
    template<class T>
    void print_vector(const vector<T>& v)
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;

        //typename vector<T>::const_iterator it = v.begin();
        /*auto it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;*/
    }

    void test_vector1()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(4);
        v1.push_back(4);
        print_vector(v1);

        vector<double> v2;
        v2.push_back(1.1);
        v2.push_back(2.2);
        v2.push_back(3.1);
        print_vector(v2);

        v2.insert(v2.begin(), 11.11);
        print_vector(v2);

        v2.insert(v2.begin(), 11.11);
        print_vector(v2);

        v2.insert(v2.begin(), 11.11);
        print_vector(v2);

        v2.insert(v2.begin(), 11.11);
        print_vector(v2);

        v2.insert(v2.begin(), 11.11);
        print_vector(v2);

        v2.erase(v2.begin());
        print_vector(v2);

        v2.erase(v2.begin() + 4);
        print_vector(v2);

        /*for (size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        vector<int>::iterator it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;*/
    }

    void test_vector2()
    {
        int i = 1;
        int j = int();
        int k = int(2);

        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(4);
        v1.push_back(4);
        print_vector(v1);

        v1.resize(10);
        print_vector(v1);

        v1.resize(3);
        print_vector(v1);
    }

    void test_vector3()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(4);
        v1.push_back(4);
        print_vector(v1);

        vector<int> v2(v1);
        print_vector(v2);
    }
}