.text
	la $t0,num1
	lw $a0,($t0)
	li $v0,1
	syscall 
	lw $a0,4($t0)
	li $v0,1
	syscall 
	li $v0,10
	syscall 

.data
num1: .word 10,15