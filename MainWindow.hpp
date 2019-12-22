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


#include "SnowFlake.hpp"

#include "Firmware/SceneData.hpp"

#include <QtCore/QTimer>
#include <QtWidgets/QMainWindow>


/// The main window of the application.
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// ctor
    ///
    MainWindow(QWidget *parent = nullptr);

    /// dtor
    ///
    ~MainWindow() = default;

public:
    /// Initialize the user interface.
    ///
    void initializeUi();

    /// Initialize the scene.
    ///
    void initializeScene();

private Q_SLOTS:
    /// Display the next frame.
    ///
    void displayNextFrame();

private:
    QTimer *_refreshTimer; ///< The refresh timer.
    SnowFlake *_snowFlake; ///< The widget with the snowflake simulation.
    SceneData *_sceneData; ///< The scene data to use for the scene.
    FrameIndex _frameCount; ///< The frame count for the scene.
    FrameIndex _frameIndex; ///< The current frame index.
};
