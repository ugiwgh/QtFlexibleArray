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
#ifndef QTFLEXIBLEABSTRACTARRAY_H
#define QTFLEXIBLEABSTRACTARRAY_H

#include <QtGlobal>

class QtFlexibleAbstractArray
{
public:
    explicit QtFlexibleAbstractArray();
    virtual ~QtFlexibleAbstractArray();
    virtual qint64 size() const = 0;
    virtual qint64 resize(qint64 size) = 0;
    virtual qint64 linearBytesAvaible(char *addr) = 0;
    virtual qint64 copyData(char *data, qint64 pos, qint64 size) = 0;
    virtual qint64 readData(char **data, qint64 pos, qint64 size) = 0;
    virtual qint64 writeData(char *data, qint64 pos, qint64 size) = 0;
    virtual bool sync(char *addr) = 0;
    virtual bool destroy(char *addr) = 0;
    virtual void clean() = 0;
    virtual int typeId() const = 0;

};

#endif
