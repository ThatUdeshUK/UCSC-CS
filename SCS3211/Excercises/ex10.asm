.text
	li $a0,5
	li $a1,7
	jal f1
	addu $s0,$zero,$v0
	la $a0,label
	li $v0,4
	syscall 
	addu $a0,$zero,$s0
	li $v0,1
	syscall 
	li $v0,10
	syscall
	
f1:
	addu $t0,$a0,$a1
	addu $v0,$zero,$t0
	jr $ra 
	
.data
label: .asciiz "Your answer is "