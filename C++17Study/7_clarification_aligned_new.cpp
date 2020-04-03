#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cassert>

void* operator new(std::size_t size, std::align_val_t align) {
#if defined(_WIN32) || defined(__CYGWIN__)
	auto ptr = _aligned_malloc(size, static_cast<std::size_t>(align));
#else
	auto ptr = std::aligned_alloc(static_cast<std::size_t>(align), size);
#endif
	if (!ptr) throw std::bad_alloc{};
	std::cout << "new: " << size << ", align: "
		<< static_cast<std::size_t>(align) << ", ptr: " << ptr << '\n';
	return ptr;
}
void operator delete(void* ptr, std::size_t size, std::align_val_t algn) noexcept {
	std::cout << "delete: " << size << ", align: "
		<< static_cast<std::size_t>(algn) << ", ptr : " << ptr << '\n';
#if defined(_WIN32) || defined(__CYGWIN__)
	_aligned_free(ptr);
#else
	std::free(ptr);
#endif
}
void operator delete(void* ptr, std::align_val_t algn) noexcept {  } // hidden

struct alignas(32) Vec3d { // alignas is available since C++11
	double x, y, z;
};

int main() {
	std::vector<Vec3d> vec;
	for(int i = 0 ; i < 10; ++i)
		vec.push_back({});
	assert(reinterpret_cast<uintptr_t>(vec.data()) % alignof(Vec3d) == 0);
}