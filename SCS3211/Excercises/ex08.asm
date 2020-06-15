.text
	li $t0,0
start:
	beq $t0,10,exit
	la $a0,prompt
	li $v0,4
	syscall 
	li $v0,5
	syscall 
	mulu $t1,$t0,4
	la $t2,arr
	addu $t2,$t2,$t1
	sw $v0,($t2)
	addiu $t0,$t0,1
	j start
	
exit:
	li $v0,10
	syscall 
	
.data
prompt: .asciiz "Enter number: "
arr: .word 0:10