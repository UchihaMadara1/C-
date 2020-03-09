#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vld.h>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;

namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
		friend istream& operator>>(istream& _cin, bit::string& s);
	public:
		static const size_t npos = -1;
	public:
		typedef char* iterator;
	public:
		string(const char *str = "") :m_str(nullptr)
		{
			m_capacity = m_size = strlen(str);
			m_str = new char[m_capacity + 1];  // \0
			strcpy(m_str, str);
		}
		string(const string &s) : m_str(nullptr), m_capacity(0), m_size(0)
		{
			string tmp(s.m_str);
			_swap(*this, tmp);
		}
		string& operator=(const string &s)
		{
			if (this != &s)
			{
				string tmp(s);
				_swap(*this, tmp);
			}
			return *this;
		}
		~string()
		{
			if (m_str)
			{
				delete[]m_str;
				m_str = nullptr;
			}
			m_capacity = m_size = 0;
		}
	public:
		iterator begin()
		{
			return m_str;
		}
		iterator end()
		{
			return m_str + size();
		}
	public:
		size_t size()const
		{
			return m_size;
		}
		size_t capacity()const
		{
			return m_capacity;
		}
		bool empty()const
		{
			return m_size == 0;
		}
		void clear()
		{
			m_size = 0;
			m_str[0] = '\0';
		}
	public:
		const char* c_str()const
		{
			return m_str;
		}
	public:
		void push_back(char c)
		{
			if (m_size >= m_capacity)
				reserve(m_capacity * 2);
			m_str[m_size++] = c;
			m_str[m_size] = '\0';
		}
	public:
		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		void append(const char* str)
		{
			int str_len = strlen(str);
			if (str_len + m_size > m_capacity)
			{
				reserve((m_capacity + str_len) * 2);
			}
			strcpy(m_str + m_size, str);
			m_size += str_len;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > m_size)
			{
				if (newSize > m_capacity)
				{
					reserve(newSize * 2);
				}
				memset(m_str + m_size, c, newSize - m_size);
			}
			m_size = newSize;
			m_str[m_size] = '\0';
		}

		bool operator<(const string& s)
		{
			return (strcmp(m_str, s.m_str) < 0);
		}
		bool operator<=(const string& s)
		{
			return !(*this > s);
		}
		bool operator>(const string& s)
		{
			return (strcmp(m_str, s.m_str) > 0);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator==(const string& s)
		{
			return (strcmp(m_str, s.m_str) == 0);
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (int i = pos; i < m_size; ++i)
			{
				if (m_str[i] == c)
					return i;
			}
			return npos;
		}
		// 返回子串s在string中第一次出现的位置
		//朴素的模式匹配 -->  KMP  strstr
		size_t find(const char* s, size_t pos = 0) const
		{
			size_t i = pos, j = 0;
			size_t s_len = strlen(s);
			while (i < m_size && j < s_len)
			{
				if (m_str[i] == s[j])
				{
					i++;
					j++;
				}
				else
				{
					i = i - j + 1;
					j = 0;
				}
			}
			if (j >= s_len)
			{
				return i - j;
			}
			return npos;
		}
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			if (m_size + 1 > m_capacity)
			{
				reserve((m_size + 1) * 2);
			}
			for (size_t i = m_size; i > pos; --i)
			{
				m_str[i] = m_str[i - 1];
			}
			m_str[pos] = c;
			m_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			//
			return *this;
		}
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len)
		{
			memcpy(m_str + pos, m_str + pos + len, m_size - pos - len + 1);
			m_size -= len;
			return *this;
		}
	public:
		char& operator[](int i)
		{
			assert(i >= 0 && i < m_size);
			return m_str[i];
		}
		const char& operator[](size_t i)const
		{
			assert(i >= 0 && i<m_size);
			return m_str[i];
		}
	public:
		void reserve(size_t new_cpy)
		{
			if (new_cpy > m_capacity)
			{
				char *new_str = new char[new_cpy + 1];
				memcpy(new_str, m_str, m_size + 1);
				m_capacity = new_cpy;
				delete[]m_str;
				m_str = new_str;
			}
		}
	protected:
		static void _swap(string &s1, string &s2)
		{
			std::swap(s1.m_str, s2.m_str);
			std::swap(s1.m_capacity, s2.m_capacity);
			std::swap(s1.m_size, s2.m_size);
		}
	private:
		char * m_str;
		size_t m_capacity;
		size_t m_size;
	};
	ostream& operator<<(ostream &out, const string &s)
	{
		for (int i = 0; i < s.m_size; ++i)
		{
			out << s.m_str[i];
		}
		//out<<s.m_str;
		return out;
	}
	////////////////////////////////////////////////////////////////
	//?????????
	istream& operator>>(istream& _cin, bit::string& s)
	{
		char *str = (char *)malloc(sizeof(char)* 10);
		char *buf = str;
		size_t count = 1;
		//跳过字符串起始位置的空格或者换行
		while ((*buf = getchar()) == ' ' || (*buf == '\n'));
		for (;;)
		{
			if (*buf == '\n' || *buf == ' ')
			{
				*buf = '\0';
				break;
			}
			else if (count % 10 == 0)
			{
				str = (char *)realloc(str, count * 2);
				//重新定位buf的位置
				buf = str + count;
				count++;
				*buf = getchar();
			}
			else
			{
				*++buf = getchar();
				count++;
			}
		}
		s.m_str = str;
		s.m_capacity = s.m_size = count;
		return _cin;
	}
}
void main()
{
	bit::string str("Hello C++");
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << "str = " << str << endl;
	str.push_back('x');
	str.reserve(20);
	str += 'x';
	str.append(" Linux.");
	str += " Linux";
	str.reserve(20);
	str.resize(15, '@');
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << "str = " << str << endl;
}