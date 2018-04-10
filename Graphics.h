#pragma once
#include<list>
#include<exception>
#include<vector>
#include<memory>

namespace MyGraphics
{
	struct _Point3D
	{
		float x, y, z;
	};

	//class _PointsBasic
	//{
	//public:
	//	_PointsBasic(void) :element(nullptr), first_free(nullptr), cap(nullptr) {};
	//	_PointsBasic(const _PointsBasic&);
	//	_PointsBasic &operator=(const _PointsBasic&);
	//	~_PointsBasic(void);

	//	void push_back(const _Point3D &);
	//	size_t size(void) const { return first_free - element; }
	//	size_t capacity(void) const { return cap - element; }
	//	_Point3D * begin() const { return element; }
	//	_Point3D * end() const { return first_free; }

	//private:

	//	static std::allocator<_Point3D> alloc;
	//	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	//	std::pair<_Point3D *, _Point3D *> alloc_n_copy(const _Point3D *, const _Point3D *);
	//	void free();
	//	void reallocate();
	//	_Point3D *element, *first_free, *cap;
	//};

	class _PointBasic0
	{
	public:
		_PointBasic0(void);
		_PointBasic0(std::vector<_Point3D>::iterator & it1, std::vector<_Point3D>::iterator & it2);
		_PointBasic0(const float * points, size_t num);
		_PointBasic0(const _PointBasic0 & );
		void push_back(const _Point3D & point);
		void push_back(float x, float y, float z);
		void push_back(float * point);

		size_t pointsSize() const;
		size_t classSize() const;
		_PointBasic0 &operator+(const _PointBasic0 &rhs);
		_PointBasic0 &operator+=(const _PointBasic0 &rhs);
	private:
		std::vector<float> points;
		std::list<size_t> pointsIndex;
		size_t numPoints = 0;
		size_t numClass = 0;
	};
}