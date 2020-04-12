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
For each element in the array check for its duplicate..if the duplicate found..then break the array else if not found any duplicate then we have the unique element..Just simply return it.
<br>Algo : <br> 1. for (i=0 to n-1)<br>
2. for(j = 0 to n-1) <br>
3.if(i!=j) {check if arr[i] == arr[j]
               if true -> break; 
               else->return arr[i];}
 ##### Time Complexity : O(n^2)

 ### Better approach : 
Sort the array first.. Now check the adjacent element if the element is not same..that means the elemnt is unique..(Note: in the loop the the increment/updation statement must be i+=2)<br>Algo : <br> 1. Sort the elements.
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
Algo : <br> 1.declare a variable Uninque, it will hold the result of the XOR operartions.
2. for(i = 0 to n-1) <br>
3.Unnique ^= arr[i];
4. Return Unique.

 ##### Time Complexity : O(n)

