/*
* Copyright 2008,2011 Will Stephenson <wstephenson@kde.org>
* Copyright 2013 Daniel Nicoletti <dantti12@gmail.com>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) version 3, or any
later version accepted by the membership of KDE e.V. (or its
successor approved by the membership of KDE e.V.), which shall
act as a proxy defined in Section 6 of version 3 of the license.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NMQT_IPV4CONFIG_H
#define NMQT_IPV4CONFIG_H

#include "QtNetworkManager-export.h"

#include <QtCore/QStringList>
#include <QNetworkAddressEntry>

namespace NetworkManager
{

class NMQT_EXPORT IPv4Address : public QNetworkAddressEntry
{
public:
    IPv4Address();
    ~IPv4Address();
    IPv4Address(const IPv4Address&);
    bool isValid() const;
    void setGateway(const QHostAddress &gateway);
    QHostAddress gateway() const;
    IPv4Address &operator=(const IPv4Address&);
private:
    class Private;
    Private * d;
};

class NMQT_EXPORT IPv4Route : public QNetworkAddressEntry
{
public:
    IPv4Route();
    ~IPv4Route();
    IPv4Route(const IPv4Route&);
    IPv4Route &operator=(const IPv4Route&);
    bool isValid() const;
    QNetworkAddressEntry route() const;
    void setNextHop(const QHostAddress &nextHop) const;
    QHostAddress nextHop() const;
    void setMetric(quint32 metric);
    quint32 metric() const;
private:
    class Private;
    Private * d;
};

class NMQT_EXPORT IPv4Config
{
public:
    IPv4Config(const QList<IPv4Address> &addresses,
        const QList<QHostAddress> &nameservers,
        const QStringList &domains,
        const QList<IPv4Route> &routes);
    IPv4Config();
    ~IPv4Config();
    IPv4Config(const IPv4Config&);
    /**
     * List of IP addresses related to this configuration.
     */
    QList<IPv4Address> addresses() const;
    QList<QHostAddress> nameservers() const;
    QStringList domains() const;
    QList<IPv4Route> routes() const;
    IPv4Config &operator=(const IPv4Config&);
    bool isValid() const;
private:
    class Private;
    Private * d;
};

} // namespace NetworkManager

#endif // NMQT__IPV4CONFIG_H
