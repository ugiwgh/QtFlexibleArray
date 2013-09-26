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
#ifndef QTFLEXIBLERAMARRAY_H
#define QTFLEXIBLERAMARRAY_H

#include "qtflexibleabstractarray.h"

class QtFlexibleRamArray : public QtFlexibleAbstractArray
{
public:
    explicit QtFlexibleRamArray(qint64 size = 0);
    ~QtFlexibleRamArray();
    // abstract methods
    qint64 size() const;
    qint64 resize(qint64 size);
    qint64 linearBytesAvaible(char *addr);
    qint64 copyData(char *data, qint64 pos, qint64 size);
    qint64 readData(char **data, qint64 pos, qint64 size);
    qint64 writeData(char *data, qint64 pos, qint64 size);
    bool sync(char *addr);
    bool destroy(char *addr);
    void clean();
    int typeId() const;
    // model depended methods
    // the data argument must be allocated by alloc() method of this class
    bool assignData(char **data, qint64 size);
    static char *alloc(qint64 size);
    static void free(char *addr);

private:
    char *m_addr;
    qint64 m_size;
    qint64 m_biggestSize;

};

#endif
