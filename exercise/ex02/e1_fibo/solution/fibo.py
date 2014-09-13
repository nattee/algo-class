#!/usr/bin/env python

def fibo(n):
        if n < 2 return n
        a,b =  0,1
        while n > 1:
                a, b = b, a + b
                n = n - 1

        return b

a = input()
print fibo(a)
