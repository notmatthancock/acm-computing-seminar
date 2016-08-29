int main() {
bool a,b,c; // Declare the type of variables a, b, and c.
a = true;
b = false;

// !  is logical negation when applied to a single variable.
c = !a; // c is false.

// && is logical and.
c = (a && b); // c is false.

// || is logical or.
c = (a || b); // c is true.
return 0;
}
