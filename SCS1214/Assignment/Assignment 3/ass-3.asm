0 movv sp 80
1 movv a 100
2 movv b 400
3 push a
4 call 20
5 pop a
6 out d
7 push b
8 call 20
9 pop b
10 out d
11 halt




20 push a
21 push b
22 push c
23 push acc
24 mov c sp
25 movv a 5
26 sub c a
27 loadr b acc
28 movv a 1000
29 add a b
30 mov d acc
31 pop acc
32 pop c
33 pop b
34 pop a
35 ret




