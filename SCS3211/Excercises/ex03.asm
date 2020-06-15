.text
	li $v0,6
	syscall
	mov.s $f1,$f0
	li $v0,6
	syscall 
	add.s $f12,$f0,$f1
	li $v0,2
	syscall 
	li $v0,10
	syscall 
