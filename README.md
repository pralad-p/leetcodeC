# LeetCode - C Edition

1. Two Sum
    - [x] Double loop approach
    - [x] Reducing search space by sorting list
    - [x] O(n) complexity by using hashmaps

2. Palindrome Number
    - [x] Standard procedure

3. Roman To Integer
    - [x] Standard procedure

4. Longest Common Prefix

5. Valid Brackets

6. Merge Two Sorted Lists
    - You need to start off with a tail pointer that points to an actual data structure first.
    - After that, based on your condition, you append to this tail pointer.
    - When there is some left-over from either list, you add that specific non-empty list to the tail pointer.
    - Since this dummy data structure has nothing, the next pointer of this dummy data structure has the solution.

7. Merge Sorted Array

8. Squares of a Sorted Array
    - [x] O(n) solution using two-pointer approach.
        - There is a trick here of populating the result from the back. This has to do when it comes to dealing with
          absolute numbers. If we populate from the front of the result array, all negative numbers will be sorted and
          then positive numbers appear towards the end of the array.

9. Reverse String

10. Find the Difference