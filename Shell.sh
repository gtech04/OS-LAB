//Even or Odd

echo "enter the number"
read num
if [ `expr $num % 2` -eq 0 ]
then
echo "number is even"
else
echo "number is odd"
fi

//BIGGEST OF TWO NUMBERS


echo "enter the number" read a b
if [ $a -gt $b ] then
echo "$a is big" else
echo "$b is big" fi
OUTPUT:Enter The Two Number:
23 67
67 is big.


//BIGGEST OF THREE NUMBERS


echo "enter three numbers"
read a b c
if [ $a -gt $b ] && [ $a -gt $c ]
then
echo "$a is big"
else if [ $b -gt $c ]
then
echo "$b is big"
else
echo "$c is big"
fi
fi


//FACTORIAL OF NUMBER

echo "enter the number"read n
fact=1
i=1
while [ $i -le $n ]
do
fact=`expr $i \* $fact`
i=`expr $i + 1`
done
echo "The fcatorial number of $n is $fact”


//FIBONACCI SERIES

echo " Enter the limit for fibonnaci series: " read lim
n1=0
n2=1
var=0
echo " The Fibonacci series is: " echo "$n1"
echo "$n2"
while [ $var -lt `expr $lim - 2` ] don3=`expr $n1 + $n2 `
n1=`expr $n2 `
n2=`expr $n3 `
var=`expr $var + 1 `
echo "$n3"
done


//MULTIPLICATION TABLE

echo “enter the number” read n
for i in 1 2 3 4 5 6 7 8 9 10 do
x= `expr $n \* $i` echo “$n * $i = $x”done


//SIMPLE CALCULATOR

echo ‘enter the value for a’
read a
echo ‘enter the value for b’
read b
echo ‘enter operator’
read op
case $op in
+) c=`expr $a + $b`;; -) c = `expr $a -$b`;;\*) c = `expr $a \* $b`;; /) c = `expr $a / $b ;; esac
echo $c
