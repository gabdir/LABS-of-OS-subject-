if test ! -f numbers
then
    echo 0 > numbers
fi

if ln numbers numbers.lock
	then                          

	for i in `seq 1 70`;
	do
		
		LASTNUMBER=`tail -1 numbers`
		LASTNUMBER=$((LASTNUMBER+1))

		echo $LASTNUMBER >> numbers
	done

	rm numbers.lock
fi