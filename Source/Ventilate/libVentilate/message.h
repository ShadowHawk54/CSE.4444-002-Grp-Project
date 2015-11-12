/* Copyright (C) 2015 Ryan Porterfield
 *
 * This file defines all networking commands.
 *
 * $QT_BEGIN_LICENSE:BSD$
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of The Qt Company Ltd nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 *
 * $QT_END_LICENSE$
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>
#include "libventilate_global.h"

class LIBVENTILATESHARED_EXPORT Message : public QObject
{
    Q_OBJECT
public:
    Message(const Message& copy);
    Message(Message&& move);
    explicit Message(QUuid& roomID, QString& username, QString& message,
                     QObject *parent = 0);
    explicit Message(QUuid& uuid, QUuid& roomID, QDateTime& timestamp,
                     QString& username, QString& message, QObject *parent = 0);

    const QString& getMessage() const;
    const QUuid& getRoomID() const;
    const QDateTime& getTimeStamp() const;
    const QString& getUsername() const;
    const QUuid& getUUID() const;

    Message& operator=(const Message& msg);
    Message& operator=(Message&& msg);
    QDataStream& operator<<(const Message& msg);
    QDataStream& operator>>(Message& msg);

private:
    QUuid uuid;
    QUuid roomID;
    QDateTime timestamp;
    QString username;
    QString message;
};

#endif // MESSAGE_H
