0 movv sp 80
1 movv a 100
2 movv b 400
3 call 20
4 add a b
5 out acc
6 halt


20 push a
21 push b
22 push acc
23 movv a 20
24 movv b 80
25 add a b
26 out acc
27 pop acc
28 pop b
29 pop a
30 ret


