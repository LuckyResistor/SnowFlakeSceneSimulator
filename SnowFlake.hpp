#pragma once
//
// (c)2019 by Lucky Resistor. See LICENSE for details.
// https://luckyresistor.me
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//


#include "Firmware/Frame.hpp"
#include "Firmware/Display.hpp"

#include <QtGui/QPixmap>
#include <QtWidgets/QFrame>


/// A widget representing a single snowflake.
///
class SnowFlake : public QFrame
{
public:
    /// ctor
    ///
    SnowFlake();

public:
    /// Initialize the user interface.
    ///
    void initializeUi();

    /// Update the widget with a new frame.
    ///
    void setFrame(const Frame &frame);

protected:
    /// Paint this custom widget.
    ///
    void paintEvent(QPaintEvent *e);

private:
    /// Get the LED color.
    ///
    static QColor getLedColor(qreal value);

private:
    QPixmap _background; ///< The background.
    QColor _currentValues[Display::cLedCount]; ///< The current LED values.
};

