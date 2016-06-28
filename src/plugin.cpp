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

#include <QtQml/qqmlextensionplugin.h>
#include <qqml.h>
#include <QDBusMetaType>

#include "geniviappman.h"

static QObject *geniviappman_singletontype_provider(QQmlEngine *engine, QJSEngine *jsEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(jsEngine)

    GeniviAppMan *inst = new GeniviAppMan();
    return inst;
}

class GeniviAppFwPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    virtual void registerTypes(const char *uri)
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("GeniviAppFw"));
        Q_UNUSED(uri);

        qDBusRegisterMetaType<GeniviAppInfo>();

        qmlRegisterSingletonType<GeniviAppMan>(uri, 1, 0, "GeniviAppMan", geniviappman_singletontype_provider);
    }
};

#include "plugin.moc"
