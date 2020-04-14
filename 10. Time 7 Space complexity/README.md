## Time and Space Complexities
 Basically this folder consist less of coding and more of some interesting concepts. 

# 1.Find Unique element
```
## Sample input : 
7
2 3 1 6 3 6 2
## Sample Output :
1
```
### Naive approach : 
For each element in the array check for its duplicate..if the duplicate found..then continue the else if not found any duplicate then we have the unique element..Just simply return it.
<br>Algo : <br> 1. for (i=0 to n-1)<br>
2. for(j = 0 to n-1) <br>
3.if(i!=j) {check if arr[i] == arr[j]
               if true -> break; 
               else->return arr[i];}
 ##### Time Complexity : O(n^2)

 ### Better approach : 
Sort the array first.. Now check the adjacent element if the element is not same..that means the elemnt is unique..(Note: in the loop the the increment/updation statement must be i+=2)<br>Algo : <br> 1. Sort the elements.<br>
2. for(i = 0 to n-1) <br>
3.if(arr[i]!=arr[i+1]) -> {return arr[i];} else ->i+=2;

 ##### Time Complexity : O(nlogn+n)

 ### Best approach : Using XOR operation<br>
```
0^0 = 0
1^1 = 0
0^1 = 1
```
So, As we see the XOR retuens 0 when the Numbers are same...SO using this approach...apply XOR to each element of the array.. and the duplicates would turned to 0 and return the element which is remaining.
<br>
Algo : <br> 1.declare a variable Uninque, it will hold the result of the XOR operartions.<br>
2. for(i = 0 to n-1) <br>
3.Unnique ^= arr[i];<br>
4. Return Unique.

 ##### Time Complexity : O(n)

# 2.Find Duplicate element 
Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.
Assume, duplicate number is always present in the array.
```
## Sample input : 
9
0 7 2 5 4 7 1 3 6
## Sample Output :
7
```
### Naive approach : 
For each element in the array check for its duplicate..if the duplicate found..then break the loop ..Just simply return the element.
<br>Algo : <br> 1. for (i=0 to n-1)<br>
2. for(j = 0 to n-1) <br>
3.if(i!=j) {check if arr[i] == arr[j]
               if true -> return arr[i];}
 ##### Time Complexity : O(n^2)

 ### Better approach : 
Sort the array first.. Now check the adjacent element if the element is  same..then return the element.(Note: in the loop the the increment/updation statement must be i+=2)<br>Algo : <br> 1. Sort the elements.<br>
2. for(i = 0 to n-1) <br>
3.if(arr[i]!=arr[i+1]) -> {return arr[i];} else ->i+=2;

 ##### Time Complexity : O(nlogn+n)

 ### Best approach :Sum of n no.<br>
```
So, As we know sum of n numbers is : (n*(n-1))/2
```
So, In the given question the the elements in the array are in range 0 to n-2...Therefore the sum would be - ((n-1)*(n-2))/2,and subtract it from sum of all elements in that array..The difference remarks the extra elemnt which is the duplicate 1<br>
Algo : <br> 1.declare a variable ideal = ((n-1)*(n-2))/2, where n is the size of the array and one more variable sum.<br>
2. for(i = 0 to n-1) <br>
3.Sum+= arr[i];<br>
4. Return sum-ideal.

 ##### Time Complexity : O(n)

