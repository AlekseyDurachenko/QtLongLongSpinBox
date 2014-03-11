# Copyright (C) 2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
TARGET          = simple
TEMPLATE        = app
CONFIG         += console debug_and_release
QT             += core gui

DESTDIR         = bin
OBJECTS_DIR     = build/release_obj
MOC_DIR         = build/release_moc
UI_DIR          = build/release_ui
RCC_DIR         = build/release_rcc

# library as sources
include($$PWD/../../qtlonglongspinbox.pri)

SOURCES        += main.cpp

# debug
build_pass:CONFIG(debug, debug|release) {
    #TARGET      = $$join(TARGET,,,d)
    #DESTDIR     = $$join(OBJECTS_DIR,,,d)
    OBJECTS_DIR = $$join(OBJECTS_DIR,,,d)
    MOC_DIR     = $$join(MOC_DIR,,,d)
    UI_DIR      = $$join(UI_DIR,,,d)
    RCC_DIR     = $$join(RCC_DIR,,,d)

    win32 {
    }

    unix {
        LIBS +=
    }
}

# release
build_pass:CONFIG(release, debug|release) {
    win32 {
    }

    unix {
        LIBS +=
    }
}
