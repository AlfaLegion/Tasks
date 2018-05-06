/********************************************************************************
** Form generated from reading UI file 'coursework.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEWORK_H
#define UI_COURSEWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseWorkClass
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_6;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *CourseWorkClass)
    {
        if (CourseWorkClass->objectName().isEmpty())
            CourseWorkClass->setObjectName(QStringLiteral("CourseWorkClass"));
        CourseWorkClass->resize(776, 847);
        gridLayout = new QGridLayout(CourseWorkClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(CourseWorkClass);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_5->addWidget(label_9);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_6);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(181, 16777215));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(78, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(175, 16777215));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(78, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(122, 16777215));

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(78, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(151, 16777215));

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 378, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


        retranslateUi(CourseWorkClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CourseWorkClass);
    } // setupUi

    void retranslateUi(QWidget *CourseWorkClass)
    {
        CourseWorkClass->setWindowTitle(QApplication::translate("CourseWorkClass", "CourseWork", 0));
        groupBox->setTitle(QApplication::translate("CourseWorkClass", "\320\230\321\202\320\265\321\200\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", 0));
        label_9->setText(QApplication::translate("CourseWorkClass", "\320\237\320\276\320\273\320\275\321\213\320\265 \320\267\320\260\321\202\321\200\320\260\321\202\321\213", 0));
        label_10->setText(QApplication::translate("CourseWorkClass", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CourseWorkClass", "\320\241\320\265\321\202\320\265\320\262\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260 (\320\234\320\265\321\202\320\276\320\264 \320\261\321\203\321\204\320\265\321\200\320\275\320\276\320\263\320\276 \320\267\320\260\320\277\320\260\321\201\320\260)", 0));
        label->setText(QApplication::translate("CourseWorkClass", "\320\236\320\261\321\212\320\265\320\274 \320\237\320\227\320\243 \320\275\320\260 \320\272\320\260\320\266\320\264\320\276\320\271 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\270 ", 0));
        label_2->setText(QApplication::translate("CourseWorkClass", "...", 0));
        label_3->setText(QApplication::translate("CourseWorkClass", "\320\235\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\276\320\264\321\203\320\273\320\265\320\271", 0));
        label_4->setText(QApplication::translate("CourseWorkClass", "...", 0));
        label_7->setText(QApplication::translate("CourseWorkClass", "\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \320\276\320\261\321\212\320\265\320\274 \320\237\320\227\320\243", 0));
        label_8->setText(QApplication::translate("CourseWorkClass", "...", 0));
        label_5->setText(QApplication::translate("CourseWorkClass", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\206\320\265\320\273\320\265\320\262\320\276\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0));
        label_6->setText(QApplication::translate("CourseWorkClass", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CourseWorkClass", "\320\227\320\260\320\264\320\260\321\207\320\260 \320\264\320\270\320\275\320\260\320\274\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class CourseWorkClass: public Ui_CourseWorkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEWORK_H
