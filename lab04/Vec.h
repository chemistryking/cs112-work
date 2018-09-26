/* Vec.h provides a simple vector class named Vec.
 * Student Name: Matthew Nykamp
 * Date: 9-27-16
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned);
	Vec(const Vec&);
	virtual ~Vec();
	Vec& operator=(const Vec&);
	unsigned getSize();
	void setItem(unsigned, const Item&);
	Item getItem(unsigned) const;
	void setSize(unsigned);
	bool operator==(const Vec&);
	void writeTo(ostream&) const;
	void readFrom(istream&);
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
