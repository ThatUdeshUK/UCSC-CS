.text
	# Calling the fib function
	li $a0,7
	jal fib
	addu $s0,$zero,$v0
	
	# Print results of fib fuction
	addi $a0,$s0,0
	li $v0,1
	syscall 
	
	li $v0,10
	syscall
	
fib:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	# if 'n' > 1
	bgt $a0,1,fib_recur
	# if 'n' == 1
	beq $a0, 1, arg_one
	# if 'n' == 0
	li $v0,0
	j fib_return
	
arg_one:
	li $v0,1
	
fib_return:
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra 
	
fib_recur:
	# Push 'n' argument in stack
	addi $sp,$sp,-4
	sw $a0,0($sp)
	# First recursive call
	subi $a0,$a0,1
	jal fib
	addi $t0,$v0,0
	# Peek 'n'argmuent from stack
	lw $a0,0($sp)
	# Push results of first recursive call in stack
	addi $sp,$sp,-4
	sw $t0,0($sp)
	# Second recursive call
	subi $a0,$a0,2
	jal fib
	addi $t1,$v0,0
	# Pop results of first recursive call from stack
	lw $t0,0($sp)
	addi $sp,$sp,4
	# Add results of two recursive calls
	add $v0,$t0,$t1
	# Pop 'n'argmuent from stack
	lw $a0,0($sp)
	addi $sp,$sp,4
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra 
	
.data
label: .asciiz "Your answer is "
