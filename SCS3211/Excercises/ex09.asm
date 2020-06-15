.text
	jal f1
	jal f1
	li $v0 10
	syscall
	
f1:
	la $a0 hello
	li $v0 4
	syscall 
	jr $ra 
.data
hello: .asciiz "Hello World"