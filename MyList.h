#pragma once
template <typename Telem>
class Iterator;

template <typename Telem>
class MyList {
public:

	/*Constructor default
	* se creaza un MyList cu capacitatea 5 si len = 0
	*/
	MyList();

	/*Constructor de copiere
	* Se copiaza in lista actuala elementele si atributele listei ot
	*/
	MyList(const MyList& ot);

	/*operator de asignare
	*/
	MyList& operator=(const MyList& ot);

	//move constructor
	MyList(MyList&& ot);

	//move assignment
	MyList& operator=(MyList&& ot);

	void push_back(const Telem& e);


	//returneaza lungimea listei
	auto size() const ;

	//returneaza elementul de la pozitia i
	Telem& at(const int i) const;

	//sterge elementul de la pozitia iteratorului dat ca parametru
	void erase(const Iterator<Telem>& it);

	/*Destructor
	*/
	~MyList();

	friend class Iterator<Telem>;
	Iterator<Telem> begin() const;
	Iterator<Telem> end() const;


private:
	int cap;
	int len;
	Telem* v;
	void redimensionare();
};


template <typename Telem>
MyList<Telem>::MyList() : v{ new Telem[5] }, cap{ 5 }, len{ 0 } {

}

template <typename Telem>
MyList<Telem>::MyList(const MyList& ot) {
	this->cap = ot.cap;
	this->len = ot.len;
	this->v = new Telem[ot.cap];
	if(ot.len>=this->len){
		for (int i = 0; i < len; i++) {
			this->v[i] = ot.v[i];
		}
	}
}

template <typename Telem>
MyList<Telem>& MyList<Telem>::operator=(const MyList& ot) {
	if (this == &ot) {
		return *this;
	}
	else {
		delete[] this->v;
		this->v = new Telem[ot.cap];
		this->cap = ot.cap;
		this->len = ot.len;
		if (ot.len >= this->len) {
			for (int i = 0; i < len; i++) {
				this->v[i] = ot.v[i];
			}
			return *this;
		}
		else {
			return *this;
		}
	}
}

template <typename Telem>
MyList<Telem>::~MyList() {
	delete[] this->v;
}
template <typename Telem>
MyList<Telem>::MyList(MyList&& ot) {
	v = ot.v;
	cap = ot.cap;
	len = ot.len;

	ot.v = nullptr;
	ot.cap = 0;
	ot.len = 0;
}

template <typename Telem>
MyList<Telem>& MyList<Telem>::operator=(MyList&& ot) {
	if (this == &ot) {
		return *this;
	}
	delete[] v;
	v = ot.v;
	cap = ot.cap;
	len = ot.len;

	ot.v = nullptr;
	ot.cap = 0;
	ot.len = 0;
	return *this;
}


template <typename Telem>
auto MyList<Telem>::size()const {
	return this->len;
}

template <typename Telem>
void MyList<Telem>::push_back(const Telem& e) {
	if (this->len == this->cap) {
		redimensionare();
	}
	this->v[len++] = e;
}

template <typename Telem>
void MyList<Telem>::redimensionare() {
	int newCap = 2 * this->cap;
	Telem* newElems = new Telem[newCap];
	for (int i = 0; i < len; i++) {
		newElems[i] = this->v[i];
	}
	delete[] this->v;
	this->v = newElems;
	this->cap = newCap;
}

template <typename Telem>
Telem& MyList<Telem>::at(const int i) const{
		return this->v[i];
}

template <typename Telem>
Iterator<Telem> MyList<Telem>::begin() const{
	return Iterator<Telem>(*this);
}

template <typename Telem>
Iterator<Telem> MyList<Telem>::end() const{
	return Iterator<Telem>(*this, len);
}

template <typename Telem>
class Iterator {
private:
	const MyList<Telem>& l;
	int poz;
public:
	Iterator(const MyList<Telem>& list);
	Iterator(const MyList<Telem>& list, int poz);
	bool valid()const;
	Telem& element() const;
	void next();
	bool operator==(const Iterator& ot) noexcept;
	bool operator!=(const Iterator& ot) noexcept;
	Telem& operator*();
	Iterator& operator++();
	Iterator& operator+(const int i);
	friend class MyList<Telem>;
};

template <typename Telem>
Iterator<Telem>::Iterator(const MyList<Telem>& list) :l{ list }, poz{ 0 }{
	
}

template <typename Telem>
Iterator<Telem>::Iterator(const MyList<Telem>& list, int poz) : l{ list }, poz{ poz }{

}

template <typename Telem>
bool Iterator<Telem>::valid()const {
	if (poz < l.len) {
		return true;
	}
	return false;
}

template <typename Telem>
Telem& Iterator<Telem>::element() const {
	return l.v[poz];
}

template <typename Telem>
void Iterator<Telem>::next() {
	poz++;
}

template <typename Telem>
Telem& Iterator<Telem>::operator*() {
	return element();
}

template <typename Telem>
Iterator<Telem>& Iterator<Telem>::operator++() {
	next();
	return *this;
}

template <typename Telem>
bool Iterator<Telem>::operator==(const Iterator& ot) noexcept {
	return ot.poz == poz;
}

template <typename Telem>
bool Iterator<Telem>::operator!=(const Iterator& ot) noexcept {
	return ot.poz != poz;
}

template <typename Telem>
Iterator<Telem>& Iterator<Telem>::operator+(const int i) {
	poz += i;
	return *this;
}

template <typename Telem>
void MyList<Telem>::erase(const Iterator<Telem>& it) {
	for (int i = it.poz + 1; i < len; i++) {
		this->v[i - 1] = this->v[i]; 
	}
	len--;
}