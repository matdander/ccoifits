/*
 * COIUV.h
 *
 *  Created on: Nov 7, 2012
 *      Author: bkloppen
 */

#ifndef COIUV_H_
#define COIUV_H_

#include <memory>
#include <cmath>

using namespace std;

namespace ccoifits
{

#define UV_THRESHOLD 5.0e-5

class COIUV;
typedef shared_ptr<COIUV> OIUVPtr;

class COIUV
{
public:
	double u;
	double v;

public:
	COIUV();
	COIUV(const COIUV & uv);
	COIUV(double u, double v);
	virtual ~COIUV();

	COIUV operator +(const COIUV & rhs)
	{
		return COIUV(this->u + rhs.u, this->v + rhs.v);
	}

	COIUV operator -(const COIUV & rhs)
	{
		return COIUV(this->u - rhs.u, this->v - rhs.v);
	}

	bool operator ==(const COIUV & rhs)
	{
		double du = this->u - rhs.u;
		double dv = this->v - rhs.v;

		if(sqrt(du*du + dv*dv) < UV_THRESHOLD)
			return true;

		return false;
	}

	template <typename T>
	bool operator *(T val)
	{
		this->u * val;
		this->v * val;
	}
};

} /* namespace ccoifits */
#endif /* COIUV_H_ */
