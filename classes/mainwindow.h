/********************************************************************************
** Form generated from reading UI file 'mainwindowbksgUV.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWBKSGUV_H
#define MAINWINDOWBKSGUV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *import_formula;
    QAction *save_formula;
    QAction *set_font;
    QAction *set_style;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *vLayout1;
    QLabel *label1;
    QLineEdit *input_web;
    QHBoxLayout *hLayout4;
    QCheckBox *has_ll;
    QCheckBox *has_ul;
    QCheckBox *has_nb;
    QCheckBox *has_sb;
    QHBoxLayout *hLayout3;
    QLabel *label2;
    QSlider *complexity;
    QPushButton *make_psw;
    QHBoxLayout *hLayout2;
    QLineEdit *show_psw;
    QPushButton *copy_psw;
    QHBoxLayout *hLayout1;
    QPushButton *change_formula;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 649);
        import_formula = new QAction(MainWindow);
        import_formula->setObjectName(QString::fromUtf8("import_formula"));
        save_formula = new QAction(MainWindow);
        save_formula->setObjectName(QString::fromUtf8("save_formula"));
        set_font = new QAction(MainWindow);
        set_font->setObjectName(QString::fromUtf8("set_font"));
        set_style = new QAction(MainWindow);
        set_style->setObjectName(QString::fromUtf8("set_style"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        vLayout1 = new QVBoxLayout();
        vLayout1->setSpacing(20);
        vLayout1->setObjectName(QString::fromUtf8("vLayout1"));
        vLayout1->setContentsMargins(20, 20, 20, 20);
        label1 = new QLabel(centralwidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label1->sizePolicy().hasHeightForWidth());
        label1->setSizePolicy(sizePolicy);
        label1->setMinimumSize(QSize(740, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        label1->setFont(font);

        vLayout1->addWidget(label1);

        input_web = new QLineEdit(centralwidget);
        input_web->setObjectName(QString::fromUtf8("input_web"));
        sizePolicy.setHeightForWidth(input_web->sizePolicy().hasHeightForWidth());
        input_web->setSizePolicy(sizePolicy);
        input_web->setMinimumSize(QSize(740, 50));
        input_web->setFont(font);

        vLayout1->addWidget(input_web);

        hLayout4 = new QHBoxLayout();
        hLayout4->setSpacing(20);
        hLayout4->setObjectName(QString::fromUtf8("hLayout4"));
        has_ll = new QCheckBox(centralwidget);
        has_ll->setObjectName(QString::fromUtf8("has_ll"));
        sizePolicy.setHeightForWidth(has_ll->sizePolicy().hasHeightForWidth());
        has_ll->setSizePolicy(sizePolicy);
        has_ll->setMinimumSize(QSize(170, 50));
        has_ll->setFont(font);

        hLayout4->addWidget(has_ll);

        has_ul = new QCheckBox(centralwidget);
        has_ul->setObjectName(QString::fromUtf8("has_ul"));
        sizePolicy.setHeightForWidth(has_ul->sizePolicy().hasHeightForWidth());
        has_ul->setSizePolicy(sizePolicy);
        has_ul->setMinimumSize(QSize(170, 50));
        has_ul->setFont(font);

        hLayout4->addWidget(has_ul);

        has_nb = new QCheckBox(centralwidget);
        has_nb->setObjectName(QString::fromUtf8("has_nb"));
        sizePolicy.setHeightForWidth(has_nb->sizePolicy().hasHeightForWidth());
        has_nb->setSizePolicy(sizePolicy);
        has_nb->setMinimumSize(QSize(170, 50));
        has_nb->setFont(font);

        hLayout4->addWidget(has_nb);

        has_sb = new QCheckBox(centralwidget);
        has_sb->setObjectName(QString::fromUtf8("has_sb"));
        sizePolicy.setHeightForWidth(has_sb->sizePolicy().hasHeightForWidth());
        has_sb->setSizePolicy(sizePolicy);
        has_sb->setMinimumSize(QSize(170, 50));
        has_sb->setFont(font);

        hLayout4->addWidget(has_sb);


        vLayout1->addLayout(hLayout4);

        hLayout3 = new QHBoxLayout();
        hLayout3->setObjectName(QString::fromUtf8("hLayout3"));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label2->sizePolicy().hasHeightForWidth());
        label2->setSizePolicy(sizePolicy1);
        label2->setMinimumSize(QSize(185, 50));
        label2->setFont(font);

        hLayout3->addWidget(label2);

        complexity = new QSlider(centralwidget);
        complexity->setObjectName(QString::fromUtf8("complexity"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(complexity->sizePolicy().hasHeightForWidth());
        complexity->setSizePolicy(sizePolicy2);
        complexity->setMinimumSize(QSize(555, 50));
        complexity->setFont(font);
        complexity->setMinimum(1);
        complexity->setMaximum(5);
        complexity->setOrientation(Qt::Horizontal);
        complexity->setTickPosition(QSlider::TicksBelow);

        hLayout3->addWidget(complexity);


        vLayout1->addLayout(hLayout3);

        make_psw = new QPushButton(centralwidget);
        make_psw->setObjectName(QString::fromUtf8("make_psw"));
        sizePolicy.setHeightForWidth(make_psw->sizePolicy().hasHeightForWidth());
        make_psw->setSizePolicy(sizePolicy);
        make_psw->setMinimumSize(QSize(740, 50));
        make_psw->setFont(font);

        vLayout1->addWidget(make_psw);

        hLayout2 = new QHBoxLayout();
        hLayout2->setSpacing(20);
        hLayout2->setObjectName(QString::fromUtf8("hLayout2"));
        show_psw = new QLineEdit(centralwidget);
        show_psw->setObjectName(QString::fromUtf8("show_psw"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(5);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(show_psw->sizePolicy().hasHeightForWidth());
        show_psw->setSizePolicy(sizePolicy3);
        show_psw->setMinimumSize(QSize(600, 50));
        show_psw->setFont(font);
        show_psw->setEchoMode(QLineEdit::Password);
        show_psw->setReadOnly(true);

        hLayout2->addWidget(show_psw);

        copy_psw = new QPushButton(centralwidget);
        copy_psw->setObjectName(QString::fromUtf8("copy_psw"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(copy_psw->sizePolicy().hasHeightForWidth());
        copy_psw->setSizePolicy(sizePolicy4);
        copy_psw->setMinimumSize(QSize(120, 50));
        copy_psw->setFont(font);

        hLayout2->addWidget(copy_psw);


        vLayout1->addLayout(hLayout2);

        hLayout1 = new QHBoxLayout();
        hLayout1->setSpacing(20);
        hLayout1->setObjectName(QString::fromUtf8("hLayout1"));
        change_formula = new QPushButton(centralwidget);
        change_formula->setObjectName(QString::fromUtf8("change_formula"));
        sizePolicy.setHeightForWidth(change_formula->sizePolicy().hasHeightForWidth());
        change_formula->setSizePolicy(sizePolicy);
        change_formula->setMinimumSize(QSize(740, 50));
        change_formula->setFont(font);

        hLayout1->addWidget(change_formula);


        vLayout1->addLayout(hLayout1);


        verticalLayout_2->addLayout(vLayout1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(input_web, has_ul);
        QWidget::setTabOrder(has_ul, has_nb);
        QWidget::setTabOrder(has_nb, has_sb);
        QWidget::setTabOrder(has_sb, complexity);
        QWidget::setTabOrder(complexity, make_psw);
        QWidget::setTabOrder(make_psw, copy_psw);
        QWidget::setTabOrder(copy_psw, show_psw);
        QWidget::setTabOrder(show_psw, change_formula);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuFile->addAction(import_formula);
        menuFile->addAction(save_formula);
        menuSettings->addAction(set_font);
        menuSettings->addAction(set_style);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Password Maker", nullptr));
        import_formula->setText(QCoreApplication::translate("MainWindow", "&Import formula", nullptr));
#if QT_CONFIG(shortcut)
        import_formula->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        save_formula->setText(QCoreApplication::translate("MainWindow", "&Save formula", nullptr));
#if QT_CONFIG(shortcut)
        save_formula->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        set_font->setText(QCoreApplication::translate("MainWindow", "Set &font", nullptr));
#if QT_CONFIG(shortcut)
        set_font->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        set_style->setText(QCoreApplication::translate("MainWindow", "Set &style", nullptr));
#if QT_CONFIG(shortcut)
        set_style->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        label1->setText(QCoreApplication::translate("MainWindow", "Website:", nullptr));
        has_ll->setText(QCoreApplication::translate("MainWindow", "Lower letter", nullptr));
        has_ul->setText(QCoreApplication::translate("MainWindow", "Upper letter", nullptr));
        has_nb->setText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        has_sb->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "complexity:", nullptr));
        make_psw->setText(QCoreApplication::translate("MainWindow", "Make Password", nullptr));
        copy_psw->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        change_formula->setText(QCoreApplication::translate("MainWindow", "Change formula", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "&Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWBKSGUV_H
