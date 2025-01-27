# Test Cases for Rod Cutting Problem

## Test Case 1
**Input:**
$ ./rodcut 10
Enter lengths and prices separated by a comma (e.g. 1, 2):
Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.
1, 2
2, 4
3, 7
4, 8
5, 11
7, 12
10, 23
^Z

1 @ 1 = 2

3 @ 3 = 21
Remainder: 0
Value: 23

## Test Case 2
**Input:**
$ ./rodcut 82
Enter lengths and prices separated by a comma (e.g. 1, 2):
Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.
2, 12
3, 4
7, 18
8, 21
12, 24
15, 32
^Z

41 @ 2 = 492
Remainder: 0
Value: 492

## Test Case 3
**Input:**
$ ./rodcut 10 12
Usage: C:\Users\ndang\CSUF\VS_Code\Spring_2025\351_Intro_to_OS\Projects\HW_01_Rods\rodcut.exe <supplied rod length>

## Test Case 4
**Input:**
$ ./rodcut 1
Enter lengths and prices separated by a comma (e.g. 1, 2):
Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.
1, 2
2, 4
5, 1000
^Z

1 @ 1 = 2
Remainder: 0
Value: 2

## Test Case 5
**Input:**
$ ./rodcut 100000
Enter lengths and prices separated by a comma (e.g. 1, 2):
Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.
2, 52
3, 82
9, 118
82, 41
34, 17
56, 256
1000, 0
1001, 512
^Z

2 @ 2 = 104

33332 @ 3 = 2733224
Segmentation fault

## Test Case 6
**Input:**
$ ./rodcut 100000
Enter lengths and prices separated by a comma (e.g. 1, 2):
Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.
1, 10
2, 23
4, 52
5, 100
6, 199
7, 180 
9, 150
10, 250
^Z

1 @ 4 = 52

16666 @ 6 = 3316534
Remainder: 0
Value: 3316586

## Test Case 7
**Input:**
$ ./rodcut 0002000
Enter lengths and prices separated by a comma (e.g. 1, 2):
Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.
2, 100
5, 52
12, 82
15, 383
16, 343
292, 10000
^Z

1000 @ 2 = 100000

32 @ 292 = 320000
Remainder: -9344
Value: 100000