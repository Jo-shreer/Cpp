/*
Protected Inheritance
class Derived : protected Base {};
public becomes protected
protected → remains protected
private → not inherited

👉 This is "implemented-in-terms-of" → Base is used, but not exposed publicly.

Private Inheritance
class Derived : private Base {};
public → becomes private
protected → becomes private
private → not inherited

👉 This is "implemented-in-terms-of" → only for internal use,
no part of Base visible to users of Derived.

*/
