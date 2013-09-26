// Copyright (C) 2013, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#include "qtflexibleramarray.h"
#include "qtflexiblearrayfactory.h"
#include <string.h>

QtFlexibleRamArray::QtFlexibleRamArray(qint64 size)
    : QtFlexibleAbstractArray()
{
    m_size = size;
    m_biggestSize = size;
    if (size > 0)
        m_addr = QtFlexibleRamArray::alloc(size);
    else
        m_addr = 0;
}

QtFlexibleRamArray::~QtFlexibleRamArray()
{
    QtFlexibleRamArray::free(m_addr);
}

int QtFlexibleRamArray::typeId() const
{
    return QtFlexibleArrayFactory::Ram;
}

qint64 QtFlexibleRamArray::size() const
{
    return m_size;
}

qint64 QtFlexibleRamArray::resize(qint64 size)
{
    if (m_addr == 0)
    {
        m_addr = QtFlexibleRamArray::alloc(size);
        m_biggestSize = size;
    }
    else if (size > m_biggestSize)
    {
        char *tmp = QtFlexibleRamArray::alloc(size);
        memcpy(tmp, m_addr, m_size);
        QtFlexibleRamArray::free(m_addr);
        m_addr = tmp;
        m_biggestSize = size;
    }
    else if (size == 0)
    {
        QtFlexibleRamArray::free(m_addr);
        m_addr = 0;
        m_biggestSize = 0;
    }
    m_size = size;

    return size;
}

qint64 QtFlexibleRamArray::linearBytesAvaible(char *addr)
{
    return m_size - static_cast<qint64>(m_addr - addr);
}

bool QtFlexibleRamArray::assignData(char **data, qint64 size)
{
    QtFlexibleRamArray::free(m_addr);
    m_addr = *data;
    m_size = m_biggestSize = size;

    return true;
}

qint64 QtFlexibleRamArray::copyData(char *data, qint64 pos, qint64 size)
{
    memcpy(data, &m_addr[pos], size);
    return size;
}

qint64 QtFlexibleRamArray::writeData(char *data, qint64 pos, qint64 size)
{
    memcpy(&m_addr[pos], data, size);
    return size;
}

qint64 QtFlexibleRamArray::readData(char **data, qint64 pos, qint64 size)
{
    *data = &m_addr[pos];
    return size;
}

bool QtFlexibleRamArray::sync(char *addr)
{
    Q_UNUSED(addr);
    return true;
}

bool QtFlexibleRamArray::destroy(char *addr)
{
    Q_UNUSED(addr);
    return true;
}

void QtFlexibleRamArray::clean()
{
}

char *QtFlexibleRamArray::alloc(qint64 size)
{
    return new char[size];
}

void QtFlexibleRamArray::free(char* addr)
{
    delete []addr;
}
