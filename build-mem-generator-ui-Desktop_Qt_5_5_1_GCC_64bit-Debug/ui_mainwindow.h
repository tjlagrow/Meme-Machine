/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QTextEdit *textEdit;
    QListWidget *listWidget;
    QWidget *layoutWidget1;
    QHBoxLayout *hboxLayout1;
    QLabel *label;
    QLineEdit *lineEdit;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(1076, 485);
        layoutWidget = new QWidget(ChatDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 10, 441, 411));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setReadOnly(true);

        hboxLayout->addWidget(textEdit);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(180, 16777215));
        listWidget->setFocusPolicy(Qt::NoFocus);

        hboxLayout->addWidget(listWidget);

        layoutWidget1 = new QWidget(ChatDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(380, 430, 441, 25));
        hboxLayout1 = new QHBoxLayout(layoutWidget1);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout1->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        hboxLayout1->addWidget(lineEdit);

        graphicsView = new QGraphicsView(ChatDialog);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(830, 10, 241, 441));
        graphicsView_2 = new QGraphicsView(ChatDialog);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(100, 10, 271, 421));
        pushButton = new QPushButton(ChatDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 440, 80, 23));
        pushButton_2 = new QPushButton(ChatDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 80, 23));
        pushButton_3 = new QPushButton(ChatDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 60, 80, 23));
        pushButton_4 = new QPushButton(ChatDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 110, 80, 23));
        pushButton_5 = new QPushButton(ChatDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 160, 80, 23));
        pushButton_6 = new QPushButton(ChatDialog);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 210, 80, 23));
        pushButton_7 = new QPushButton(ChatDialog);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 260, 80, 23));
        pushButton_8 = new QPushButton(ChatDialog);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 310, 80, 23));
        pushButton_9 = new QPushButton(ChatDialog);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 370, 80, 23));
        pushButton_10 = new QPushButton(ChatDialog);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(920, 460, 80, 23));

        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Chat", 0));
        label->setText(QApplication::translate("ChatDialog", "Message:", 0));
        pushButton->setText(QApplication::translate("ChatDialog", "Send Meme", 0));
        pushButton_2->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_8->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("ChatDialog", "PushButton", 0));
        pushButton_10->setText(QApplication::translate("ChatDialog", "Decrypt", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
