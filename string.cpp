#include"string.h"
using namespace bit;
//char* _str;
//size_t _capacity;
//size_t _size;
std::ostream& bit::operator<<(std::ostream& _cout, const bit::string& s) {
	_cout << s._str << std::endl;
	return _cout;
}
std::istream& bit::operator>>(std::istream& _cin, bit::string& s) {
	return _cin;
}
string::string(const char* str = "") {
	_str = new char[strlen(str) + 1];
	strcpy(_str, str);
	_size = strlen(str);
	_capacity = _size + 1;
	*(_str + _size) = '\0';
}
string::string(const string& s) {
	_str = new char[strlen(s._str) + 1];
	strcpy(_str, s._str);
	_size = s._size;
	_capacity = s._capacity;
}
string& string::operator=(const string& s) {
	_str = new char[strlen(s._str) + 1];
	strcpy(_str, s._str);
	_size = s._size;
	_capacity = s._capacity;
	return *this;
}
string::~string() {
	delete[] _str;
}
//////////////////////////////////////////////////////////////
// iterator
string::iterator string::begin() const {
	return _str;
}
string::iterator string::end() const {
	return _str + _size - 1;
}
/////////////////////////////////////////////////////////////
// modify
void string::push_back(char c) {
	if (_size == _capacity - 1) {
		reserve(2 * _capacity);
	}
	*(_str + _size) = c;
	*(_str + _size + 1) = '\0';
	_size++;
}
string& string::operator+=(char c) {
	this->push_back(c);
	return *this;
}
void string::append(const char* str) {
	if (strlen(str) > _capacity - _size - 1) {
		reserve(2 * (_capacity + strlen(str)));
	}
	strcpy(_str + _size , str);
	_size += strlen(str);
}
string& string::operator+=(const char* str) {
	append(str);
	return *this;
}
void string::clear() {
	*_str = 0;
	_size = 0;
}
void string::swap(string& s) {
	char* tmp1 = _str;
	size_t tmp2 = _size;
	size_t tmp3 = _capacity;
	_str = s._str;
	_size = s._size;
	_capacity = s._capacity;
	s._str = tmp1;
	s._size = tmp2;
	s._capacity = tmp3;
}
const char* string::c_str() const {
	return this->_str;
}
/////////////////////////////////////////////////////////////
// capacity
size_t string::size() const {
	return _size;
}
size_t string::capacity() const {
	return _capacity;
}
bool string::empty() const {
	if (_size == 0) {
		return true;
	}
	else {
		return false;
	}
}
void string::resize(size_t n, char c) {
	if (n > _size) {
		if (n  > _capacity - 1) {
			reserve(n + 1);
			for (size_t i = _size; i < n; i++) {
				_str[i] = c;
				_size++;
			}
			_str[_size] = '\0';
		}
		else {
			for (size_t i = _size; i < n; i++) {
				_str[i] = c;
				_size++;
			}
			_str[_size] = '\0';
		}
	}
	else {
		_size = n;
		_str[_size] = 0;
	}
}
void string::reserve(size_t n) {
	if (n > _capacity - 1) {
		char* tmp = new char[n];
		strcpy(tmp, _str);
		delete[] _str;
		_str = tmp;
		_capacity = n;
	}
}
/////////////////////////////////////////////////////////////
// access
char& string::operator[](size_t index) {
	return *(_str + index);
}
const char& string::operator[](size_t index)const {
	return *(_str + index);
}
/////////////////////////////////////////////////////////////
//relational operators
bool string::operator<(const string& s) {
	int r = strcmp(_str, s._str);
	if (r < 0) {
		return true;
	}
	else {
		return false;
	}
}
bool string::operator<=(const string& s) {
	int r = strcmp(_str, s._str);
	if (r <= 0) {
		return true;
	}
	else {
		return false;
	}
}
bool string::operator>(const string& s) {
	if (_size > s._size) {
		return true;
	}
	else {
		return false;
	}
}
bool string::operator>=(const string& s) {
	if (_size >= s._size) {
		return true;
	}
	else {
		return false;
	}
}
bool string::operator==(const string& s) {
	if (_size == s._size) {
		string::iterator s1 = this->begin();
		string::iterator s2 = s.begin();
		while (s1 != this->end()) {
			if (*s1 == *s2) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
bool string::operator!=(const string& s) {
	if (_size != s._size) {
		return true;
	}
	else {
		if (*this == s) {
			return true;
		}
		else {
			return false;
		}
	}
}
// 返回c在string中第一次出现的位置
size_t string::find(char c, size_t pos) const {
	size_t cnt = pos;
	while (cnt < _size) {
		if (_str[cnt] == c) {
			return cnt;
		}
		else {
			cnt++;
		}
	}
	return string::npos;
}
// 返回子串s在string中第一次出现的位置
size_t string::find(const char* s, size_t pos) const {
	size_t cmp = 1;
	size_t src = pos;
	while (src != _size) {
		const char* tmp = s;
		size_t index = src;
		while (*tmp != '\0' && index < _size) {
			if (*tmp == _str[index]) {
				index++;
				tmp++;
			}
			else {
				cmp = 0;
				break;
			}
		}
		if (cmp == 1) {
			return src;
		}
		else {
			src++;
			cmp = 1;
		}
	}
	return npos;
}
// 在pos位置上插入字符c/字符串str，并返回该字符的位置
string& string::insert(size_t pos, char c) {
	assert(pos<_size && pos>=0);
	if (_size == _capacity - 1) {
		reserve(2 * _capacity);
	}
	size_t index = _size + 1;
	while (index > pos) {
		_str[index] = _str[index - 1];
		index--;
	}
	_str[pos] = c;
	_size++;
	return *this;
}
string& string::insert(size_t pos, const char* str) {
	assert(pos<_size && pos>=0);
	size_t gap = strlen(str);
	if (_size + gap > _capacity - 1) {
		reserve(2 * (_size + gap));
	}
	size_t index1 = _size + gap + 1;
	size_t index2 = _size + 1;
	while (index2 >= pos) {
		_str[index1] = _str[index2];
		index1--;
		index2--;
	}
	strncpy(_str + pos, str, gap);
	_size += gap;
	return *this;
}
string& string::erase(size_t pos, size_t len) {
	assert(pos<_size && pos>=0);
	assert(pos + len <= _size && len>0);
	size_t index1 = pos + len;
	size_t index2 = pos;
	while (index1 <= _size) {
		_str[index2] = _str[index1];
		index1--;
		index2++;
	}
	_size-=len;
	return *this;
}