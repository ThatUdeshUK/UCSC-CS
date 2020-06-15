.text
	lw $t1,num1
	lw $t2,num2
	add $a0,$t1,$t2
	li $v0,1
	syscall 
	li $v0,10
	syscall 

.data
num1: .word 10
num2: .word 15