# Approximating Euler's Number using Binary Search

This C++ program approximates Euler's number (e) using a binary search approach. It iteratively narrows down the range where the maximum value of the function f(x) = x^(base/x) occurs, which is known to be maximized at x = e when base = e.

## Table of Contents
- [Overview](#overview)
- [How It Works](#how-it-works)
- [Requirements](#requirements)
- [Code Structure](#code-structure)
- [Customization](#customization)
- [Mathematical Background](#mathematical-background)

## Overview

The program uses a binary search-like algorithm to find the value of x that maximizes the function f(x) = x^(base/x). When the base is equal to e (Euler's number), this function reaches its maximum value at x = e. By iteratively narrowing down the range where this maximum occurs, we can approximate the value of e to a high degree of accuracy.

## How It Works

1. The program starts with an initial range [2, base_number].
2. It divides this range into a specified number of points.
3. For each point, it calculates the value of the function f(x) = x^(base/x).
4. It finds the point where the function reaches its maximum value.
5. It narrows down the range around this maximum point.
6. Steps 2-5 are repeated for a specified number of iterations.
7. The final lower bound of the range is taken as the approximation of e.

## Requirements

- C++ compiler with C++11 support
- Standard C++ libraries: iostream, math.h, vector, iomanip, limits

## Code Structure

- `calculate_magic`: Calculates the value of x^(base/x) for given x and base.
- `create_divided_array`: Creates an array of evenly spaced points in a given range.
- `calculate_magic_vector`: Calculates the function value for each point in the divided array.
- `find_bounds`: Finds the new bounds around the maximum point.
- `main`: Controls the main loop of the approximation process.

## Customization

You can modify the following parameters in the `main` function to customize the approximation:

- `base_number`: The base of the exponential function (default: 10)
- `div_count`: The number of points to divide the range into at each iteration (default: 100)
- `lim_neg`: The initial lower bound (default: 2)
- `lim_pos`: The initial upper bound (default: base_number)
- `approx_count`: The number of iterations to perform (default: 1000)

## Mathematical Background

The function f(x) = x^(base/x) has some interesting properties:
1. When base = e, the function reaches its maximum value at x = e.
2. For any base > 1, the function has a unique maximum.

By finding the x that maximizes this function when base = e, we can approximate the value of e itself. This program uses a numerical approach to find this maximum, effectively approximating e in the process.
