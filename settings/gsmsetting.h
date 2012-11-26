/*
    Copyright 2012  Jan Grulich <jgrulich@redhat.com>

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

#ifndef GSMSETTING_H
#define GSMSETTING_H

#include "QtNetworkManager-export.h"
#include "setting.h"

#include <QString>

namespace NetworkManager
{
namespace Settings
{
    class GsmSettingPrivate;

    class NMQT_EXPORT GsmSetting : public Setting
    {
    Q_DECLARE_PRIVATE(GsmSetting)
    public:
	enum SecretFlagType {None = 0, AgentOwned = 0x01, NotSaved = 0x02, NotRequired = 0x04};

	GsmSetting();
	GsmSetting(GsmSetting *);
	~GsmSetting();

	QString name() const;

	void setNumber(const QString & number);
	QString number() const;

	void setUsername(const QString & username);
	QString username() const;

	void setPassword(const QString & password);
	QString password() const;

	void setPasswordFlags(const SecretFlagType flags);
	SecretFlagType passwordFlags() const;

	void setApn(const QString & apn);
	QString apn() const;

	void setNetworkId(const QString & id);
	QString networkId() const;

	void setNetworkType(const qint32 type);
	qint32 networkType() const;

	void setPin(const QString & pin);
	QString pin() const;

	void setPinFlags(const SecretFlagType flags);
	SecretFlagType pinFlags() const;

	void setAllowedBand(const quint32 band);
	quint32 allowedBand() const;

	void setHomeOnly(const bool homeOnly);
	bool homeOnly() const;

	void fromMap(const QVariantMap & setting);

    private:
	GsmSettingPrivate * d_ptr;
    };

}
}



#endif // GSMSETTING_H
