# Median Finder with AVL Tree

This C++ program implements a median finder using an AVL tree data structure. It allows you to efficiently find the median of a sequence of integers as they are inserted one by one.

## Overview

This program reads integers from the standard input and inserts them into an AVL tree. As each integer is inserted, it calculates and maintains the median of the integers seen so far. The median calculation is based on the AVL tree's ability to efficiently find the element at a specified rank (position) in logarithmic time.

## Features

- Efficient insertion of integers into an AVL tree.
- Real-time median calculation as integers are inserted.
- Support for both odd and even-length sequences of integers.

# k-Closest Points using Heap

This C++ program finds the k closest points to the origin (0,0) from a given set of points using a min-heap data structure. It allows you to efficiently determine the closest points based on their Euclidean distances from the origin.

## Overview

The program reads the number of points (n) and the value of k from the standard input. It then reads n points (x, y) and uses a min-heap to keep track of the k closest points. The distance of each point from the origin is calculated as (x^2 + y^2).

## Features

- Efficiently find the k closest points from a set of n points.
- Utilizes a min-heap to maintain the closest points.
- Works with points in 2D space.
