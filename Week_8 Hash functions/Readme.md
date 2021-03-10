# Week 8 Hash functions

### Modified associative array

Implement modified associative array that supports the following operations: 

- get the value by key
- delete the value by key
- output the value corresponding to the key that was added to the array after all keys, but before the key x  
- output the value corresponding to the key that was added to the array before all keys, but after the key x  
- change the value by key

Keys and values are strings the length of which does not exceed 20 characters. Number of operations N&le;5&sdot;10<sup>5</sup>.

*Time limit*: 3 seconds

*Memory limit:* 256 MB

*File:* `mod_array.cpp`

### Fast hash table

Implement hash table that is capable to store integers from interval [0; 10<sup>15</sup> - 1]. Hash table must support "add" operation and check if the element is in the table. Number of operations N&le;10<sup>7</sup>.

*Time limit*: 5 seconds

*Memory limit:* 256 MB

*File:* `hash_table.cpp`

### String hash killer

Polynomial hash functions can be implemented in the following way:

```
      int multiple = ???;
      public int hashOf(String s) {
          int rv = 0;
          for (int i = 0; i < s.length(); ++i) {
              rv = multiple * rv + s.charAt(i);
          }
          return rv;
      }
```

Generate N (1&le;N&le;10<sup>4</sup>) different strings such that for any multiple m (2&le;m&le;1023) all these strings have the same hash value. String length should be less than 2500 characters. 

*Time limit*: 2 seconds

*Memory limit:* 256 MB

*File:* `anti_hash.cpp`
