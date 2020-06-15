.text
	li $a0,5
	jal fact
	addu $s0,$zero,$v0
	li $v0,10
	syscall
	
fact:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	li $t0,1
	bgt $a0,$t1,fact_end
	li $v0,1
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra 
fact_end:
	addi $sp,$sp,-4
	sw $a0,0($sp)
	subi $a0,$a0,1
	jal fact
	lw $a0,0($sp)
	addi $sp,$sp,4
	mul $v0,$v0,$a0
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra 
	
.data
label: .asciiz "Your answer is "
