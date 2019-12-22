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
#include "Waves.hpp"


#include "../InterpolatingArray.hpp"
#include "../LedMaps.hpp"
#include "../RandomFrameCounters.hpp"
#include "../ShiftingMap.hpp"
#include "../ValueArrays.hpp"


namespace scene {
namespace Waves {


/// The bars array with the ramp for the effect.
///
const Fixed16 cWave[] = {
	Fixed16(1.0f), Fixed16(0.2f), Fixed16(0.0f), Fixed16(0.2f)
};

/// The number of elements in the bars array.
///
const uint8_t cWaveCount = sizeof(cWave)/sizeof(Fixed16);
	
/// The interpolating array.
///
const InterpolatingArray<cWaveCount> cWaveInterpolation(cWave);

/// The shifting map with a simple diagonal pattern.
///
const ShiftingMap<0> cDiagonalShiftingMap(LedMaps::cDiagonal);

/// The number of elements in the sparkle values array
///
const uint16_t cSparkleValuesCount = sizeof(ValueArrays::cRandom)/sizeof(Fixed16);

/// The interpolating array for the sparkle values.
///
const InterpolatingArray<cSparkleValuesCount> cSparkleValuesInterpolation(ValueArrays::cRandom);

/// Create a random frame counter for a the sparkle
///
const RandomFrameCounters<100, 2500, 2> gSparkleFrameCounters;


void initialize(SceneData *sceneData, uint8_t entropy)
{
	// Initialize the shifting map with a random direction from the given entropy value.
	cDiagonalShiftingMap.initialize(sceneData, (entropy/43), Fixed16(1.2f));
}


Frame getFrame(SceneData *sceneData, FrameIndex frameIndex)
{
	// Create the sparkle values frame
	auto sparkleValueFrame = gSparkleFrameCounters.getFrame(sceneData, [](Fixed16 x)->PixelValue{
		// Create relative value between 0.7 and 1.0 for later multiplication.
		return cSparkleValuesInterpolation.getHardValueAt(x) * Fixed16(0.3f) + Fixed16(0.7f);
	});
	// Create the frame with the wave animation.
	Frame waveFrame([=](uint8_t pixelIndex)->PixelValue{		
		return cWaveInterpolation.getSmoothValueAt(cDiagonalShiftingMap.getPositionWrapped(sceneData, pixelIndex, cFrameCount, frameIndex));
	});
	// Combine the two.
	waveFrame.multipleWith(sparkleValueFrame);
	return waveFrame;
}


}
}
