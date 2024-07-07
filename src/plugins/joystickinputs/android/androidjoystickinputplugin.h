// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef ANDROIDJOYSTICKINPUTPLUGIN_H
#define ANDROIDJOYSTICKINPUTPLUGIN_H

#include <QtUniversalInput/private/qjoystickinputplugin_p.h>
#include <QtUniversalInput/private/qjoystickinput_p.h>

QT_BEGIN_NAMESPACE

class AndroidJoystickInputPlugin : public QJoystickInputPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QJoystickInputFactoryInterface_iid FILE "android.json")

public:
    QJoystickInput *create(const QString &key, const QStringList &paramList) override;
};

QT_END_NAMESPACE

#endif // ANDROIDJOYSTICKINPUTPLUGIN_H