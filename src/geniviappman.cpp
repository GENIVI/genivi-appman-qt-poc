/*
 * GENIVI AppFw AppMan interface QML plugin
 * Copyright(C) 2016 Pelagicore AB
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "geniviappman.h"
#include "../franca/gen/appmanagercore.h"

/*
 * Serialization and deserialization operators for GeniviAppInfo
 */
QDBusArgument &operator<<(QDBusArgument &argument, const GeniviAppInfo &info)
{
    argument.beginStructure();
    argument << info.appId;
    argument.beginMap(QVariant::String, QVariant::String);
    foreach(QString k, info.values.keys())
    {
        argument.beginMapEntry();
        argument << k << info.values.value(k);
        argument.endMapEntry();
    }
    argument.endMap();
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, GeniviAppInfo &info)
{
    argument.beginStructure();
    argument >> info.appId;
    argument.beginMap();
    info.values.clear();
    foreach(QString k, info.values.keys())
    {
        QString key, value;
        argument.beginMapEntry();
        argument >> key >> value;
        argument.endMapEntry();
        info.values[key] = value;
    }
    argument.endMap();
    argument.endStructure();

    return argument;
}

/*
 * GENIVI AppManager_Core interface facade implementation
 */
GeniviAppManInterface::GeniviAppManInterface(QObject *parent)
    : QObject(parent)
{
    new AppManager_CoreAdaptor(this);

    QDBusConnection::sessionBus().registerService("org.genivi.appfw");
    QDBusConnection::sessionBus().registerObject("/org/genivi/appfw/AppManager_Core", this);
}

void GeniviAppManInterface::setAppIds(QStringList appIds)
{
    m_appIds = appIds;
    emit AppsInfoUpdated();
}

GeniviAppInfo GeniviAppManInterface::GetAppInfo(const QString &_app_id)
{
    GeniviAppInfo res;
    res.appId = _app_id;

    // TODO populate key/values
    // TODO how to react on a non-existent app?

    return res;
}

QStringList GeniviAppManInterface::GetInstalledApps()
{
    return m_appIds;
}

void GeniviAppManInterface::LaunchApp(const QString &_app_id)
{
    emit onLaunchApp(_app_id);
}

uint GeniviAppManInterface::getInterfaceVersion()
{
    return 0;
}


/*
 * GENIVI Application Manager QML element implementation
 */
GeniviAppMan::GeniviAppMan(QObject *parent)
    : QObject(parent)
    , m_model(0)
    , m_interface(0)
{
    m_interface = new GeniviAppManInterface(this);

    connect(m_interface, SIGNAL(onLaunchApp(QString)), this, SIGNAL(launchApplication(QString)));
}

QAbstractItemModel *GeniviAppMan::model() const
{
    return m_model;
}

void GeniviAppMan::setModel(QAbstractItemModel *model)
{
    if (model == m_model)
        return;

    disconnect(m_model, SIGNAL(rowsInserted(QModelIndex,int,int)), this, SLOT(onModelChanged()));
    disconnect(m_model, SIGNAL(rowsRemoved(QModelIndex,int,int)), this, SLOT(onModelChanged()));
    disconnect(m_model, SIGNAL(modelReset()), this, SLOT(onModelChanged()));

    m_model = model;

    connect(m_model, SIGNAL(rowsInserted(QModelIndex,int,int)), this, SLOT(onModelChanged()));
    connect(m_model, SIGNAL(rowsRemoved(QModelIndex,int,int)), this, SLOT(onModelChanged()));
    connect(m_model, SIGNAL(modelReset()), this, SLOT(onModelChanged()));

    onModelChanged();
    emit modelChanged(m_model);
}

void GeniviAppMan::onModelChanged()
{
    QStringList ids;

    if (m_model)
    {
        int role = m_model->roleNames().key(QByteArray("applicationId"));
        if (role > 0)
            for (int r=0; r<m_model->rowCount(); ++r)
                ids << m_model->index(r, 0).data(role).toString();
        else
            qDebug("Model does not support role 'applicationId', no application ids returned.");
    }

    m_interface->setAppIds(ids);
}
