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
#include "qtlonglongspinbox.h"
#include <QLineEdit>
#include <limits>

QtLongLongSpinBox::QtLongLongSpinBox(QWidget *parent) :
        QAbstractSpinBox(parent)
{
    m_value = 0;
    m_minimum = std::numeric_limits<qlonglong>::min();
    m_maximum = std::numeric_limits<qlonglong>::max();
    m_singleStep = 1;
    updateEdit();
}

qlonglong QtLongLongSpinBox::value() const
{
    return valueFromText(lineEdit()->text());
}

QString QtLongLongSpinBox::cleanText() const
{
    return QString::number(valueFromText(lineEdit()->text()));
}

qlonglong QtLongLongSpinBox::minimum() const
{
    return m_minimum;
}

qlonglong QtLongLongSpinBox::maximum() const
{
    return m_maximum;
}

qlonglong QtLongLongSpinBox::singleStep() const
{
    return m_singleStep;
}

const QString &QtLongLongSpinBox::prefix() const
{
    return m_prefix;
}

const QString &QtLongLongSpinBox::suffix() const
{
    return m_suffix;
}

void QtLongLongSpinBox::setMinimum(qlonglong min)
{
    m_minimum = min;
    if (m_maximum < m_minimum) m_maximum = m_minimum;
    setValue(value());
}

void QtLongLongSpinBox::setMaximum(qlonglong max)
{
    m_maximum = max;
    if (m_maximum < m_minimum) m_maximum = m_minimum;
    setValue(value());
}

void QtLongLongSpinBox::setRange(qlonglong min, qlonglong max)
{
    m_minimum = min;
    m_maximum = max;
    if (m_maximum < m_minimum) m_maximum = m_minimum;
    setValue(value());
}

void QtLongLongSpinBox::setPrefix(const QString &prefix)
{
    m_prefix = prefix;
    updateEdit();
}

void QtLongLongSpinBox::setSuffix(const QString &suffix)
{
    m_suffix = suffix;
    updateEdit();
}

void QtLongLongSpinBox::setSingleStep(qlonglong step)
{
    m_singleStep = step;
}

void QtLongLongSpinBox::setValue(qlonglong value)
{
    qint64 v = qBound(minimum(), value, maximum());
    if (m_value != v)
    {
        m_value = v;
        QString text = prefix() + textFromValue(v) + suffix();
        lineEdit()->setText(text);
        emit valueChanged(v);
        emit valueChanged(text);
    }
}

QValidator::State QtLongLongSpinBox::validate(QString &input, int &) const
{
    QString tmp = input;
    if (!prefix().isEmpty() && tmp.startsWith(prefix()))
    {
        tmp.remove(0, prefix().size());
    }
    if (!suffix().isEmpty() && tmp.endsWith(suffix()))
    {
        tmp.chop(suffix().size());
    }

    bool ok;
    qlonglong value = tmp.toLongLong(&ok);
    if (!ok || value < minimum() || value > maximum())
    {
        return QValidator::Invalid;
    }
    return QValidator::Acceptable;
}

void QtLongLongSpinBox::fixup(QString &) const
{
}

QString QtLongLongSpinBox::textFromValue(qlonglong value) const
{
    return QString::number(value);
}

qlonglong QtLongLongSpinBox::valueFromText(const QString &text) const
{
    QString tmp = text;
    if (!prefix().isEmpty() && tmp.startsWith(prefix()))
    {
        tmp.remove(0, prefix().size());
    }
    if (!suffix().isEmpty() && tmp.endsWith(suffix()))
    {
        tmp.chop(suffix().size());
    }

    return tmp.toLongLong();
}

QAbstractSpinBox::StepEnabled QtLongLongSpinBox::stepEnabled() const
{
    if (isReadOnly())
    {
        return 0;
    }

    if (wrapping())
    {
        return StepUpEnabled|StepDownEnabled;
    }

    StepEnabled se = 0;
    if (value() < maximum()) se |= StepUpEnabled;
    if (value() > minimum()) se |= StepDownEnabled;

    return se;
}

void QtLongLongSpinBox::stepBy(int steps)
{
    if (isReadOnly())
    {
        return;
    }

    if (steps == 0)
    {
        return;
    }

    qlonglong v = value() + steps*singleStep();
    // TODO:
    //if (wrapping())

    setValue(qBound(minimum(), v, maximum()));
    selectAll();
}

void QtLongLongSpinBox::updateEdit()
{
    QString text = prefix() + textFromValue(value()) + suffix();
    lineEdit()->setText(text);
}
