.data

.text
	li $t0,4
	li $t1,2
	mult $t0,$t1
	mflo $t2
	addi $t3,$t2,5