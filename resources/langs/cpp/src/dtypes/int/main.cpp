int main() {
int a = 6; // initialize a to 6.
unsigned int b = 7; // initialize b to 7.
int c; // declare c to be an integer variable.

a = 6;
b = 7;

c = a / b; // c is 0
c = b / a; // c is 1
c = b % a; // c is 1 (% is the integer remainder or modulo operator)
c = a - b; // c is -1
c = a > b; // c is 0 (boolean gets cast to integer)
c = a < b; // c is 1 (boolean gets cast to integer)
c++;       // c is 2 (++ is shorthand for c = c + 1)

b = a - b; // b is 4294967295 (-1 gets cast to unsigned)
b = b + 1; // b is 0 (b was previously the largest unsigned,
           // so adding one circles it back to zero.)
b += 7;    // b is 7 (+= is shorthand for b = b + 7;
return 0;
}
