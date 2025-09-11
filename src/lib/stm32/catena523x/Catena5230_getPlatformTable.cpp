/* Catena5230_getPlatformTable.cpp	Mon Nov 26 2018 17:27:02 chwon */

/*

Module:  Catena5230_getPlatformTable.cpp

Function:
	Catena5230::getPlatformTable()

Version:
	V0.12.0	Mon Nov 26 2018 17:27:02 chwon	Edit level 1

Copyright notice:
	This file copyright (C) 2018 by

		MCCI Corporation
		3520 Krums Corners Road
		Ithaca, NY  14850

	An unpublished work.  All rights reserved.

	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of MCCI Corporation

Author:
	ChaeHee Won, MCCI Corporation	November 2018

Revision history:
   0.12.0  Mon Nov 26 2018 17:27:02  chwon
	Module created.

*/

#ifdef ARDUINO_ARCH_STM32

#include "Catena5230.h"

#include "Catena_Log.h"
#include "Catena_Platforms.h"
#include "Catena_Guids.h"

namespace McciCatena {

const CATENA_PLATFORM gkPlatformCatena5230 =
	{
	Guid: GUID_HW_CATENA_5230_BASE(WIRE),
	pParent: &gkPlatformCatena5230,
	PlatformFlags:
		CatenaBase::fHasLoRa |
		CatenaBase::fHasTtnNycLoRa |
		CatenaBase::fHasLuxLtr329 |
		CatenaBase::fHasFRAM |
		CatenaBase::fHasFlash
	PlatformFlags2:
		CatenaBase::fHasSHT4X |
		CatenaBase::fHasNpm1300 |
		CatenaBase::fHasLIS2DUXS12
	};

const CATENA_PLATFORM (* const Catena5230::vPlatforms[]) =
	{
	// entry 0 is the default
	&gkPlatformCatena5230,
	};

const size_t Catena5230::nvPlatforms = sizeof(Catena5230::vPlatforms) / sizeof(Catena5230::vPlatforms[0]);

/*

Name:	Catena5230::getPlatformTable()

Function:
	Get the known platform table.

Definition:
	public: virtual
		void Catena5230::getPlatformTable(
                        const CATENA_PLATFORM * const * &vPlatforms,
                        size_t &nvPlatforms
                        ) override;

Description:
	This override for getPlatformTable() returns the vector of platform
        GUIDs for this Catena.

Returns:
	vPlatforms is set to the base of the array of pointers to platform
        stuctures; and nvPlatforms is set to the number of entries in
        the table.

*/

/* public virtual override */
void
Catena5230::getPlatformTable(
        const CATENA_PLATFORM * const * &result_vPlatforms,
        size_t &result_nvPlatforms
        )
	{
        result_vPlatforms = vPlatforms;
        result_nvPlatforms = nvPlatforms;
	}

} /* namespace McciCatena */

#endif // ARDUINO_ARCH_STM32
