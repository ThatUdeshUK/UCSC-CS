.text
	lw $t1,num1
	lw $t2,num2
	add $t3,$t1,$t2
	sw $t3,result

.data
num1: .word 10
num2: .word 15
result: .space 4