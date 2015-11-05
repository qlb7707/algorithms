# divid-product
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
##描述
Given two positive integers N and M, please divide N into several integers A1, A2, ..., Ak (k >= 1), so that:

1. 0 < A1 < A2 < ... < Ak;

2. A1 + A2 + ... + Ak = N;

3. A1, A2, ..., Ak are different with each other;

4. The product of them P = A1 * A2 * ... * Ak is a multiple of M;

How many different ways can you achieve this goal?

##输入
Two integers N and M. 1 <= N <= 100, 1 <= M <= 50.

##输出
Output one integer -- the number of different ways to achieve this goal, module 1,000,000,007.

##样例提示
There are 4 different ways to achieve this goal for the sample:

A1=1, A2=2, A3=4;

A1=1, A2=6;

A1=2, A2=5;

A1=3, A2=4.

##样例输入
```
7 2
```
##样例输出
```
4
```
