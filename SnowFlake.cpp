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
#include "SnowFlake.hpp"


#include <QtGui/QPainter>


namespace {


const auto x0 = 70;
const auto x1 = 167;
const auto x2 = 196;
const auto x3 = 225;
const auto x4 = 256;
const auto x5 = 286;
const auto x6 = 316;
const auto x7 = 345;
const auto x8 = 442;

const auto y0 = 41;
const auto y2 = 152;
const auto y3 = 203;
const auto y4 = 256;
const auto y5 = 308;
const auto y6 = 359;
const auto y8 = 471;


const QPoint cLedPositions[Display::cLedCount] = {
    QPoint(x4, y0),
    QPoint(x8, y2),
    QPoint(x8, y6),
    QPoint(x4, y8),
    QPoint(x0, y6),
    QPoint(x0, y2),
    QPoint(x4, y2),
    QPoint(x7, y3),
    QPoint(x7, y5),
    QPoint(x4, y6),
    QPoint(x1, y5),
    QPoint(x1, y3),
    QPoint(x5, y3),
    QPoint(x6, y4),
    QPoint(x5, y5),
    QPoint(x3, y5),
    QPoint(x2, y4),
    QPoint(x3, y3),
    QPoint(x4, y4)
};


const int cLedRadius = 16;


}


SnowFlake::SnowFlake()
    : QFrame()
{
    initializeUi();
}


void SnowFlake::initializeUi()
{
    // Create a fixed size widget.
    setFixedSize(512, 512);
    // Load the background from the resources.
    _background = QPixmap(":/images/background.png");
}


void SnowFlake::setFrame(const Frame &frame)
{
    for (int i = 0; i < Display::cLedCount; ++i) {
        _currentValues[i] = getLedColor(qBound(0.0f, frame.pixelValue[i].toFloat(), 1.0f));
    }
    update();
    repaint();
}


void SnowFlake::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawPixmap(0, 0, _background);

    p.setPen(Qt::NoPen);
    for (int i = 0; i < Display::cLedCount; ++i) {
        auto center = cLedPositions[i];
        p.setBrush(_currentValues[i]);
        p.drawEllipse(center, cLedRadius, cLedRadius);
    }
}


QColor SnowFlake::getLedColor(qreal value)
{
    return QColor::fromRgbF(value, value, value);
}

