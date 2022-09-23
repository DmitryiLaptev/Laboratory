#pragma once  

template<class T>
class List
{
private:
	template<class T>
	class ElementList
	{
	public:
		ElementList* cFollowing;  
		T* cdata;
		ElementList(T* cdata = nullptr, ElementList* cFollowing = nullptr) : cdata(cdata), cFollowing(cFollowing) {};
	};

	void deleteFollowing(ElementList<T>* cElement) {
		if (cElement->cFollowing) {
			deleteFollowing(cElement->cFollowing);
		}
		delete cElement;
	}

	int m_length;
	ElementList<T>* cFollowing;  
	ElementList<T>* cPrev;     
public:
	class Iterator
	{
		ElementList<T>* cElementList;
	public:
		Iterator(ElementList<T>* it = nullptr) : cElementList(it) {};
		ElementList<T>* getPLI() { return cElementList; }


		Iterator operator =(Iterator* right) {
			return right;
		}
		Iterator operator ++(int val) {
			if (this->cElementList) this->cElementList = this->cElementList->cFollowing;
			return *this;
		}

		T* operator *() {
			return this->cElementList->cdata;
		}

		ElementList<T>* operator ->() {
			return this->cElementList;
		}

		bool operator ==(Iterator* it) { return this->cElementList == it->cElementList; }
		bool operator != (Iterator* it) { return this->cElementList != it->cElementList; }
	};

	List() : m_length(0), cFollowing(nullptr), cPrev(nullptr) {};

	
	void insert_first(T* cdata) {
		ElementList<T>* cNewElement = new ElementList<T>(cdata);
		if (!cFollowing)
		{
			cFollowing = cNewElement;
			cPrev = cNewElement;
		}
		else {
			cNewElement->cFollowing = cFollowing;
			cFollowing = cNewElement;
		}
		m_length++;
	}
	int length() { return m_length; }

	void insert_last(T* cdata) {
		ElementList<T>* cNewElement = new ElementList<T>(cdata);
		if (!cFollowing)
		{
			cFollowing = cNewElement;
			cPrev = cNewElement;
		}
		else
		{
			cPrev->cFollowing = cNewElement;
			cPrev = cNewElement;
		}

		m_length++;
	}
 
	T* removal_first() {
		T* cdata = nullptr;
		if (cFollowing) {
			if (cFollowing->cFollowing == nullptr) {
				cdata = cFollowing->cdata;
				delete cFollowing;
				cPrev = cFollowing = nullptr;
			}
			else
			{
				ElementList<T>* cElement = cFollowing->cFollowing;
				cdata = cFollowing->cdata;
				delete cFollowing;
				cFollowing = nullptr;
				cFollowing = cElement;
			}
			m_length--;
		}
		return cdata;

	}
  
	T* removal_back() {
		T* cdata = nullptr;
		if (cFollowing)   
		{
			if (cFollowing->cFollowing == nullptr) {  
				cdata = cFollowing->cdata;
				delete cFollowing;
				cPrev = cFollowing = nullptr;
			}
			else {  
				ElementList<T>* cElement = cFollowing;
				while (cElement->cFollowing->cFollowing != nullptr)
				{
					cElement = cElement->cFollowing;
				}
				cdata = cElement->cFollowing->cdata;
				delete cElement->cFollowing;
				cElement->cFollowing = nullptr;
				cPrev = cElement;
			}
			m_length--;
		}
		return cdata;
	}

	void insert_after(Iterator pos, T* cdata) {
		ElementList<T>* cElement = new ElementList<T>(cdata);
		if (pos->cFollowing) {
			cElement->cFollowing = pos->cFollowing;
		}
		else cPrev = cElement;
		pos->cFollowing = cElement;
		m_length++;
	}

	void remove_iterator(Iterator pos) {
		if (pos.getPLI() == cFollowing) {
			cFollowing = cFollowing->cFollowing;
			delete pos.getPLI();
			m_length--;
		}
		else if (pos.getPLI() == cPrev) {
			removal_back();
		}
		else {
			ElementList<T>* cElement = cFollowing;
			while (cElement->cFollowing != pos.getPLI()) {
				cElement = cElement->cFollowing;
			}
			auto f = cElement->cFollowing->cFollowing;
			delete cElement->cFollowing;
			cElement->cFollowing = f;
			m_length--;

		}

	}


	void clear() {
		deleteFollowing(cFollowing);
		cPrev = nullptr;
		m_length = 0;
	}


	ElementList<T>* front() { return cFollowing; }
	ElementList<T>* back() { return cPrev; }
};