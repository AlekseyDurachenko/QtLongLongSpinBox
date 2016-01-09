QtLongLongSpinBox
=================

The spin box (like QSpinBox) for qlonglong (64-bit signed integer) numbers:

![Screenshot](doc/examples/simple/img/screenshot001.png)

Example
=======
```c++
// main.cpp
#include <QApplication>
#include <QtLongLongSpinBox>

int main(int argc, char *argv[])
{
    QtLongLongSpinBox *widget = new QtLongLongSpinBox;
    QObject::connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    widget->resize(200, 20);
    widget->setValue(123456);
    widget->show();

    return app.exec();
}
```
