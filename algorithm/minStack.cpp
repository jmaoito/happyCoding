/**************
  LeetCode MinStack

  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

  push(x) -- Push element x onto stack.
  pop() -- Removes the element on top of the stack.
  top() -- Get the top element.
  getMin() -- Retrieve the minimum element in the stack.

***************/

class MinStack {
    deque<int> stackArray;
    int m_min;
    int m_minIndex;     // previous min element index
public:
    void push(int x) {
        if (stackArray.size() == 0) {
            m_min = x;
            m_minIndex = 0;
        }
        else {
            if (x < m_min) {
                stackArray.push_back(m_minIndex);
                m_min = x;
                m_minIndex = stackArray.size();
            }
        }
        stackArray.push_back(x);
    }

    void pop() {
        if(stackArray.size()==0) return;

        int t = stackArray.back();

        if(m_min==t && m_minIndex==stackArray.size()-1 && m_minIndex != 0)  
        // m_minIndex == 0 is the initial condition, and not push into the array. should not come into the block
        {
            stackArray.pop_back();
            m_minIndex = stackArray.back();
            //if(m_minIndex<stackArray.size())
                m_min = stackArray[m_minIndex];
        }

        stackArray.pop_back();
    }

    int top() {
        return stackArray.back();
        
    }

    int getMin() {
        return m_min;
    }
};
