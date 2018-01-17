#pragma once

class MyVector
{
public:
	MyVector();
	MyVector(float x, float y, float z);
	float* getPosition();
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	MyVector operator + (MyVector);

private:
	float x, y, z;
};

MyVector::MyVector()
{
	x = y = z = 0;
}

MyVector::MyVector(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
}

float* MyVector::getPosition() {
	float res[] = { x,y,z };
	return res;
}

MyVector MyVector::operator + (MyVector v0)
{
	MyVector res(x + v0.getX(), y + v0.getY(), z + v0.getZ());
	return res;
}
