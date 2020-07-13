.text 
	la $a0,hint
	li $v0,4
	syscall 
	
	li $v0,5
	syscall 
	
	addi $t0,$v0,0
	
	# Check divisability by 400
	li $t1,400
	div $t0,$t1
	mfhi $t2
	beqz $t2,leap
	
	# Check divisability by 100
	li $t1,100
	div $t0,$t1
	mfhi $t2
	beqz $t2,not_leap
	
	# Check divisability by 100
	li $t1,4
	div $t0,$t1
	mfhi $t2
	beqz $t2,leap
	
	# Else
	j not_leap

leap:
	la $a0,leap_year
	li $v0,4
	syscall 
	j end

not_leap:
	la $a0,not_leap_year
	li $v0,4
	syscall 
	j end

end:	
	li $v0,10
	syscall 
	

.data
hint: .asciiz "Enter year:\n"
leap_year: .asciiz "Leap year\n"
not_leap_year: .asciiz "Not leap year\n"