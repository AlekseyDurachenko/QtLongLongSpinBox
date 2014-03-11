QtLongLongSpinBox
=================

The spin box (linke QSpinBox) for qlonglong numbers:

![Screenshot](https://raw.github.com/AlekseyDurachenko/QtLongLongSpinBox/master/qtlonglongspinbox.png)

Usage
=====
- clone the repository: git clone https://github.com/AlekseyDurachenko/QtLongLongSpinBox.git lib/qtlonglongspinbox
- add the line to the .pro file: include($$PWD/lib/qtlonglongspinbox/qtlonglongspinbox.pri)

Example
=======
    #include <QApplication>
    #include <QtLongLongSpinBox>

    int main(int argc, char *argv[])
    {
        QApplication app(argc, argv);

        QtLongLongSpinBox widget;
        widget.resize(200, 20);
        widget.setValue(291834);
        widget.show();

        return app.exec();
    }
