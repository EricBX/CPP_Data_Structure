//基于二叉堆的优先级队列的实现//数组存储
//最小化堆
#ifndef priorityQueue_h
#define priorityQueue_h

#include <functional>

template <class Type, class cmp = less<Type>>
class priorityQueue
{
public:
	priorityQueue(int capacity = 100) {
		array = new Type[capacity];
		maxSize = capacity;
		currentSize = 0;
	}
	priorityQueue(const Type data[], int size);
	~priorityQueue() { delete[]array; }
	bool isEmpty()const { return currentSize == 0; }
	void enQueue(const Type &x);
	Type deQueue();
	Type getHead()const { return array[1]; }

private:
	int currentSize;
	Type *array;
	int maxSize;
	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);
};

template <class Type, class cmp = less<Type>>
priorityQueue<Type,cmp>::priorityQueue(const Type data[], int size)
	:maxSize(size + 10), currentSize(size)
{
	array = new Type[maxSize];
	for (int i = 0; i < size; i++) array[i + 1] = data[i];
	buildHeap();
}

template <class Type, class cmp = less<Type>>
void priorityQueue<Type,cmp>::enQueue(const Type &x)
{
	if (currentSize == (maxSize - 1))doubleSpace();
	//向上过滤
	currentSize++;
	int hole = currentSize; for (; hole > 1 && cmp()(x, array[hole / 2]); hole /= 2) array[hole] = array[hole / 2];
	array[hole] = x;
}

template <class Type, class cmp = less<Type>>
Type priorityQueue<Type,cmp>::deQueue()
{
	Type minItem;//min
	minItem = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return minItem;
}

template <class Type, class cmp = less<Type>>
void priorityQueue<Type,cmp>::doubleSpace()
{
	Type *tmp = array;
	maxSize *= 2;
	array = new Type[maxSize];
	for (int i = 0; i < currentSize; i++) array[i] = tmp[i];
	delete[]tmp;
}

template <class Type, class cmp = less<Type>>
void priorityQueue<Type,cmp>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; i--) percolateDown(i);
}

template <class Type, class cmp = less<Type>>
void priorityQueue<Type,cmp>::percolateDown(int hole)
{
	int child;
	Type tmp = array[hole];
	for (; hole * 2 <= currentSize; hole = child) {
		child = hole * 2;
		if (child != currentSize&&cmp()(array[child + 1], array[child])) child++;//less-min
		if (cmp()(array[child], tmp)) array[hole] = array[child];//less-min
		else break;
	}
	array[hole] = tmp;
}

#endif // !priorityQueue_h
