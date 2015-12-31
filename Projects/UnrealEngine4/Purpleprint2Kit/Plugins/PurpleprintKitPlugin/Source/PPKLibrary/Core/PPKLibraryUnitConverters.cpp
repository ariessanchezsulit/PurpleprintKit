/*
===========================================================================
This code is part of the "Source Code" content in
Purpleprint 2 - Kit by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/PurpleprintKit>

The MIT License (MIT)
Copyright (c) 2014-2016 David Palacios (Hevedy) <https://github.com/Hevedy>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================
*/

/*
================================================
PPKLibraryUnitConverters.cpp
================================================
*/


#include "PPKLibraryPrivatePCH.h"
#include "PPKLibraryUnitConverters.h"

#include <chrono>
#include <random>

UPPKLibraryUnitConverters::UPPKLibraryUnitConverters( const class FObjectInitializer& ObjectInitializer ) {

}

float UPPKLibraryUnitConverters::AreaUnitsConverterSimple( const float UnitValue, const EAreaUnitsList UnitFrom, const EAreaUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::AreaUnitsConverterAdvanced( const float UnitValue, const EAreaUnitsList UnitFrom, const EAreaUnitsList UnitToValueA, const EAreaUnitsList UnitToValueB,
												  const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::AreaUnitsConverterComplete( const float UnitValue, const EAreaUnitsList UnitFrom, const bool bTruncate, FAreaUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.USKilometre = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSKilometre );
		UnitList.USMetre = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSMetre );
		UnitList.USMile = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSMile );
		UnitList.USYard = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSYard );
		UnitList.USFoot = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSFoot );
		UnitList.USInch = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSInch );
		UnitList.UHectare = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUHectare );
		UnitList.UAcre = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUAcre );
	} else {
		UnitList.USKilometre = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSKilometre ) );
		UnitList.USMetre = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSMetre ) );
		UnitList.USMile = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSMile ) );
		UnitList.USYard = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSYard ) );
		UnitList.USFoot = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSFoot ) );
		UnitList.USInch = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSInch ) );
		UnitList.UHectare = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUHectare ) );
		UnitList.UAcre = FMath::TruncToInt( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUAcre ) );
	}
}

float UPPKLibraryUnitConverters::DTRUnitsConverterSimple( const float UnitValue, const EDTRUnitsList UnitFrom, const EDTRUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::DTRUnitsConverterAdvanced( const float UnitValue, const EDTRUnitsList UnitFrom, const EDTRUnitsList UnitToValueA, const EDTRUnitsList UnitToValueB,
												  const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::DTRUnitsConverterComplete( const float UnitValue, const EDTRUnitsList UnitFrom, const bool bTruncate, FDTRUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UBitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUBitPS );
		UnitList.UKilobitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUKilobitPS );
		UnitList.UKilobytePS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUKilobytePS );
		UnitList.UKibibitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUKibibitPS );
		UnitList.UMegabitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUMegabitPS );
		UnitList.UMegabytePS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUMegabytePS );
		UnitList.UMebibitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUMebibitPS );
		UnitList.UGigabitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUGigabitPS );
		UnitList.UGigabytePS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUGigabytePS );
		UnitList.UGibibitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUGibibitPS );
		UnitList.UTerabitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUTerabitPS );
		UnitList.UTerabytePS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUTerabytePS );
		UnitList.UTebibitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUTebibitPS );
	} else {
		UnitList.UBitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUBitPS ) );
		UnitList.UKilobitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUKilobitPS ) );
		UnitList.UKilobytePS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUKilobytePS ) );
		UnitList.UKibibitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUKibibitPS ) );
		UnitList.UMegabitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUMegabitPS ) );
		UnitList.UMegabytePS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUMegabytePS ) );
		UnitList.UMebibitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUMebibitPS ) );
		UnitList.UGigabitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUGigabitPS ) );
		UnitList.UGigabytePS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUGigabytePS ) );
		UnitList.UGibibitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUGibibitPS ) );
		UnitList.UTerabitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUTerabitPS ) );
		UnitList.UTerabytePS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUTerabytePS ) );
		UnitList.UTebibitPS = FMath::TruncToInt( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUTebibitPS ) );
	}
}

float UPPKLibraryUnitConverters::DSUnitsConverterSimple( const float UnitValue, const EDSUnitsList UnitFrom, const EDSUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::DSUnitsConverterAdvanced( const float UnitValue, const EDSUnitsList UnitFrom, const EDSUnitsList UnitToValueA, const EDSUnitsList UnitToValueB,
												 const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::DSUnitsConverterComplete( const float UnitValue, const EDSUnitsList UnitFrom, const bool bTruncate, FDSUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UBit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUBit );
		UnitList.UKilobit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKilobit );
		UnitList.UKibibit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKibibit );
		UnitList.UMegabit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMegabit );
		UnitList.UMebibit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMebibit );
		UnitList.UGigabit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGigabit );
		UnitList.UGibibit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGibibit );
		UnitList.UTerabit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTerabit );
		UnitList.UTebibit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTebibit );
		UnitList.UPetabit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPetabit );
		UnitList.UPebibit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPebibit );
		UnitList.UByte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUByte );
		UnitList.UKilobyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKilobyte );
		UnitList.UKibibyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKibibyte );
		UnitList.UMegabyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMegabyte );
		UnitList.UMebibyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMebibyte );
		UnitList.UGigabyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGigabyte );
		UnitList.UGibibyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGibibyte );
		UnitList.UTerabyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTerabyte );
		UnitList.UTebibyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTebibyte );
		UnitList.UPetabyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPetabyte );
		UnitList.UPebibyte = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPebibyte );
	} else {
		UnitList.UBit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUBit ) );
		UnitList.UKilobit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKilobit ) );
		UnitList.UKibibit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKibibit ) );
		UnitList.UMegabit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMegabit ) );
		UnitList.UMebibit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMebibit ) );
		UnitList.UGigabit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGigabit ) );
		UnitList.UGibibit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGibibit ) );
		UnitList.UTerabit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTerabit ) );
		UnitList.UTebibit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTebibit ) );
		UnitList.UPetabit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPetabit ) );
		UnitList.UPebibit = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPebibit ) );
		UnitList.UByte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUByte ) );
		UnitList.UKilobyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKilobyte ) );
		UnitList.UKibibyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUKibibyte ) );
		UnitList.UMegabyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMegabyte ) );
		UnitList.UMebibyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUMebibyte ) );
		UnitList.UGigabyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGigabyte ) );
		UnitList.UGibibyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUGibibyte ) );
		UnitList.UTerabyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTerabyte ) );
		UnitList.UTebibyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUTebibyte ) );
		UnitList.UPetabyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPetabyte ) );
		UnitList.UPebibyte = FMath::TruncToInt( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUPebibyte ) );
	}
}

float UPPKLibraryUnitConverters::FrequencyUnitsConverterSimple( const float UnitValue, const EFrequencyUnitsList UnitFrom, const EFrequencyUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::FrequencyUnitsConverterAdvanced( const float UnitValue, const EFrequencyUnitsList UnitFrom, const EFrequencyUnitsList UnitToValueA, const EFrequencyUnitsList UnitToValueB,
												 const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::FrequencyUnitsConverterComplete( const float UnitValue, const EFrequencyUnitsList UnitFrom, const bool bTruncate, FFrequencyUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UHertz = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUHertz );
		UnitList.UKilohertz = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUKilohertz );
		UnitList.UMegahertz = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUMegahertz );
		UnitList.UGigahertz = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUGigahertz );
	} else {
		UnitList.UHertz = FMath::TruncToInt( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUHertz ) );
		UnitList.UKilohertz = FMath::TruncToInt( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUKilohertz ) );
		UnitList.UMegahertz = FMath::TruncToInt( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUMegahertz ) );
		UnitList.UGigahertz = FMath::TruncToInt( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUGigahertz ) );
	}
}

float UPPKLibraryUnitConverters::LenghtUnitsConverterSimple( const float UnitValue, const ELenghtUnitsList UnitFrom, const ELenghtUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::LenghtUnitsConverterAdvanced( const float UnitValue, const ELenghtUnitsList UnitFrom, const ELenghtUnitsList UnitToValueA, const ELenghtUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::LenghtUnitsConverterComplete( const float UnitValue, const ELenghtUnitsList UnitFrom, const bool bTruncate, FLenghtUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UKilometre = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUKilometre );
		UnitList.UMetre = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMetre );
		UnitList.UCentimetre = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUCentimetre );
		UnitList.UMillimetre = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMillimetre );
		UnitList.UMicrometre = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMicrometre );
		UnitList.UNanometre = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUNanometre );
		UnitList.UMile = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMile );
		UnitList.UYard = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUYard );
		UnitList.UFoot = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUFoot );
		UnitList.UInch = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUInch );
		UnitList.UNauticalMile = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUNauticalMile );
	} else {
		UnitList.UKilometre = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUKilometre ) );
		UnitList.UMetre = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMetre ) );
		UnitList.UCentimetre = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUCentimetre ) );
		UnitList.UMillimetre = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMillimetre ) );
		UnitList.UMicrometre = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMicrometre ) );
		UnitList.UNanometre = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUNanometre ) );
		UnitList.UMile = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUMile ) );
		UnitList.UYard = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUYard ) );
		UnitList.UFoot = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUFoot ) );
		UnitList.UInch = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUInch ) );
		UnitList.UNauticalMile = FMath::TruncToInt( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUNauticalMile ) );
	}
}

float UPPKLibraryUnitConverters::MassUnitsConverterSimple( const float UnitValue, const EMassUnitsList UnitFrom, const EMassUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::MassUnitsConverterAdvanced( const float UnitValue, const EMassUnitsList UnitFrom, const EMassUnitsList UnitToValueA, const EMassUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::MassUnitsConverterComplete( const float UnitValue, const EMassUnitsList UnitFrom, const bool bTruncate, FMassUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UTonne = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUTonne );
		UnitList.UKilogram = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUKilogram );
		UnitList.UGram = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUGram );
		UnitList.UMilligram = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUMilligram );
		UnitList.UMicrogram = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUMicrogram );
		UnitList.UImperialTon = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUImperialTon );
		UnitList.UUSTon = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUUSTon );
		UnitList.UStone = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUStone );
		UnitList.UPound = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUPound );
		UnitList.UOunce = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUOunce );
	} else {
		UnitList.UTonne = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUTonne ) );
		UnitList.UKilogram = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUKilogram ) );
		UnitList.UGram = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUGram ) );
		UnitList.UMilligram = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUMilligram ) );
		UnitList.UMicrogram = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUMicrogram ) );
		UnitList.UImperialTon = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUImperialTon ) );
		UnitList.UUSTon = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUUSTon ) );
		UnitList.UStone = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUStone ) );
		UnitList.UPound = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUPound ) );
		UnitList.UOunce = FMath::TruncToInt( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUOunce ) );
	}
}

float UPPKLibraryUnitConverters::PAUnitsConverterSimple( const float UnitValue, const EPAUnitsList UnitFrom, const EPAUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::PAUnitsConverterAdvanced( const float UnitValue, const EPAUnitsList UnitFrom, const EPAUnitsList UnitToValueA, const EPAUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::PAUnitsConverterComplete( const float UnitValue, const EPAUnitsList UnitFrom, const bool bTruncate, FPAUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UAngularMil = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUAngularMil );
		UnitList.UDegree =( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUDegree );
		UnitList.UGradian = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUGradian );
		UnitList.UMinuteOfArc = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUMinuteOfArc );
		UnitList.URadian = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAURadian );
		UnitList.USecondOfArc = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUSecondOfArc );
	} else {
		UnitList.UAngularMil = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUAngularMil ) );
		UnitList.UDegree = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUDegree ) );
		UnitList.UGradian = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUGradian ) );
		UnitList.UMinuteOfArc = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUMinuteOfArc ) );
		UnitList.URadian = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAURadian ) );
		UnitList.USecondOfArc = FMath::TruncToInt( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUSecondOfArc ) );
	}
}

float UPPKLibraryUnitConverters::SpeedUnitsConverterSimple( const float UnitValue, const ESpeedUnitsList UnitFrom, const ESpeedUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::SpeedUnitsConverterAdvanced( const float UnitValue, const ESpeedUnitsList UnitFrom, const ESpeedUnitsList UnitToValueA, const ESpeedUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::SpeedUnitsConverterComplete( const float UnitValue, const ESpeedUnitsList UnitFrom, const bool bTruncate, FSpeedUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UMilesPH = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUMilesPH );
		UnitList.UFootPS = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUFootPS );
		UnitList.UMetrePS = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUMetrePS );
		UnitList.UKilometrePH = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUKilometrePH );
		UnitList.UKnot = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUKnot );
	} else {
		UnitList.UMilesPH = FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUMilesPH ) );
		UnitList.UFootPS = FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUFootPS ) );
		UnitList.UMetrePS = FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUMetrePS ) );
		UnitList.UKilometrePH = FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUKilometrePH ) );
		UnitList.UKnot = FMath::TruncToInt( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUKnot ) );
	}
}

float UPPKLibraryUnitConverters::TempUnitsConverterSimple( const float UnitValue, const ETempUnitsList UnitFrom, const ETempUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::TempUnitsConverterAdvanced( const float UnitValue, const ETempUnitsList UnitFrom, const ETempUnitsList UnitToValueA, const ETempUnitsList UnitToValueB,
												   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::TempUnitsConverterComplete( const float UnitValue, const ETempUnitsList UnitFrom, const bool bTruncate, FTempUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UCelsius = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUCelsius );
		UnitList.UFahrenheit = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUFahrenheit );
		UnitList.UKelvin = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUKelvin );
	} else {
		UnitList.UCelsius = FMath::TruncToInt( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUCelsius ) );
		UnitList.UFahrenheit = FMath::TruncToInt( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUFahrenheit ) );
		UnitList.UKelvin = FMath::TruncToInt( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUKelvin ) );
	}
}

float UPPKLibraryUnitConverters::TimeUnitsConverterSimple( const float UnitValue, const ETimeUnitsList UnitFrom, const ETimeUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitTo ) );
	}
		return ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::TimeUnitsConverterAdvanced( const float UnitValue, const ETimeUnitsList UnitFrom, const ETimeUnitsList UnitToValueA, const ETimeUnitsList UnitToValueB, 
												  const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::TimeUnitsConverterComplete( const float UnitValue, const ETimeUnitsList UnitFrom, const bool bTruncate, FTimeUnitsStruct& UnitList ) {	
	if ( !bTruncate ) {
		UnitList.UNanosecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUNanosecond );
		UnitList.UMicrosecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMicrosecond );
		UnitList.UMillisecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMillisecond );
		UnitList.USecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUSecond );
		UnitList.UMinute = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMinute );
		UnitList.UHour = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUHour );
		UnitList.UDay = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDay );
		UnitList.UWeek = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUWeek );
		UnitList.UMonth = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMonth );
		UnitList.UYear = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUYear );
		UnitList.UDecade = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDecade );
		UnitList.UCentury = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUCentury );
	} else {
		UnitList.UNanosecond = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUNanosecond ));
		UnitList.UMicrosecond = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMicrosecond ));
		UnitList.UMillisecond = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMillisecond ));
		UnitList.USecond = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUSecond ));
		UnitList.UMinute = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMinute ));
		UnitList.UHour = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUHour ));
		UnitList.UDay = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDay ));
		UnitList.UWeek = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUWeek ));
		UnitList.UMonth = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMonth ));
		UnitList.UYear = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUYear ));
		UnitList.UDecade = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDecade ));
		UnitList.UCentury = FMath::TruncToInt(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUCentury ));
	}
}

float UPPKLibraryUnitConverters::VolUnitsConverterSimple( const float UnitValue, const EVolUnitsList UnitFrom, const EVolUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitTo );
}

void UPPKLibraryUnitConverters::VolUnitsConverterAdvanced( const float UnitValue, const EVolUnitsList UnitFrom, const EVolUnitsList UnitToValueA, const EVolUnitsList UnitToValueB,
												   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryUnitConverters::VolUnitsConverterComplete( const float UnitValue, const EVolUnitsList UnitFrom, const bool bTruncate, FVolUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UUSLiquidGallon = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidGallon );
		UnitList.UUSLiquidQuart = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidQuart );
		UnitList.UUSLiquidPint = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidPint );
		UnitList.UUSLegalCup = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLegalCup );
		UnitList.UUSFluidOunce = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSFluidOunce );
		UnitList.UUSTablespoon = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSTablespoon );
		UnitList.UUSTeaspoon = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSTeaspoon );
		UnitList.UCubicMetre = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUCubicMetre );
		UnitList.ULitre = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VULitre );
		UnitList.UMillilitre = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUMillilitre );
		UnitList.UImperialGallon = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialGallon );
		UnitList.UImperialQuart = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialQuart );
		UnitList.UImperialPint = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialPint );
		UnitList.UImperialCup = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialCup );
		UnitList.UImperialFluidOunce = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialFluidOunce );
		UnitList.UImperialTablespoon = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialTablespoon );
		UnitList.UImperialTeaspoon = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialTeaspoon );
		UnitList.UCubicFoot = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUCubicFoot );
		UnitList.UCubicInch = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUCubicInch );
	} else {
		UnitList.UUSLiquidGallon = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidGallon ) );
		UnitList.UUSLiquidQuart = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidQuart ) );
		UnitList.UUSLiquidPint = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidPint ) );
		UnitList.UUSLegalCup = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLegalCup ) );
		UnitList.UUSFluidOunce = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSFluidOunce ) );
		UnitList.UUSTablespoon = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSTablespoon ) );
		UnitList.UUSTeaspoon = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSTeaspoon ) );
		UnitList.UCubicMetre = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUCubicMetre ) );
		UnitList.ULitre = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VULitre ) );
		UnitList.UMillilitre = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUMillilitre ) );
		UnitList.UImperialGallon = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialGallon ) );
		UnitList.UImperialQuart = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialQuart ) );
		UnitList.UImperialPint = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialPint ) );
		UnitList.UImperialCup = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialCup ) );
		UnitList.UImperialFluidOunce = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialFluidOunce ) );
		UnitList.UImperialTablespoon = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialTablespoon ) );
		UnitList.UImperialTeaspoon = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUImperialTeaspoon ) );
		UnitList.UCubicFoot = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUCubicFoot ) );
		UnitList.UCubicInch = FMath::TruncToInt( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUCubicInch ) );
	}
}

// TODO Add better conversion values

float UPPKLibraryUnitConverters::GetAreaUnitValue( const EAreaUnitsList AreaUnit ) {
	switch ( AreaUnit ) {
		case EAreaUnitsList::AUSKilometre:
			return 1.f;
			break;
		case EAreaUnitsList::AUSMetre:
			return 1.f;
			break;
		case EAreaUnitsList::AUSMile:
			return 1.f;
			break;
		case EAreaUnitsList::AUSYard:
			return 1.f;
			break;
		case EAreaUnitsList::AUSFoot:
			return 1.f;
			break;
		case EAreaUnitsList::AUSInch:
			return 1.f;
			break;
		case EAreaUnitsList::AUHectare:
			return 1.f;
			break;
		case EAreaUnitsList::AUAcre:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetDTRUnitValue( const EDTRUnitsList DTRUnit ) {
	switch ( DTRUnit ) {
		case EDTRUnitsList::DTRUBitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUKilobitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUKilobytePS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUKibibitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUMegabitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUMegabytePS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUMebibitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUGigabitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUGigabytePS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUGibibitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUTerabitPS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUTerabytePS:
			return 1.f;
			break;
		case EDTRUnitsList::DTRUTebibitPS:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetDSUnitValue( const EDSUnitsList DSUnit ) {
	switch ( DSUnit ) {
		case EDSUnitsList::DSUBit:
			return 1.f;
			break;
		case EDSUnitsList::DSUKilobit:
			return 1.f;
			break;
		case EDSUnitsList::DSUKibibit:
			return 1.f;
			break;
		case EDSUnitsList::DSUMegabit:
			return 1.f;
			break;
		case EDSUnitsList::DSUMebibit:
			return 1.f;
			break;
		case EDSUnitsList::DSUGigabit:
			return 1.f;
			break;
		case EDSUnitsList::DSUGibibit:
			return 1.f;
			break;
		case EDSUnitsList::DSUTerabit:
			return 1.f;
			break;
		case EDSUnitsList::DSUTebibit:
			return 1.f;
			break;
		case EDSUnitsList::DSUPetabit:
			return 1.f;
			break;
		case EDSUnitsList::DSUPebibit:
			return 1.f;
			break;
		case EDSUnitsList::DSUByte:
			return 1.f;
			break;
		case EDSUnitsList::DSUKilobyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUKibibyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUMegabyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUMebibyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUGigabyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUGibibyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUTerabyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUTebibyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUPetabyte:
			return 1.f;
			break;
		case EDSUnitsList::DSUPebibyte:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetFrequencyUnitValue( const EFrequencyUnitsList FrequencyUnit ) {
	switch ( FrequencyUnit ) {
		case EFrequencyUnitsList::FUHertz:
			return 1.f;
			break;
		case EFrequencyUnitsList::FUKilohertz:
			return 1.f;
			break;
		case EFrequencyUnitsList::FUMegahertz:
			return 1.f;
			break;
		case EFrequencyUnitsList::FUGigahertz:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetLenghtUnitValue( const ELenghtUnitsList LenghtUnit ) {
	switch ( LenghtUnit ) {
		case ELenghtUnitsList::LUKilometre:
			return 1.f;
			break;
		case ELenghtUnitsList::LUMetre:
			return 1.f;
			break;
		case ELenghtUnitsList::LUCentimetre:
			return 1.f;
			break;
		case ELenghtUnitsList::LUMillimetre:
			return 1.f;
			break;
		case ELenghtUnitsList::LUMicrometre:
			return 1.f;
			break;
		case ELenghtUnitsList::LUNanometre:
			return 1.f;
			break;
		case ELenghtUnitsList::LUMile:
			return 1.f;
			break;
		case ELenghtUnitsList::LUYard:
			return 1.f;
			break;
		case ELenghtUnitsList::LUFoot:
			return 1.f;
			break;
		case ELenghtUnitsList::LUInch:
			return 1.f;
			break;
		case ELenghtUnitsList::LUNauticalMile:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetMassUnitValue( const EMassUnitsList MassUnit ) {
	switch ( MassUnit ) {
		case EMassUnitsList::MUTonne:
			return 1.f;
			break;
		case EMassUnitsList::MUKilogram:
			return 1.f;
			break;
		case EMassUnitsList::MUGram:
			return 1.f;
			break;
		case EMassUnitsList::MUMilligram:
			return 1.f;
			break;
		case EMassUnitsList::MUMicrogram:
			return 1.f;
			break;
		case EMassUnitsList::MUImperialTon:
			return 1.f;
			break;
		case EMassUnitsList::MUUSTon:
			return 1.f;
			break;
		case EMassUnitsList::MUStone:
			return 1.f;
			break;
		case EMassUnitsList::MUPound:
			return 1.f;
			break;
		case EMassUnitsList::MUOunce:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetPAUnitValue( const EPAUnitsList PAUnit ) {
	switch ( PAUnit ) {
		case EPAUnitsList::PAUAngularMil:
			return 1.f;
			break;
		case EPAUnitsList::PAUDegree:
			return 1.f;
			break;
		case EPAUnitsList::PAUGradian:
			return 1.f;
			break;
		case EPAUnitsList::PAUMinuteOfArc:
			return 1.f;
			break;
		case EPAUnitsList::PAURadian:
			return 1.f;
			break;
		case EPAUnitsList::PAUSecondOfArc:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetSpeedUnitValue( const ESpeedUnitsList SpeedUnit ) {
	switch ( SpeedUnit ) {
		case ESpeedUnitsList::SUMilesPH:
			return 1.f;
			break;
		case ESpeedUnitsList::SUFootPS:
			return 1.f;
			break;
		case ESpeedUnitsList::SUMetrePS:
			return 1.f;
			break;
		case ESpeedUnitsList::SUKilometrePH:
			return 1.f;
			break;
		case ESpeedUnitsList::SUKnot:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetTempUnitValue( const ETempUnitsList TempUnit ) {
	switch ( TempUnit ) {
		case ETempUnitsList::TUCelsius:
			return 1.f;
			break;
		case ETempUnitsList::TUFahrenheit:
			return 1.f;
			break;
		case ETempUnitsList::TUKelvin:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetTimeUnitValue( const ETimeUnitsList TimeUnit ) {
	switch ( TimeUnit ) {
		case ETimeUnitsList::TUNanosecond:
			return 1.f * 60.f * 60.f * 1000.f * 1000.f * 1000.f;
			break;
		case ETimeUnitsList::TUMicrosecond:
			return 1.f * 60.f * 60.f * 1000.f * 1000.f;
			break;
		case ETimeUnitsList::TUMillisecond:
			return 1.f * 60.f * 60.f * 1000.f;
			break;
		case ETimeUnitsList::TUSecond:
			return 1.f * 60.f * 60.f;
			break;
		case ETimeUnitsList::TUMinute:
			return 1.f * 60.f;
			break;
		case ETimeUnitsList::TUHour:
			return 1.f; //Base
			break;
		case ETimeUnitsList::TUDay:
			return 1.f / 24.f;
			break;
		case ETimeUnitsList::TUWeek:
			return ( 1.f / 24.f ) / 7.f;
			break;
		case ETimeUnitsList::TUMonth:
			return ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f;
			break;
		case ETimeUnitsList::TUYear:
			return ( ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f ) / 12.f;
			break;
		case ETimeUnitsList::TUDecade:
			return ( ( ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f ) / 12.f ) / 10.f;
			break;
		case ETimeUnitsList::TUCentury:
			return ( ( ( ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f ) / 12.f ) / 10.f ) / 10.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryUnitConverters::GetVolUnitValue( const EVolUnitsList VolUnit ) {
	switch ( VolUnit ) {
		case EVolUnitsList::VUUSLiquidGallon:
			return 1.f;
			break;
		case EVolUnitsList::VUUSLiquidQuart:
			return 1.f;
			break;
		case EVolUnitsList::VUUSLiquidPint:
			return 1.f;
			break;
		case EVolUnitsList::VUUSLegalCup:
			return 1.f;
			break;
		case EVolUnitsList::VUUSFluidOunce:
			return 1.f;
			break;
		case EVolUnitsList::VUUSTablespoon:
			return 1.f;
			break;
		case EVolUnitsList::VUUSTeaspoon:
			return 1.f;
			break;
		case EVolUnitsList::VUCubicMetre:
			return 1.f;
			break;
		case EVolUnitsList::VULitre:
			return 1.f;
			break;
		case EVolUnitsList::VUMillilitre:
			return 1.f;
			break;
		case EVolUnitsList::VUImperialGallon:
			return 1.f;
			break;
		case EVolUnitsList::VUImperialQuart:
			return 1.f;
			break;
		case EVolUnitsList::VUImperialPint:
			return 1.f;
			break;
		case EVolUnitsList::VUImperialCup:
			return 1.f;
			break;
		case EVolUnitsList::VUImperialFluidOunce:
			return 1.f;
			break;
		case EVolUnitsList::VUImperialTablespoon:
			return 1.f;
			break;
		case EVolUnitsList::VUImperialTeaspoon:
			return 1.f;
			break;
		case EVolUnitsList::VUCubicFoot:
			return 1.f;
			break;
		case EVolUnitsList::VUCubicInch:
			return 1.f;
			break;
	}
	return 1.f;
}
