/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include "ui_chatdialog.h"
#include "client.h"
#include "qencrypt.hpp"
#include "qtmemeGeneration.hpp"

class ChatDialog : public QDialog, private Ui::ChatDialog
{
    Q_OBJECT

public:
    ChatDialog(QWidget *parent = 0);
    void showImage(const QString &);

public slots:
    void appendMessage(const QString &from, const QString &message);

private slots:
    void returnPressed();
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);
    void showInformation();
    bool openMeme(const QString &fileName,bool fromFile);
    void open();
    bool sendMeme();
    void memeReturnedPressed();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Client client;
    QString myNickName;
    QTextTableFormat tableFormat;
    QPushButton *loadMemeButton;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QEncryption *qme;
    QmemeGeneration *qmg;
};

#endif
