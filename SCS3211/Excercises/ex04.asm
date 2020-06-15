.text
	la $a0,inst
	li $v0,4
	syscall 
	li $v0,5
	syscall 
	move $t0,$v0
	la $a0,out
	li $v0,4
	syscall
	move $a0,$t0
	li $v0,1
	syscall

.data
inst: .asciiz "enter an integer:"
out: .asciiz "you have entered: "