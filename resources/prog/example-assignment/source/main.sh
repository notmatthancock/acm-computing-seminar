for diff_type in forw back cent
do
    for func_num in 1 2
    do
        if [ $func_num -eq 1 ]
        then
            for x in 1 2
            do
                ./fdiff $diff_type f$func_num $x
            done
        else
            for x in 1.1 2.2
            do
                ./fdiff $diff_type f$func_num $x
            done
        fi 
    done
done
