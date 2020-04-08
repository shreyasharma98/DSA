## RECURSION

# 1.length of string
Given a string compute its length recursively.
<br>
 ### Sample Input :<br>
```
abcd 
```
### Sample Output :<br>
``` 
4
```
# 2.Check Pallindrome
Check if the given String is Pallindrome.
<br>
 ### Sample Input :<br>
```
abcdcba
```
### Sample Output :<br>
``` 
true
```
# 3.change PI

Given a String change all 'pi' to 3.14
### Sample Input :<br>

```
xpipx
```
### Sample Output :<br>
``` 
x3.14px
```
# 4.Remove All X

Given a String remove all x.
### Sample Input :<br>

```
axbxcx
```
### Sample Output :<br>
``` 
abc
```

# 5.Remove duplicates

Given a string remove all duplicates.
### Sample Input :<br>

```
abbcca
```
### Sample Output :<br>
``` 
abca
```

# 6.Replace characters

In a given strings replace all given characters by another given charcters.
Do this recursively.
### Sample Input :<br>

```
abacd
a x
```
### Sample Output :<br>
``` 
xbxcd
```
# 7.Star Pair  
Given a string place star b/w if the consecutive characters are same.
Do this recursively.
### Sample Input :<br>

```
avvxxn
```
### Sample Output :<br>
``` 
av*vx*xn
```
# 8.Tower of Hanoi

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :
<br>1) Only one disk can be moved at a time.
<br>2) A disk can be moved only if it is on the top of a rod.
<br>3) No disk can be placed on the top of a smaller disk.
Print the steps required to move n disks from source rod to destination rod.
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
### Sample Input :<br>

```
2
```
### Sample Output :<br>
``` 
a b
a c
b c
```
# 9.String to integer
Given a string return it as integer.
Do this recursively.
### Sample Input :<br>

```
1024
```
### Sample Output :<br>
``` 
1024
```

# 10. Key-pad codes
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Do this recursively.
### Sample Input :<br>

```
23
```
### Sample Output :<br>
``` 
ad
ae
af
bd
be
bf
cd
ce
cf
```
# 10. Quick Sort

### Sample Input :<br>

```
8
80 30 60 10 40 20 70 50
```
### Sample Output :<br>
``` 
10 20 30 40 50 60 70 80
```
# 11. Merge Sort

### Sample Input :<br>

```
8
80 30 60 10 40 20 70 50
```
### Sample Output :<br>
``` 
10 20 30 40 50 60 70 80
```
# 12. Subsequences
Given a string s, print all possible subsequences that can be formed using the characters of the given string.
Do this recursively.
### Sample Input :<br>

```
abc
```
### Sample Output :<br>
``` 

c
b
bc
a
ac
ab
abc
```
# 13. Staircase 
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Do this recursively.
### Sample Input :<br>

```
4
```
### Sample Output :<br>
``` 
7
```
# 14. Check AB
Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
<br>a. The string begins with an 'a'
<br>b. Each 'a' is followed by nothing or an 'a' or "bb"
<br>c. Each "bb" is followed by nothing or an 'a'
### Sample Input :<br>

```
abb
```
### Sample Output :<br>
``` 
true
```
# 15.Binary Search (Recursive)

Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)
### Sample Input :<br>

```
6
2 3 4 5 6 8 
5 
```
### Sample Output :<br>
``` 
3
```

# 16. Return subset of an array

Given an integer array (of length n), find and return all the subsets of input array.
### Sample Input :<br>

```
3
15 20 12
```
### Sample Output :<br>
``` 
 
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
```
# 17.Print Subsets of Array

Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines. 
### Sample Input :<br>

```
3
15 20 12
```
### Sample Output :<br>
``` 
 
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
```
# 18.  Return Sum up to k
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
### Sample Input :<br>

```
9 
5 12 3 17 1 18 15 3 17 
6
```
### Sample Output :<br>
``
3 3
5 1
```
# 19.Print Sum up to k
Given an array A of size n and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
### Sample Input :<br>

```
9 
5 12 3 17 1 18 15 3 17 
6
```
### Sample Output :<br>
``
3 3
5 1
```
# 20.Return all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to Return the list of all possible codes that can be generated from the given string.
### Sample Input :<br>

```
1123
```
### Sample Output :<br>
``
aabc
kbc
alc
aaw
kw
```
# 21.Print all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to Print the list of all possible codes that can be generated from the given string.
### Sample Input :<br>

```
1123
```
### Sample Output :<br>
``
aabc
kbc
alc
aaw
kw
```
# 22.Print Permutations - String

Given a string, find and print all the possible permutations of the input string.
```
abc
```
### Sample Output :<br>
``
abc
acb
bac
bca
cab
cba
```
# 23. Return Permutations - String

Given a string, find and return all the possible permutations of the input string.
```
abc
```
### Sample Output :<br>
``
abc
acb
bac
bca
cab
cba
```