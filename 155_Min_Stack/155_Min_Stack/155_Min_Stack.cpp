#include <iostream>

using namespace std;

class MinStack {
public:
	
	MinStack() : _capacity(1), _top(-1) {
		nums = (int*)malloc(_capacity * sizeof(int));
	}

	~MinStack()
	{
		free(nums);
	}

	void push(int x) {
		_top++;
		if (_top > _capacity)
		{
			_capacity *= 5;
			nums = (int*)realloc(nums, _capacity * sizeof(int));
		}
		nums[_top] = x;
		std::cout << "nums[_top] = " << nums[_top] << std::endl;
	}

	void pop() {
		nums[_top] = 0;
		_top--;
		std::cout << "nums[_top] = " << nums[_top] << std::endl;
	}

	int top() {
		return nums[_top];
	}

	int getMin() {
		int temp = nums[0];
		for (int i = 0; i < _top; ++i)
		{
			if (nums[i] < temp)
			{
				temp = nums[i];
			}
		}
		std::cout << "Min = " << temp << std::endl;
		return temp;
	}

private:
	int *nums;
	int _capacity;
	int _top;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/


/*
template <typename T>
class Stack {
private:
	T* _stack;
	int _capacity;
	int _top;
public:
	Stack() :_capacity(1), _top(-1) {
		_stack = (T*)malloc(_capacity * sizeof(T));
	}

	~Stack() {
		free(_stack);
	}

	void push(T x) {
		_top++;
		if (_top >= _capacity) {
			//if capacity is not enough, enlarge it 5 times.
			//Notes: why 5 times? because if you change to other(e.g. 2 times), 
			//       LeetCode system will report Run-time Error! it sucks!
			_capacity *= 5;
			_stack = (T*)realloc(_stack, _capacity * sizeof(T));
		}
		_stack[_top] = x;
	}

	T pop() {
		return top(true);
	}

	T& top(bool pop = false) {
		if (_top >= 0) {
			if (pop) {
				return _stack[_top--];
			}
			return _stack[_top];
		}
		static T null;
		return null;
	}

	bool empty() {
		return (_top<0);
	}
	int size() {
		return _top + 1;
	}
	void clear() {
		_top = -1;
	}
};
*/

/*
class MinStack {
public:
	
	MinStack() {}

	void push(int x) {
		s1.push(x);
		if (s2.empty() || x <= s2.top()) s2.push(x);
	}

	void pop() {
		if (s1.top() == s2.top()) s2.pop();
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}

private:
	stack<int> s1, s2;
};
*/

int main()
{
	MinStack obj;
	obj.push(-2);
	obj.push(0);
	obj.push(-3);
	int num = obj.getMin();
	obj.pop();
	int param_3 = obj.top();
	int num1 = obj.getMin();
	//int param_4 = obj.getMin();
	return 0;
}
