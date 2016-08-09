Keep a directory that looks like:

    /FCM1
        /programming-assignments
            /assignment-template
            /1
                /data
                /figures
                /report
                /source
            /2
                /data
                /figures
                /report
                /source
            .
            .
            .
            etc

Begin each assignment by copying the entire `assignment-template` folder 
and renaming it according to the assignment number, e.g., name the 
folder `2` if it is the second assignment, etc.

For each assignment folder:

1. Keep all your source code in the subfolder, `source`, for each 
assignment (with appropriate subfolder organization if necessary).

2. Write and store all your data from your experiments to the `data` folder.

3. Store all your figures in the `figures` folder.

4. Store your report markup in the `report` folder. A template LaTex report 
is provided in the `report` folder of the `report-template` folder.

To compile the report to pdf, change your working directory to the `report` 
folder in the terminal and run `make`. Running `make clean` from the 
directory will remove a few extra files that are created during the 
compilation of the LaTex source to pdf.
