#
# (c)2019 by Lucky Resistor. See LICENSE for details.
# https://luckyresistor.me
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += link_prl

SOURCES += \
    SnowFlake.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.hpp \
    SnowFlake.hpp

SOURCES += \
    Firmware/Communication.cpp \
    Firmware/Fixed16.cpp \
    Firmware/Frame.cpp \
    Firmware/Helper.cpp \
    Firmware/LedMaps.cpp \
    Firmware/PixelCanvas.cpp \
    Firmware/PixelValue.cpp \
    Firmware/Scene.cpp \
    Firmware/SceneData.cpp \
    Firmware/ValueArrays.cpp \
    Firmware/scene/Black.cpp \
    Firmware/scene/Circles.cpp \
    Firmware/scene/IceSparkle.cpp \
    Firmware/scene/Rain.cpp \
    Firmware/scene/SimpleDiagonal.cpp \
    Firmware/scene/SimpleFlash.cpp \
    Firmware/scene/SimpleRandomFlicker.cpp \
    Firmware/scene/SimpleRandomParticle.cpp \
    Firmware/scene/SimpleRotation.cpp \
    Firmware/scene/SimpleShift.cpp \
    Firmware/scene/SkyWithStars.cpp \
    Firmware/scene/User.cpp \
    Firmware/scene/Waves.cpp

HEADERS += \
    Firmware/Communication.hpp \
    Firmware/Configuration.hpp \
    Firmware/Display.hpp \
    Firmware/Fixed16.hpp \
    Firmware/Frame.hpp \
    Firmware/Helper.hpp \
    Firmware/InterpolatingArray.hpp \
    Firmware/LedMaps.hpp \
    Firmware/PixelCanvas.hpp \
    Firmware/PixelParticleMap.hpp \
    Firmware/PixelPosition.hpp \
    Firmware/PixelValue.hpp \
    Firmware/RandomFrameCounters.hpp \
    Firmware/Scene.hpp \
    Firmware/SceneData.hpp \
    Firmware/ShiftingMap.hpp \
    Firmware/ValueArrays.hpp \
    Firmware/scene/Black.hpp \
    Firmware/scene/Circles.hpp \
    Firmware/scene/IceSparkle.hpp \
    Firmware/scene/Rain.hpp \
    Firmware/scene/SimpleDiagonal.hpp \
    Firmware/scene/SimpleFlash.hpp \
    Firmware/scene/SimpleRandomFlicker.hpp \
    Firmware/scene/SimpleRandomParticle.hpp \
    Firmware/scene/SimpleRotation.hpp \
    Firmware/scene/SimpleShift.hpp \
    Firmware/scene/SkyWithStars.hpp \
    Firmware/scene/User.hpp \
    Firmware/scene/Waves.hpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Data/data.qrc
