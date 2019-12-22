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
#include "MainWindow.hpp"


#include "Firmware/scene/User.hpp"

#include <QtGui/QPainter>
#include <QtWidgets/QVBoxLayout>


// Define the namespace of the scene to test.
//
#define SceneName scene::User


MainWindow::MainWindow(QWidget *parent)
:
    QMainWindow(parent),
    _refreshTimer(nullptr),
    _snowFlake(nullptr),
    _sceneData(nullptr),
    _frameCount(1),
    _frameIndex(0)
{
    initializeUi();
    initializeScene();
}


void MainWindow::initializeUi()
{
    auto centralWidget = new QFrame();
    auto mainLayout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    _snowFlake = new SnowFlake();
    mainLayout->addWidget(_snowFlake);

    // Setup a timer to display the frames.
    _refreshTimer = new QTimer(this);
    _refreshTimer->setTimerType(Qt::PreciseTimer);
    _refreshTimer->setSingleShot(false);
    _refreshTimer->setInterval(30);
    connect(_refreshTimer, &QTimer::timeout, this, &MainWindow::displayNextFrame);

    // Start the timer.
    _refreshTimer->start();
}


void MainWindow::initializeScene()
{
    // Create empry scene data.
    _sceneData = new SceneData();
    // Initialize the scene.
    SceneName::initialize(_sceneData, 0);
    // Reset the frame counter.
    _frameCount = SceneName::cFrameCount;
    _frameIndex = 0;
}


void MainWindow::displayNextFrame()
{
    // Display the next frame.
    auto frame = SceneName::getFrame(_sceneData, _frameIndex);
    _snowFlake->setFrame(frame);
    _frameIndex += 1;
    if (_frameIndex >= _frameCount) {
        _frameIndex = 0;
    }
}



