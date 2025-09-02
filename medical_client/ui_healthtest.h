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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_healthtest
{
public:
    QLabel *label_healthtest_title;
    QWidget *formContainer;
    QGridLayout *gridLayout;
    QLabel *label_sex;
    QLineEdit *sex_;
    QLabel *label_height;
    QLineEdit *height;
    QLabel *label_weight;
    QLineEdit *weight;
    QLabel *label_heart_rate;
    QLineEdit *heart_rate;
    QLabel *label_temperature;
    QLineEdit *temperature;
    QLabel *label_vital_capacity;
    QLineEdit *vital_capacity;
    QLabel *label_pressure;
    QLabel *label_pressure_height;
    QLineEdit *pressure_high;
    QLabel *label_pressure_low;
    QLineEdit *pressure_low;
    QHBoxLayout *horizontalLayout;
    QPushButton *healthtest_sure;
    QPushButton *healthtest_return;

    void setupUi(QWidget *healthtest)
    {
        if (healthtest->objectName().isEmpty())
            healthtest->setObjectName(QString::fromUtf8("healthtest"));
        healthtest->resize(800, 600);
        healthtest->setMinimumSize(QSize(800, 600));
        healthtest->setStyleSheet(QString::fromUtf8(" QWidget { background-color: #f5f9fc; font-family: 'Microsoft YaHei'; } QLabel { color: #333333; font-size: 14px; } QLineEdit { border: 1px solid #d1d5db; border-radius: 4px; padding: 8px; background-color: white; font-size: 14px; } QLineEdit:focus { border: 1px solid #4a90e2; } QPushButton { background-color: #4a90e2; color: white; border: none; border-radius: 4px; padding: 10px 20px; font-size: 14px; } QPushButton:hover { background-color: #3a7bc8; } QPushButton:pressed { background-color: #2c6bb6; } #header { background-color: #4a90e2; color: white; padding: 15px; border-radius: 0; font-size: 20px; font-weight: bold; } #formContainer { background-color: white; border-radius: 8px; padding: 20px; margin: 15px; box-shadow: 0 2px 4px rgba(0,0,0,0.1); } "));
        label_healthtest_title = new QLabel(healthtest);
        label_healthtest_title->setObjectName(QString::fromUtf8("label_healthtest_title"));
        label_healthtest_title->setGeometry(QRect(0, 0, 800, 60));
        label_healthtest_title->setStyleSheet(QString::fromUtf8("#header"));
        label_healthtest_title->setAlignment(Qt::AlignCenter);
        formContainer = new QWidget(healthtest);
        formContainer->setObjectName(QString::fromUtf8("formContainer"));
        formContainer->setGeometry(QRect(50, 80, 700, 450));
        formContainer->setStyleSheet(QString::fromUtf8("#formContainer"));
        gridLayout = new QGridLayout(formContainer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_sex = new QLabel(formContainer);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));

        gridLayout->addWidget(label_sex, 0, 0, 1, 1);

        sex_ = new QLineEdit(formContainer);
        sex_->setObjectName(QString::fromUtf8("sex_"));
        sex_->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(sex_, 0, 1, 1, 1);

        label_height = new QLabel(formContainer);
        label_height->setObjectName(QString::fromUtf8("label_height"));

        gridLayout->addWidget(label_height, 0, 2, 1, 1);

        height = new QLineEdit(formContainer);
        height->setObjectName(QString::fromUtf8("height"));
        height->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(height, 0, 3, 1, 1);

        label_weight = new QLabel(formContainer);
        label_weight->setObjectName(QString::fromUtf8("label_weight"));

        gridLayout->addWidget(label_weight, 1, 0, 1, 1);

        weight = new QLineEdit(formContainer);
        weight->setObjectName(QString::fromUtf8("weight"));
        weight->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(weight, 1, 1, 1, 1);

        label_heart_rate = new QLabel(formContainer);
        label_heart_rate->setObjectName(QString::fromUtf8("label_heart_rate"));

        gridLayout->addWidget(label_heart_rate, 1, 2, 1, 1);

        heart_rate = new QLineEdit(formContainer);
        heart_rate->setObjectName(QString::fromUtf8("heart_rate"));
        heart_rate->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(heart_rate, 1, 3, 1, 1);

        label_temperature = new QLabel(formContainer);
        label_temperature->setObjectName(QString::fromUtf8("label_temperature"));

        gridLayout->addWidget(label_temperature, 2, 0, 1, 1);

        temperature = new QLineEdit(formContainer);
        temperature->setObjectName(QString::fromUtf8("temperature"));
        temperature->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(temperature, 2, 1, 1, 1);

        label_vital_capacity = new QLabel(formContainer);
        label_vital_capacity->setObjectName(QString::fromUtf8("label_vital_capacity"));

        gridLayout->addWidget(label_vital_capacity, 2, 2, 1, 1);

        vital_capacity = new QLineEdit(formContainer);
        vital_capacity->setObjectName(QString::fromUtf8("vital_capacity"));
        vital_capacity->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(vital_capacity, 2, 3, 1, 1);

        label_pressure = new QLabel(formContainer);
        label_pressure->setObjectName(QString::fromUtf8("label_pressure"));

        gridLayout->addWidget(label_pressure, 3, 0, 1, 2);

        label_pressure_height = new QLabel(formContainer);
        label_pressure_height->setObjectName(QString::fromUtf8("label_pressure_height"));

        gridLayout->addWidget(label_pressure_height, 4, 0, 1, 1);

        pressure_high = new QLineEdit(formContainer);
        pressure_high->setObjectName(QString::fromUtf8("pressure_high"));
        pressure_high->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(pressure_high, 4, 1, 1, 1);

        label_pressure_low = new QLabel(formContainer);
        label_pressure_low->setObjectName(QString::fromUtf8("label_pressure_low"));

        gridLayout->addWidget(label_pressure_low, 5, 0, 1, 1);

        pressure_low = new QLineEdit(formContainer);
        pressure_low->setObjectName(QString::fromUtf8("pressure_low"));
        pressure_low->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(pressure_low, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        healthtest_sure = new QPushButton(formContainer);
        healthtest_sure->setObjectName(QString::fromUtf8("healthtest_sure"));

        horizontalLayout->addWidget(healthtest_sure);

        healthtest_return = new QPushButton(formContainer);
        healthtest_return->setObjectName(QString::fromUtf8("healthtest_return"));

        horizontalLayout->addWidget(healthtest_return);


        gridLayout->addLayout(horizontalLayout, 6, 2, 1, 2);


        retranslateUi(healthtest);

        QMetaObject::connectSlotsByName(healthtest);
    } // setupUi

    void retranslateUi(QWidget *healthtest)
    {
        healthtest->setWindowTitle(QApplication::translate("healthtest", "\345\201\245\345\272\267\350\257\204\344\274\260", nullptr));
        label_healthtest_title->setText(QApplication::translate("healthtest", "\345\201\245\345\272\267\350\257\204\344\274\260", nullptr));
        label_sex->setText(QApplication::translate("healthtest", "\346\200\247\345\210\253\357\274\232", nullptr));
        sex_->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\347\224\267\346\210\226\345\245\263", nullptr));
        label_height->setText(QApplication::translate("healthtest", "\350\272\253\351\253\230(cm)\357\274\232", nullptr));
        height->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\350\272\253\351\253\230", nullptr));
        label_weight->setText(QApplication::translate("healthtest", "\344\275\223\351\207\215(kg)\357\274\232", nullptr));
        weight->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\344\275\223\351\207\215", nullptr));
        label_heart_rate->setText(QApplication::translate("healthtest", "\345\277\203\347\216\207(\346\254\241/\345\210\206\351\222\237)\357\274\232", nullptr));
        heart_rate->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\345\277\203\347\216\207", nullptr));
        label_temperature->setText(QApplication::translate("healthtest", "\344\275\223\346\270\251(\342\204\203)\357\274\232", nullptr));
        temperature->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\344\275\223\346\270\251", nullptr));
        label_vital_capacity->setText(QApplication::translate("healthtest", "\350\202\272\346\264\273\351\207\217(ml)\357\274\232", nullptr));
        vital_capacity->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\350\202\272\346\264\273\351\207\217", nullptr));
        label_pressure->setText(QApplication::translate("healthtest", "\350\241\200\345\216\213(mmHg)\357\274\232", nullptr));
        label_pressure_height->setText(QApplication::translate("healthtest", "\351\253\230\345\216\213\357\274\232", nullptr));
        pressure_high->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\351\253\230\345\216\213\345\200\274", nullptr));
        label_pressure_low->setText(QApplication::translate("healthtest", "\344\275\216\345\216\213\357\274\232", nullptr));
        pressure_low->setPlaceholderText(QApplication::translate("healthtest", "\350\257\267\350\276\223\345\205\245\344\275\216\345\216\213\345\200\274", nullptr));
        healthtest_sure->setText(QApplication::translate("healthtest", "\345\274\200\345\247\213\350\257\204\344\274\260", nullptr));
        healthtest_return->setText(QApplication::translate("healthtest", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class healthtest: public Ui_healthtest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHTEST_H
