/*
 * COIFilter.cpp
 *
 *  Created on: Oct 30, 2012
 *      Author: bkloppen
 */

#include "oi_filter.hpp"
#include "COIDataRow.h"

namespace ccoifits
{

/// Returns a vector of OIDataPtr whose array matches array_name.
OIDataList FilterByArrayName(const OIDataList & data, string array_name)
{
	OIDataList output;

	for(OIDataRowPtr row: data)
	{
		if(row->GetArrayName() == array_name)
			output.push_back(row);
	}

	return output;
}

/// Returns a vector of OIDataPtr whose combiner matches combiner_name
OIDataList FilterByCombinerName(const OIDataList & data, string combiner_name)
{
	OIDataList output;

	for(OIDataRowPtr row: data)
	{
		if(row->GetCombinerName() == combiner_name)
			output.push_back(row);
	}

	return output;
}

/// Returns a vector of OIDataPtr which have the specified data type
/// Operation is O(data.size())
OIDataList FilterByDataType(const OIDataList & data, ccoifits::DataTypes type)
{
	OIDataList output;

	for(OIDataRowPtr row: data)
	{
		if(row->GetType() == type)
			output.push_back(row);
	}

	return output;
}

/// Splits the data into three sublists based upon data type.
/// Operation is O( data.size() ) (i.e. faster than three calls to FilterByDataType
void FilterByDataType(const OIDataList & data, OIDataList & vis_rows, OIDataList & v2_rows, OIDataList & t3_rows)
{
	// First split the data into three sublists:
	for(auto row: data)
	{
		if(row->GetType() == ccoifits::OI_VIS)
			vis_rows.push_back(row);
		else if(row->GetType() == ccoifits::OI_VIS2)
			v2_rows.push_back(row);
		else if(row->GetType() == ccoifits::OI_T3)
			t3_rows.push_back(row);
	}
}

/// Returns a vector of OIDataPtr which are within search_radius of the specifed (ra,dec) values.
OIDataList FilterByObjectCoords(const OIDataList & data, double ra, double dec, double search_radius)
{
	OIDataList output;

	for(OIDataRowPtr row: data)
	{
		if(row->DistanceTo(ra, dec) < search_radius)
			output.push_back(row);
	}

	return output;
}

/// Returns a vector of OIDataPtr which correspond to the specified object_name
OIDataList FilterByObjectName(const OIDataList & data, string object_name)
{
	OIDataList output;

	for(OIDataRowPtr row: data)
	{
		if(row->GetObjectName() == object_name)
			output.push_back(row);
	}

	return output;
}


/// Returns a vector of OIDataPtrs whose observation time is within the range specified.
OIDataList FilterByObservationMJD(const OIDataList & data, pair<double, double> mjd_range)
{
	OIDataList output;

	for(OIDataRowPtr row: data)
	{
		if(InRange(row->mjd, mjd_range))
			output.push_back(row);
	}

	return output;
}

/// Returns a vector of OIDataPtrs which contain data from within the specified wavelength range.
/// Wavelength filtering is accomplished by modifying the underlying data flags, therefore this
/// function performs deep copies of the data structures when needed.
OIDataList FilterByWavelength(const OIDataList & data, pair<double,double> wavelength_range)
{
	// This function applies filtering to the data itself, therefore it
	//
	// 1) Copies the underlying COIDataRow object
	// 2) Manipulates the COIDataRow::flag member
	// 3) Creates a new OIDataPtr object and appends it to the output vector
	// 4) Returns the vector.

	OIDataList output;

	for(OIDataRowPtr row: data)
	{

	}

	return output;
}

} /* namespace ccoifits */
