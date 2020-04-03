#include <iostream>

struct alignas(64) Vec3d {
	double x, y, z;
};//fit bit size
//new operator does not guarantee which size is returned
int main() {
	auto h = new Vec3d[1000];
	h[0] = Vec3d{ 1.1, 2.2,3.3 };
	std::cout << h[0].x << ' ' << h[0].y << ' ' << h[0].z << '\n';
	std::cout << sizeof(h[0]);
}