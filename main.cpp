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

#include <QtWidgets/QApplication>
#include <QtCore/QFile>


int main(int argc, char *argv[])
{
    // Make sure the application runs in retina displays.
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    // Create the application object.
    QApplication a(argc, argv);
    // Load and apply the application stylesheet.
    QFile applicationCss(":/css/application.css");
    applicationCss.open(QIODevice::ReadOnly);
    auto applicationStyleSheet = QString::fromUtf8(applicationCss.readAll());
    applicationCss.close();
    a.setStyleSheet(applicationStyleSheet);
    // Create and display the main window.
    MainWindow w;
    w.show();
    // Enter the mainloop.
    return a.exec();
}

