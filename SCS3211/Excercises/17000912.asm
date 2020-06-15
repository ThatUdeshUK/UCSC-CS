.text
	li $v0,5
	syscall
	move $t0,$v0
	sw $t0,X
	li $v0,5
	syscall 
	move $t1,$v0
	sw $t1,Y
	add $a0,$t0,$t1
	li $v0,1
	syscall 
	li $v0,10
	syscall 

.data
X: .space 4
Y: .space 4