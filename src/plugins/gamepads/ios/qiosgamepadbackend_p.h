/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Gamepad module
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QIOSGAMEPADCONTROLLER_H
#define QIOSGAMEPADCONTROLLER_H

#include <QtCore/QTimer>
#include <QtCore/QMap>

#include <QtGamepad/QGamepadManager>
#include <QtGamepad/private/qgamepadbackend_p.h>

Q_FORWARD_DECLARE_OBJC_CLASS(QT_MANGLE_NAMESPACE(IosGamepadManager));

QT_BEGIN_NAMESPACE

class QIosGamepadBackend : public QGamepadBackend
{
    Q_OBJECT
public:
    explicit QIosGamepadBackend(QObject *parent = 0);
    ~QIosGamepadBackend();

protected:
    bool start();
    void stop();

public slots:
    void iosGamepadAdded(int index);
    void iosGamepadRemoved(int index);
    void iosGamepadAxisMoved(int index, QGamepadManager::GamepadAxis axis, double value);
    void iosGamepadButtonPressed(int index, QGamepadManager::GamepadButton button, double value);
    void iosGamepadButtonReleased(int index, QGamepadManager::GamepadButton button);
    void handlePauseButton(int index);

private:
    QT_MANGLE_NAMESPACE(IosGamepadManager) *m_iosGamepadManager;
    bool m_isMonitoringActive;
    QMap<int, bool> m_pauseButtonMap;
};

QT_END_NAMESPACE

#endif // QIOSGAMEPADCONTROLLER_H
