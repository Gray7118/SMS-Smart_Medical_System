/********************************************************************************
** Form generated from reading UI file 'healthtest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEALTHTEST_H
#define UI_HEALTHTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_healthtest
{
public:
    QLabel *label_healthtest_title;
    QLabel *label_height;
    QLabel *label_weight;
    QLabel *label_heart_rate;
    QLabel *label_pressure;
    QLabel *label_vital_capacity;
    QLineEdit *pressure_high;
    QLabel *label_pressure_low;
    QLabel *label_pressure_height;
    QLineEdit *pressure_low;
    QLabel *label_temperature;
    QPushButton *healthtest_return;
    QPushButton *healthtest_sure;
    QLabel *label_sex;
    QLineEdit *sex_;
    QLineEdit *heart_rate;
    QLineEdit *height;
    QLineEdit *weight;
    QLineEdit *temperature;
    QLineEdit *vital_capacity;

    void setupUi(QWidget *healthtest)
    {
        if (healthtest->objectName().isEmpty())
            healthtest->setObjectName(QString::fromUtf8("healthtest"));
        healthtest->resize(638, 537);
        label_healthtest_title = new QLabel(healthtest);
        label_healthtest_title->setObjectName(QString::fromUtf8("label_healthtest_title"));
        label_healthtest_title->setGeometry(QRect(220, 10, 141, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label_healthtest_title->setFont(font);
        label_height = new QLabel(healthtest);
        label_height->setObjectName(QString::fromUtf8("label_height"));
        label_height->setGeometry(QRect(100, 80, 91, 41));
        QFont font1;
        font1.setPointSize(12);
        label_height->setFont(font1);
        label_weight = new QLabel(healthtest);
        label_weight->setObjectName(QString::fromUtf8("label_weight"));
        label_weight->setGeometry(QRect(100, 130, 71, 31));
        label_weight->setFont(font1);
        label_heart_rate = new QLabel(healthtest);
        label_heart_rate->setObjectName(QString::fromUtf8("label_heart_rate"));
        label_heart_rate->setGeometry(QRect(60, 150, 221, 91));
        label_heart_rate->setFont(font1);
        label_pressure = new QLabel(healthtest);
        label_pressure->setObjectName(QString::fromUtf8("label_pressure"));
        label_pressure->setGeometry(QRect(90, 290, 121, 71));
        label_pressure->setFont(font1);
        label_vital_capacity = new QLabel(healthtest);
        label_vital_capacity->setObjectName(QString::fromUtf8("label_vital_capacity"));
        label_vital_capacity->setGeometry(QRect(90, 260, 101, 41));
        label_vital_capacity->setFont(font1);
        pressure_high = new QLineEdit(healthtest);
        pressure_high->setObjectName(QString::fromUtf8("pressure_high"));
        pressure_high->setGeometry(QRect(230, 310, 121, 41));
        label_pressure_low = new QLabel(healthtest);
        label_pressure_low->setObjectName(QString::fromUtf8("label_pressure_low"));
        label_pressure_low->setGeometry(QRect(190, 370, 91, 41));
        label_pressure_low->setFont(font1);
        label_pressure_height = new QLabel(healthtest);
        label_pressure_height->setObjectName(QString::fromUtf8("label_pressure_height"));
        label_pressure_height->setGeometry(QRect(190, 300, 71, 51));
        label_pressure_height->setFont(font1);
        pressure_low = new QLineEdit(healthtest);
        pressure_low->setObjectName(QString::fromUtf8("pressure_low"));
        pressure_low->setGeometry(QRect(230, 380, 121, 41));
        label_temperature = new QLabel(healthtest);
        label_temperature->setObjectName(QString::fromUtf8("label_temperature"));
        label_temperature->setGeometry(QRect(100, 210, 141, 61));
        label_temperature->setFont(font1);
        healthtest_return = new QPushButton(healthtest);
        healthtest_return->setObjectName(QString::fromUtf8("healthtest_return"));
        healthtest_return->setGeometry(QRect(390, 460, 101, 51));
        healthtest_sure = new QPushButton(healthtest);
        healthtest_sure->setObjectName(QString::fromUtf8("healthtest_sure"));
        healthtest_sure->setGeometry(QRect(120, 460, 101, 51));
        label_sex = new QLabel(healthtest);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));
        label_sex->setGeometry(QRect(430, 20, 61, 31));
        label_sex->setFont(font1);
        sex_ = new QLineEdit(healthtest);
        sex_->setObjectName(QString::fromUtf8("sex_"));
        sex_->setGeometry(QRect(510, 20, 111, 41));
        heart_rate = new QLineEdit(healthtest);
        heart_rate->setObjectName(QString::fromUtf8("heart_rate"));
        heart_rate->setGeometry(QRect(180, 180, 251, 31));
        height = new QLineEdit(healthtest);
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(180, 90, 251, 31));
        weight = new QLineEdit(healthtest);
        weight->setObjectName(QString::fromUtf8("weight"));
        weight->setGeometry(QRect(180, 130, 251, 31));
        temperature = new QLineEdit(healthtest);
        temperature->setObjectName(QString::fromUtf8("temperature"));
        temperature->setGeometry(QRect(180, 220, 251, 31));
        vital_capacity = new QLineEdit(healthtest);
        vital_capacity->setObjectName(QString::fromUtf8("vital_capacity"));
        vital_capacity->setGeometry(QRect(180, 260, 251, 31));

        retranslateUi(healthtest);

        QMetaObject::connectSlotsByName(healthtest);
    } // setupUi

    void retranslateUi(QWidget *healthtest)
    {
        healthtest->setWindowTitle(QApplication::translate("healthtest", "Form", nullptr));
        label_healthtest_title->setText(QApplication::translate("healthtest", "\345\201\245\345\272\267\350\257\204\344\274\260", nullptr));
        label_height->setText(QApplication::translate("healthtest", "\350\272\253\351\253\230/cm", nullptr));
        label_weight->setText(QApplication::translate("healthtest", "\344\275\223\351\207\215/kg", nullptr));
        label_heart_rate->setText(QApplication::translate("healthtest", "\345\277\203\347\216\207/\346\254\241\346\257\217\345\210\206\351\222\237", nullptr));
        label_pressure->setText(QApplication::translate("healthtest", "\350\241\200\345\216\213/mmHg", nullptr));
        label_vital_capacity->setText(QApplication::translate("healthtest", "\350\202\272\346\264\273\351\207\217/ml", nullptr));
        label_pressure_low->setText(QApplication::translate("healthtest", "\344\275\216", nullptr));
        label_pressure_height->setText(QApplication::translate("healthtest", "\351\253\230", nullptr));
        label_temperature->setText(QApplication::translate("healthtest", "\344\275\223\346\270\251/\342\204\203", nullptr));
        healthtest_return->setText(QApplication::translate("healthtest", "\350\277\224\345\233\236", nullptr));
        healthtest_sure->setText(QApplication::translate("healthtest", "\347\241\256\345\256\232", nullptr));
        label_sex->setText(QApplication::translate("healthtest", "\346\200\247\345\210\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class healthtest: public Ui_healthtest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHTEST_H
