#include"Graphics.h"

namespace MyGraphics
{
	//_PointsBasic::_PointsBasic(const _PointsBasic & s)
	//{
	//	auto newdata = alloc_n_copy(s.begin(), s.end());
	//	element = newdata.first;
	//	first_free = cap = newdata.second;
	//}

	//_PointsBasic & _PointsBasic::operator=(const _PointsBasic & rhs)
	//{
	//	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	//	free();
	//	element = data.first;
	//	first_free = cap = data.second;
	//	return *this;
	//}

	//_PointsBasic::~_PointsBasic(void)
	//{
	//	free();
	//}

	//void _PointsBasic::push_back(const _Point3D & s)
	//{
	//	chk_n_alloc();
	//	alloc.construct(first_free++, s);
	//}

	//std::pair<_Point3D*, _Point3D*> _PointsBasic::alloc_n_copy(const _Point3D *b, const _Point3D *e)
	//{
	//	auto data = alloc.allocate(e - b);
	//	return { data,std::uninitialized_copy(b,e,data) };
	//}

	//void _PointsBasic::free()
	//{
	//	if (element)
	//	{
	//		for (auto p = first_free; p != element;)
	//		{
	//			alloc.destroy(--p);
	//		}
	//		alloc.deallocate(element, cap - element);
	//	}
	//}

	//void _PointsBasic::reallocate()
	//{
	//	auto newcapacity = size() ? 2 * size() : 1;
	//	auto newdata = alloc.allocate(newcapacity);
	//	auto dest = newdata;
	//	auto elem = element;
	//	for (size_t i = 0; i != size(); ++i)
	//	{
	//		alloc.construct(dest++, std::move(*elem++));
	//	}
	//	free();
	//	element = newdata;
	//	first_free = dest;
	//	cap = element + newcapacity;
	//}

	_PointBasic0::_PointBasic0(void) :numPoints(0), numClass(0) {}

	_PointBasic0::_PointBasic0(std::vector<_Point3D>::iterator & it1, std::vector<_Point3D>::iterator & it2)
	{
		for (auto p = it1; p != it2; ++p)
		{
			this->points.push_back((*p).x);
			this->points.push_back((*p).y);
			this->points.push_back((*p).z);
		}
		this->pointsIndex.push_back(numPoints);
		this->numPoints += it2 - it1;
		++(this->numClass);
	}

	_PointBasic0::_PointBasic0(const float * points, size_t num)
	{
		for (size_t i = 0; i < num; ++i)
		{
			this->points.push_back(points[3 * i]);
			this->points.push_back(points[3 * i + 1]);
			this->points.push_back(points[3 * i + 2]);
		}
		this->pointsIndex.push_back(numPoints);
		this->numPoints += num;
		++(this->numClass);
	}

	void _PointBasic0::push_back(const _Point3D & point)
	{
		this->points.push_back(point.x);
		this->points.push_back(point.y);
		this->points.push_back(point.z);

		this->pointsIndex.push_back(numPoints);
		++numPoints;
		++numClass;
	}

	void _PointBasic0::push_back(float x, float y, float z)
	{
		this->points.push_back(x);
		this->points.push_back(y);
		this->points.push_back(z);

		this->pointsIndex.push_back(numPoints);
		++numPoints;
		++numClass;
	}

	void _PointBasic0::push_back(float * point)
	{
		this->points.push_back(points[0]);
		this->points.push_back(points[1]);
		this->points.push_back(points[2]);

		this->pointsIndex.push_back(numPoints);
		++numPoints;
		++numClass;
	}

	size_t _PointBasic0::pointsSize() const
	{
		return this->numPoints;
	}

	size_t _PointBasic0::classSize() const
	{
		return this->numClass;
	}

	_PointBasic0 & _PointBasic0::operator+(const _PointBasic0 & rhs)
	{
		for (size_t i = 0; i < rhs.pointsSize(); i++)
		{
			this->points.push_back(rhs.points[i * 3]);
			this->points.push_back(rhs.points[i * 3 + 1]);
			this->points.push_back(rhs.points[i * 3 + 2]);
		}

		for (auto i = rhs.pointsIndex.cbegin(); i != rhs.pointsIndex.cend(); ++i)
		{
			this->pointsIndex.push_back(*i);
		}
		
		this->numPoints += rhs.numPoints;
		this->numClass += rhs.numClass;
		return *this;
	}

	_PointBasic0 & _PointBasic0::operator+=(const _PointBasic0 & rhs)
	{
		*this = *this + rhs;
		return *this;
	}

}