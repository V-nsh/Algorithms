echo "Enter number 1: "
read a
echo "Enter number 2: "
read b

echo -e "1. Addition\\n2: Subtraction\\n3:Multiplication\\n4.Division"
echo "Enter your choice:"
read ch

if [ $ch -eq 1 ]
	then echo "Sum is : $(($a+$b))"
elif [ $ch -eq 2 ]
	then echo "Difference is: $(($a-$b))"
elif [ $ch -eq 3 ]
	then echo "Product is : $(($a*$b))"
elif [ $ch -eq 4 ]
	then echo "Quotient is : $(($a/$b))"
else 
	echo "Invalid choice"
fi

