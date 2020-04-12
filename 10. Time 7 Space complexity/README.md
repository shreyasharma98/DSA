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
<br>
Naive approach : For each element in the array check for its duplicate..if the duplicate found..then break the array else if not found any duplicate then we have the unique element..Just simply return it.
<br>Algo : for (i=0 to n-1)  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  for(j = 0 to n-1)<br>if(i!=j)<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; check if arr[i] == arr[j] if true -> break; else->return arr[i]