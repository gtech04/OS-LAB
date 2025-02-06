settings ()
{
	echo "Choose integer of which to print table:"
	read $1
	echo "Choose n value until which to print the table:"
	read $2
	echo ' '
}

table ()
{
	for ((i=1; i<=$2; i++))
	do
		echo "$1 x $i =" `expr $1 \* $i`
	done

}

continuance ()
{
	echo ' '
	echo "Continue with another table?" 
	echo "1: Continue" 
	echo "0: End" 
	read $1
	clear
}

CONT=1;
while [ $CONT == 1 ]
do
	settings NB OP
	table $NB $OP
	continuance CONT
done

clear