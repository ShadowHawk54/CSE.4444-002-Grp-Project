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

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QByteArray>
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QUuid>

enum ServiceProvider {
    ATT,
    METRO_PCS,
    SPRINT,
    TMOBILE,
    VERIZON,
};

class Account : public QObject
{
    Q_OBJECT
public:
    explicit Account(QUuid& uuid, QString& accountName, QDateTime& creationDate,
                     QString& emailAddress, QObject *parent = 0);

    explicit Account(QString& accountName, QString& password,
                     QString& emailAddress, QObject *parent = 0);
    // OPTIONAL
    explicit Account(QString& accountName, QString& password,
                     QString& emailAddress, QString& phoneNumber,
                     ServiceProvider serviceProvider, QObject *parent = 0);

    static bool authenticateUser(QString& username, QByteArray passwordHash);
    const QUuid& getUUID() const;
    const QDateTime& getCreationDate() const;
    const QString& getEmailAddress() const;
    const QString& getUsername() const;

    friend QDataStream& operator<<(QDataStream& out, const Account& account);
    friend QDataStream& operator>>(QDataStream& in, Account& account);

    // OPTIONAL
    const QString& getPhoneNumber() const;
    const ServiceProvider getServiceProvider() const;

private:
    const QUuid uuid;
    const QDateTime creationDate;
    QString emailAddress;
    QByteArray passwordHash;
    QString username;
    // OPTIONAL
    QString phoneNumber;
    ServiceProvider serviceProvider;

    QByteArray hashPassword(QString& password) const;
};

#endif // ACCOUNT_H
