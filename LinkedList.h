

template <typename T>
class LList {
public:
	LList() : head(nullptr) {}

	void pushFront(const T& _data);
	void pushBack(const T& _data);
	void reverse();
	void print();
	void remove();
	bool popFront();
	bool popBack();
	const T& getAt(T&) const;
	size_t size() const;
	bool insertAt(size_t, const T&);
	bool deleteAt(size_t i);
	const T& operator[] (size_t i);
	void swap(size_t, size_t);

private:
	struct Node {
		T data;
		Node* next;

		Node() : data(nullptr), next(nullptr) {};
		Node(const T& _data, Node* _next = nullptr) : data(_data) {};
	};

	Node* head;


public:
	class Iterator
	{
	public:
		Iterator(Node* init) : current(init) {};

		bool operator != (const Iterator& other) const;
		bool operator == (const Iterator& other) const;
		Iterator& operator++();
		T operator *();

	private:
		Node* current;

	};

	Iterator begin();
	Iterator end();

};

template<typename T>
void LList<T>::pushFront(const T& _data) {
	Node* newNode = new Node(_data, nullptr);
	newNode->next = head;
	head = newNode;
}

template<typename T>
void LList<T>::pushBack(const T& _data) {
	Node* newNode = new Node(_data);
	Node* curr = head;

	if (head == nullptr)
	{
		head = newNode;
		head->next = nullptr;
		return;
	}

	while (curr->next) {
		curr = curr->next;
	}
	curr->next = newNode;
	curr->next->next = nullptr;
}

template<typename T>
bool LList<T>::popFront() {
	Node* curr = head;
	if (curr == nullptr)
	{
		return false;
	}

	head = head->next;
	head->next = head->next;
	delete curr;
	curr = nullptr;

	return true;
}

template<typename T>
bool LList<T>::popBack() {
	Node* curr = head;
	if (curr == nullptr)
	{
		return false;
	}
	while (curr->next->next) {
		curr = curr->next;
	}
	delete curr->next;
	curr->next = nullptr;

	return true;
}

template<typename T>
const T& LList<T>::getAt(T& data) const
{
	Node* curr = head;
	while (curr) {
		if (curr->data == data) {
			return curr->data;
		}
		curr = curr->next;
	}
	std::cout << "invalid!";
	return head->data;
}

template<typename T>
size_t LList<T>::size() const {
	Node* curr = head;
	size_t sizeOfList = 0;

	while (curr != nullptr)
	{
		++sizeOfList;
		curr = curr->next;
	}
	return sizeOfList;
}

template<typename T>
void LList<T>::reverse() {
	Node* previous = nullptr;
	Node* next = nullptr;
	Node* curr = head;

	while (curr) {
		next = curr->next;
		curr->next = previous;
		previous = curr;
		curr = next;
	}

	head = previous;
}

template<typename T>
void LList<T>::print()
{
	Node* curr = head;
	while (curr) {
		std::cout << curr->data << ", ";
		curr = curr->next;
	}
}

template<typename T>
void LList<T>::remove() {
	Node* curr = head;
	Node* currNext = nullptr;

	while (curr)
	{
		currNext = curr->next;
		free(curr);
		curr = currNext;
	}

	head = nullptr;
}

template<typename T>
bool LList<T>::insertAt(size_t i, const T& _data) {
	Node* curr = head;
	Node* newNode = new Node(_data);
	size_t index = 1;

	while (curr)
	{
		if (i == 1)
		{
			pushFront(_data);
			return true;
		}
		else if ((i - 1) == index)
		{
			newNode->next = curr->next;
			curr->next = newNode;
			return true;
		}

		curr = curr->next;
		++index;
	}

	std::cout << "Out of range index was choosen!\n";
	return false;
}

template<typename T>
bool LList<T>::deleteAt(size_t i) {
	Node* curr = head;
	size_t index = 1;

	while (curr)
	{
		if (i == 1)
		{
			popFront();
			return true;
		}
		else if ((i - 1) == index)
		{
			Node* temp = curr->next->next;
			free(curr->next);
			curr->next = temp;
			return true;
		}

		curr = curr->next;
		++index;
	}

	std::cout << "Out of range index was choosen!\n";
	return false;
}

template<typename T>
void LList<T>::swap(size_t pos1, size_t pos2) {
	Node* prevFirst = nullptr;
	Node* currFirst = head;

	Node* prevSecond = nullptr;
	Node* currSecond = head;
	size_t ind = 0;

	while (currFirst) {
		if (ind == (pos1-1))
		{
			break;
		}
		++ind;
		prevFirst = currFirst;
		currFirst = currFirst->next;
	}

	
	while (currSecond) {
		if (ind == (pos2))
		{
			break;
		}
		++ind;
		prevSecond = currSecond;
		currSecond = currSecond->next;
	}

		
	if (prevFirst != nullptr) {
		prevFirst->next = currSecond;
	}
	else {
		head = currSecond;
	}

	if (prevSecond != nullptr)
		prevSecond->next = currFirst;
	else 
		head = currFirst;

	
	Node* temp = currSecond->next;
	currSecond->next = currFirst->next;
	currFirst->next = temp;
}




template<typename T>
const T& LList<T>::operator[] (size_t i) {
	Node* curr = head;
	size_t indexN = 0;

	while (curr)
	{
		if (indexN == (i - 1))
		{
			return curr->data;
		}
		curr = curr->next;
		++indexN;
	}

	std::cout << "Out of range index!\n";
}

template <typename T>
bool LList<T>::Iterator::operator == (const typename LList<T>::Iterator& other) const
{
	return current == other.current;
}

template <typename T>
bool LList<T>::Iterator::operator != (const typename LList<T>::Iterator& other) const
{
	return current != other.current;
}

template <typename T>
typename LList<T>::Iterator& LList<T>::Iterator::operator++()
{
	current = current->next;
	return *this;
}

template <typename T>
T LList<T>::Iterator::operator *()
{
	return current->data;
}

template <typename T>
typename LList<T>::Iterator LList<T>::begin()
{
	return LList<T>::Iterator(head);
}

template <typename T>
typename LList<T>::Iterator LList<T>::end()
{
	return LList<T>::Iterator(nullptr);
}