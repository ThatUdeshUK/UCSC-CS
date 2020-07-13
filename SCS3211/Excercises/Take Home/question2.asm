.text 
	la $a0,hint
	li $v0,4
	syscall 
	
	la $a0,binary
	li $a1,16
	li $v0,8
	syscall 
	
	# Count string length
count_loop:	
	addu $t1,$a0,$t0
	lb $t2,($t1)
	beq $t2,10,count_end
	addiu $t0,$t0,1
	j count_loop

count_end:
	addiu $t1,$a0,0
	subiu $t0,$t0,1
	li $t5,0
	
cal_loop:
	beq $t0,-1,cal_end
	addiu $a0,$t0,0
	jal pow
	lb $t3,($t1)
	subiu $t3,$t3,48
	mulo $t3,$t3,$v0
	addu $t5,$t5,$t3
	subiu $t0,$t0,1
	addiu $t1,$t1,1
	j cal_loop

cal_end:
	addiu $a0,$t5,0
	li $v0,1
	syscall 
	
	li $v0,10
	syscall 

	# Power of two proccedure
pow:
	addiu $sp,$sp,-4
	sw $ra,0($sp)
	addiu $s0,$a0,0
	beqz $s0,pow_arg_zero
	li $s1,2
	subiu $s0,$s0,1
	j pow_loop

pow_arg_zero:
	li $s1,1
	j pow_loop_end
	
pow_loop:
	beqz $s0,pow_loop_end
	mulou $s1,$s1,2
	subiu $s0,$s0,1
	j pow_loop

pow_loop_end:
	addiu $v0,$s1,0
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
	

.data
hint: .asciiz "Enter binary string:\n"
binary: .space 16
