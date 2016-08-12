for func_num in 1 2
do
    if [ $func_num -eq 1 ]
    then
        for x in 1 2
        do
            ./fdiff cent f$func_num $x
        done
    else
        for x in 1.1 2.2
        do
            ./fdiff cent f$func_num $x
        done
    fi 
done
