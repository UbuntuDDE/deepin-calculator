// This file is part of the SpeedCrunch project
// Copyright (C) 2014 @heldercorreia
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; see the file COPYING.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA.

#include "pageserver.h"

QString PageServer::getPageContent(const QString &id)
{
    PageMaker maker = m_toc.value(id);
    if (!maker)
        return QString();
    m_currentPageID = id;
    return maker();
}

QString PageServer::getCurrentPageContent()
{
    if (m_currentPageID.isNull())
        return QString();
    return getPageContent(m_currentPageID);
}
