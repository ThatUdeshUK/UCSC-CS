.text 
	la $a0,hint
	li $v0,4
	syscall 
	
	li $v0,5
	syscall 
	addiu $t0,$v0,0
	
	li $v0,5
	syscall 
	
	add $t2,$t0,$v0
	sub $t3,$t0,$v0
	
	# Print summ
	la $a0,sum_prefix
	li $v0,4
	syscall
	
	addiu $a0,$t2,0
	li $v0,1
	syscall 
	
	# Print the difference
	la $a0,diff_prefix
	li $v0,4
	syscall
	
	addiu $a0,$t3,0
	li $v0,1
	syscall 

	
.data
hint: .asciiz "Enter two numbers:\n"
sum_prefix: .asciiz "Sum is = "
diff_prefix: .asciiz "\nDifference is = "