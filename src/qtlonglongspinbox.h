// Copyright (C) 2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
#ifndef QTLONGLONGSPINBOX_H
#define QTLONGLONGSPINBOX_H

#include <QAbstractSpinBox>
#include <QtGlobal>

class QtLongLongSpinBox : public QAbstractSpinBox
{
    Q_OBJECT
public:
    explicit QtLongLongSpinBox(QWidget *parent = 0);

    qlonglong value() const;
    QString	cleanText() const;
    qlonglong minimum() const;
    qlonglong maximum() const;
    qlonglong singleStep() const;
    const QString &prefix() const;
    const QString &suffix() const;

    void setMinimum(qlonglong min);
    void setMaximum(qlonglong max);
    void setRange(qlonglong min, qlonglong max);
    void setPrefix(const QString &prefix);
    void setSuffix(const QString &suffix);
    void setSingleStep(qlonglong step);

public slots:
    void setValue(qlonglong value);

signals:
    void valueChanged(qlonglong i);
    void valueChanged(const QString &text);

protected:
    virtual QValidator::State validate(QString & input, int &pos) const;
    virtual void fixup(QString &input) const;
    virtual QString textFromValue(qlonglong value) const;
    virtual qlonglong valueFromText(const QString &text) const;
    virtual StepEnabled stepEnabled() const;
    virtual void stepBy(int steps);

private:
    void updateEdit();

private:
    qlonglong m_value;
    qlonglong m_minimum;
    qlonglong m_maximum;
    qlonglong m_singleStep;
    QString m_prefix;
    QString m_suffix;

private:
    Q_DISABLE_COPY(QtLongLongSpinBox)

};

#endif // QTLONGLONGSPINBOX_H
