//
// Snow Flake Project
// ---------------------------------------------------------------------------
// (c)2017-2019 by Lucky Resistor. See LICENSE for details.
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
#include "Communication.hpp"


namespace Communication {


void initialize()
{
}


bool waitForNegotiation()
{
    return false;
}


Communication::Error getError()
{
    return Error::None;
}


uint8_t getIdentifier()
{
    return 0;
}


bool sendData(uint32_t)
{
    return false;
}


bool sendSynchronization()
{
    return false;
}


bool isReadyToSend()
{
    return false;
}


bool waitUntilReadyToSend()
{
    return false;
}


bool waitForData(uint32_t)
{
    return false;
}


uint32_t readData()
{
    return 0;
}


ButtonPress getNextButtonPress()
{
    return ButtonPress::None;
}


bool waitForSynchonization(uint32_t)
{
	return true;
}


void registerSynchronisationFunction(SynchronizationFn)
{
}


void registerReadDataFunction(ReadDataFn)
{
}


}

