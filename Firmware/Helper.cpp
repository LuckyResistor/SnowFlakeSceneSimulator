//
// Snow Flake Project
// ---------------------------------------------------------------------------
// (c)2017 by Lucky Resistor. See LICENSE for details.
// https://luckyresistor.me
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#include "Helper.hpp"


#include <random>


namespace Helper {


/// A fast lagged Fibonacci pseudo random number generator.
///
std::ranlux24_base gRandomGeneratorEngine; 


void initialize()
{
	// Seed the PRND with some entropy.
    gRandomGeneratorEngine.seed(0);
}


void delayNop(uint32_t)
{
}
	

void delayMs(uint32_t)
{
}


uint32_t getSystemTimeMs()
{
    return 0;
}


void waitForSystemTime(uint32_t)
{
}


uint32_t getRandom32(uint32_t minimum, uint32_t maximum)
{
	std::uniform_int_distribution<> distribution(minimum, maximum);
	return distribution(gRandomGeneratorEngine);
}


uint16_t getRandom16(uint16_t minimum, uint16_t maximum)
{
	std::uniform_int_distribution<> distribution(minimum, maximum);
	return distribution(gRandomGeneratorEngine);
}


uint8_t getRandom8(uint8_t minimum, uint8_t maximum)
{
	std::uniform_int_distribution<> distribution(minimum, maximum);
	return distribution(gRandomGeneratorEngine);
}


}

