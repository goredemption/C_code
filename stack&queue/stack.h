#pragma once
#include<deque>
using namespace std;
namespace bit {
    template<class T, class Con = deque<T>>
    class stack
    {
    public:
        stack(const Con& ctnr = Con()) {
            _c = ctnr;
        }
        void push(const T& x) {
            _c.push_back(x);
        }
        void pop() {
            _c.pop_back();
        }
        T& top() {
            return _c.back();
        }
        const T& top()const {
            return _c.back();
        }
        size_t size()const {
            return _c.size();
        }
        bool empty()const {
            return _c.empty();
        }
    private:
        Con _c;
    };
}
