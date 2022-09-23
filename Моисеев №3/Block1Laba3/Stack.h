#pragma once  

template<class T>
class Stack
{
private:
	template<class T>
	class ElementStack
	{
	public:
		ElementStack* cfoll; 
		T* cdata;
		ElementStack(T* cdata = nullptr, ElementStack* cfoll = nullptr) : cdata(cdata), cfoll(cfoll) {};
	};

	int m_length;
	ElementStack<T>* cFirst;  
	ElementStack<T>* cLast;  
public:
	class Iterator
	{
		ElementStack<T>* cElementStack;
	public:
		Iterator(ElementStack<T>* it = nullptr) : cElementStack(it) {};
		ElementStack<T>* getPLI() { return cElementStack; }


		Iterator operator =(Iterator* right) {
			return right;
		}
		Iterator operator ++(int val) {
			if (this->cElementStack) this->cElementStack = this->cElementStack->cfoll;
			return *this;
		}

		T* operator *() {
			return this->cElementStack->cdata;
		}

		ElementStack<T>* operator ->() {
			return this->cElementStack;
		}

		bool operator ==(Iterator* it) { return this->cElementStack == it->cElementStack; }
		bool operator != (Iterator* it) { return this->cElementStack != it->cElementStack; }
	};

	Stack() : m_length(0), cFirst(nullptr), cLast(nullptr) {};

	int length() { return m_length; }

	T* pop() {
		T* cdata = nullptr;
		if (cFirst) {
			if (cFirst->cfoll == nullptr) {
				cdata = cFirst->cdata;
				delete cFirst;
				cLast = cFirst = nullptr;
			}
			else
			{
				ElementStack<T>* cElement = cFirst->cfoll;
				cdata = cFirst->cdata;
				delete cFirst;
				cFirst = nullptr;
				cFirst = cElement;
			}
			m_length--;
		}
		return cdata;

	}

	void push(T* cdata) {
		ElementStack<T>* cNewElement = new ElementStack<T>(cdata);
		if (!cFirst)
		{
			cFirst = cNewElement;
			cLast = cNewElement;
		}
		else {
			cNewElement->cfoll = cFirst;
			cFirst = cNewElement;
		}
		m_length++;
	}

	ElementStack<T>* front() { return cFirst; }
	ElementStack<T>* back() { return cLast; }
};