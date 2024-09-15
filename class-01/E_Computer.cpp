#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 用C++的STL做，不要手写stack了
// 此题为基本的中缀运算，通过创建两个栈即可实现

long calculate(long a, long b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }
    return -1; // 不会到这里，题目保证没有其他运算符
}

int main()
{
    int n;
    cin >> n;
    vector<long> nums(n);
    vector<char> ops(n - 1);
    // 读取n个数
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // 读取n - 1个运算符
    for (int i = 0; i < n - 1; i++)
    {
        cin >> ops[i];
    }

    // 定义两个栈：一个存数字，一个存操作符
    stack<long> numStack;
    stack<char> opStack;

    // 首先把第一个数字入栈
    numStack.push(nums[0]);

    // 遍历后续的数字和运算符
    for (int i = 0; i < n - 1; i++)
    {
        char op = ops[i];
        long currentNum = nums[i + 1];
        // 如果当前操作符是乘法，立即计算
        if (op == '*')
        {
            long topNum = numStack.top();
            numStack.pop();
            long result = calculate(topNum, currentNum, op);
            numStack.push(result);
        }
        else
        {
            // 如果是加法或减法，则把当前数字入栈，操作符入栈
            numStack.push(currentNum);
            opStack.push(op);
        }
    }

    // 剩下的就是加减法了，需要从左往右计算，所以需要把栈逆过来
    stack<long> numStack_v;
    stack<char> opStack_v;

    while (!opStack.empty())
    {
        opStack_v.push(opStack.top());
        opStack.pop();
    }
    while (!numStack.empty())
    {
        numStack_v.push(numStack.top());
        numStack.pop();
    }

    while (!opStack_v.empty())
    {
        long num1 = numStack_v.top(); numStack_v.pop();
        long num2 = numStack_v.top(); numStack_v.pop();
        char op = opStack_v.top();   opStack_v.pop();

        long result = calculate(num1, num2, op);
        numStack_v.push(result);
    }

    // 栈中最后剩下的就是最终结果
    cout << numStack_v.top() << endl;

    return 0;
}