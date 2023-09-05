#
# some calculations for the course notes in FCM
# ---------------------------------------------
#
# imports
import numpy as np
import matplotlib.pyplot as plt
#
# function definition
# -------------------
#
def f(x):
    val = x * np.exp(-x*x)
    return val
def df(x):
    val = np.exp(-x*x) * ( 1.0 - 2.0 * x * x )
    return val
def dfapprox(x,h):
    val = ( f(x+h) - f(x) ) / h
    return val
def diff(fexct, approx):
    val = np.abs(fexct-approx)
    return val

a = 1.0
h = 0.01
print(a, h, a+h, f(a), f(a+h), dfapprox(a, h), df(a), diff(df(a), dfapprox(a,h)))
    

a = np.sqrt(2)
h = 0.01
print(a, h, a+h, f(a), f(a+h), dfapprox(a, h), df(a), diff(df(a), dfapprox(a,h)))
