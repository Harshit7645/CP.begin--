import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math
import time

a = 6364136223846793005
b = 1
m = 2**64
x = 1


def linear_congruence_generator(a, b, m, x, n):
    seq = []
    for i in range(n):
        x = (a * x + b) % m
        u = x / m
        seq.append(u)
    return seq


def fibonacci_generator(u):
    while len(u) < 1000000:
        ui = u[-17] - u[-5]
        if ui < 0:
            ui += 1.0
        u.append(ui)


def uniform_number(seq):
    if len(seq) == 17:
        fibonacci_generator(seq)
        seq = seq[50:]
    temp = seq[-1]
    seq.pop()
    return temp


uniform_seq = linear_congruence_generator(a, b, m, x, 10000)
fibonacci_generator(uniform_seq)
uniform_seq = uniform_seq[50:]


def Box_Muller():
    U1 = uniform_number(uniform_seq)
    U2 = uniform_number(uniform_seq)

    R = np.sqrt(-2.0 * np.log(U1))
    theta = 2.0 * np.pi * U2

    Z1 = R * np.cos(theta)
    Z2 = R * np.sin(theta)
    return Z1, Z2


def Marsaglia():
    while True:
        U1 = uniform_number(uniform_seq)
        U2 = uniform_number(uniform_seq)
        U1 = 2.0 * U1 - 1
        U2 = 2.0 * U2 - 1
        if U1*2 + U2*2 <= 1.0:
            break

    temp = U1*2 + U2*2
    temp = np.sqrt(-2.0 * np.log(temp) / temp)
    Z1 = U1 * temp
    Z2 = U2 * temp
    return Z1, Z2


def convert_N01_toNmv(u, m, v):
    seq = []
    for ui in u:
        seq.append(m + (np.sqrt(v) * ui))
    return seq


def pdf_with_plot(u, m, v):
    sigma = np.sqrt(v)
    plt.hist(u, bins=60, density=True)
    plt.title(f"N = {len(u)}, mean = {m}, variance = {v}")
    x = np.linspace(-10 + m, 10 + m)
    y = 1.0 / (
        np.sqrt(2.0 * np.pi) * sigma * np.exp(((x - m) ** 2) / (2.0 * sigma**2))
    )
    plt.plot(x, y)
    plt.show()


def generate(number_of_samples, flag):
    ans = []
    times = []
    for _ in range(number_of_samples):
        start = time.time()
        if flag == 1:
            u1i, u2i = Marsaglia()
        elif flag == 0:
            u1i, u2i = Box_Muller()
        end = time.time()
        ans.append(u1i)
        times.append(end - start)
    mean_value = np.mean(ans)
    var_value = np.var(ans)
    print(
        f"{number_of_samples} numbers generated:\nMean: {mean_value}, Variance: {var_value}"
    )
    print(f"Time required to generate one number: {np.average(times)}")
    print(f"Time required to generate {number_of_samples} numbers: {np.sum(times)}")

    plt.hist(ans, bins=60)
    plt.title(f"N = {number_of_samples}")
    plt.xlabel("Values")
    plt.ylabel("Frequency")
    plt.show()

    ans_N05 = convert_N01_toNmv(ans, 0, 5)
    pdf_with_plot(ans_N05, 0, 5)

    ans_N55 = convert_N01_toNmv(ans, 5, 5)
    pdf_with_plot(ans_N55, 5, 5)


print("BOX MULLER:")
generate(100, 0)
print()
generate(10000, 0)

print()
print()

print("MARSAGLIA AND BRAY:")
generate(100, 1)
print()
generate(10000, 1)