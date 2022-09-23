#pragma once  

template<class T>
class Queue
{
private:
	template<class T>
	class ElementQueue
	{
	public:
		ElementQueue* cfoll;
		T* cdata;
		ElementQueue(T* cdata = nullptr, ElementQueue* cfoll = nullptr) : cdata(cdata), cfoll(cfoll) {};
	};

	int m_length;
	ElementQueue<T>* cFirst;  
	ElementQueue<T>* cLast;
public:
	class Iterator
	{
		ElementQueue<T>* cElementQueue;
	public:
		Iterator(ElementQueue<T>* it = nullptr) : cElementQueue(it) {};
		ElementQueue<T>* getPLI() { return cElementQueue; }


		Iterator operator =(Iterator* right) {
			return right;
		}
		Iterator operator ++(int val) {
			if (this->cElementQueue) this->cElementQueue = this->cElementQueue->cfoll;
			return *this;
		}

		T* operator *() {
			return this->cElementQueue->cdata;
		}

		ElementQueue<T>* operator ->() {
			return this->cElementQueue;
		}

		bool operator ==(Iterator* it) { return this->cElementQueue == it->cElementQueue; }
		bool operator != (Iterator* it) { return this->cElementQueue != it->cElementQueue; }
	};

	Queue() : m_length(0), cFirst(nullptr), cLast(nullptr) {};

	int length() { return m_length; }

	
	T* pop_front() {
		T* cdata = nullptr;
		if (cFirst) {
			if (cFirst->cfoll == nullptr) {
				cdata = cFirst->cdata;
				delete cFirst;
				cLast = cFirst = nullptr;
			}
			else
			{
				ElementQueue<T>* cElement = cFirst->cfoll;
				cdata = cFirst->cdata;
				delete cFirst;
				cFirst = nullptr;
				cFirst = cElement;
			}
			m_length--;
		}
		return cdata;

	}

	void push_back(T* cdata) {
		ElementQueue<T>* cNewElement = new ElementQueue<T>(cdata);
		if (!cFirst)
		{
			cFirst = cNewElement;
			cLast = cNewElement;
		}
		else
		{
			cLast->cfoll = cNewElement;
			cLast = cNewElement;
		}

		m_length++;
	}

	ElementQueue<T>* front() { return cFirst; }
	ElementQueue<T>* back() { return cLast; }
};