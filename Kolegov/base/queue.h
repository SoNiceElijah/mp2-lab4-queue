#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MaxQueueSize = 100;

using namespace std;

template <class T>
class TQueue
{
  T *pMem;
  int size;
  int top;
public:
  TQueue(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxQueueSize))
      throw size;
    pMem = new T[size];
  }
  ~TQueue()
  {
    delete [] pMem;
  }

  void Push(T elem)
  {
	  if (IsFull())
		  throw "Queue full";

	  top++;
	  for (int i = top; i > 0; i--)
		  pMem[i] = pMem[i - 1];

	  pMem[0] = elem;
  }
  T Shift()
  {
	  if (IsEmpty())
		  throw "Queue empty";

	  top--;
	  return pMem[top + 1];
  }

  T Check() 
  {
	  if (IsEmpty())
		  throw "Queue empty";

	  return pMem[0];
  }

  int IsEmpty(void) const { return top == -1; }
  int IsFull(void) const { return top == size - 1; }
  int Count() { return top + 1; };
};

#endif
