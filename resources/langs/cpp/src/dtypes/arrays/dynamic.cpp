int main() {
// This allocates memory for 5 double types.
double * a = new double[5];

// Afterwards, you can treat `a` like a normal array.
a[0] = 1.0;
// etc...

// Whenever you use the `new` keyword, you must
// delete the memory allocated when you're done by hand.
delete [] a;

// We can change the size of `a`.
a = new double [10];

a[0] = 2.0;
// etc...

delete [] a;
return 0;
}
