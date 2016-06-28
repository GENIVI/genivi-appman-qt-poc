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

#ifndef GENIVIAPPMAN_H
#define GENIVIAPPMAN_H

#include <QObject>
#include <QAbstractItemModel>

#include "geniviappmaninfo.h"

class GeniviAppManInterface : public QObject
{
    Q_OBJECT

public:
    explicit GeniviAppManInterface(QObject *parent = 0);

    void setAppIds(QStringList appIds);

public slots:
    GeniviAppInfo GetAppInfo(const QString &_app_id);
    QStringList GetInstalledApps();
    void LaunchApp(const QString &_app_id);
    uint getInterfaceVersion();

signals:
    void AppsInfoUpdated();

    void onLaunchApp(const QString &app_id);

private:
    QStringList m_appIds;
};

class GeniviAppMan : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QAbstractItemModel* model READ model WRITE setModel NOTIFY modelChanged)

public:
    explicit GeniviAppMan(QObject *parent = 0);

    QAbstractItemModel *model() const;

public slots:
    void setModel(QAbstractItemModel *model);

signals:
    void modelChanged(QAbstractItemModel *model);
    void launchApplication(const QString &id);

private slots:
    void onModelChanged();

private:
    QAbstractItemModel *m_model;
    GeniviAppManInterface *m_interface;
};

#endif // GENIVIAPPMAN_H
