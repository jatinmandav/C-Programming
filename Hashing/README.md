# Hashing-Using-C
Hashing Using C Language

Hash Table is a data structure which stores data in an associative manner. In hash table, the data is stored in an array format where each data value has its own unique index value. Access of data becomes very fast, if we know the index of the desired data.

Collisions can occur when the hash function maps two different keys to the same location. The Two most popular methods are:
  - Open Addressing
    - [Linear Probing](Hashing/LinearProbing.c/)
      - Linear Probing is the simplest approach to resolve a collision.
        - Formula : h(k, i) = [h'(k) + i] mod m
          where, h'(k) = key mod m, m = size of Hash Table, mod = % Operator
    - [Quadratic Probing](Hashing/QuadraticProbing.c/)
    - [Double Hashing](Hashing/DoubleHashing.c/)
  - Chaining
