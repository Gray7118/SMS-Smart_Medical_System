QT       += core gui network quickwidgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    simplevideocall.cpp \
    aihealthservice.cpp \
    appointmentchoose.cpp \
    # chat.cpp \  # 移除旧的
    department_choose.cpp \
    departmentchoose.cpp \
    doctor_choose.cpp \
    doctor_individualinfo.cpp \
    doctorcase.cpp \
    doctorprofile.cpp \
    emergency.cpp \
    healthtest.cpp \
    healthtestoutcome.cpp \
    main.cpp \
    message.cpp \
    messagetype.cpp \
    patient_individualinfo.cpp \
    patientcase.cpp \
    patientprofile.cpp \
    schedule_choose.cpp \
    schedulechoose.cpp \
    seedoctorinfo.cpp \
    seepatientinfo.cpp \
    # selectreceiver.cpp \  # 移除旧的
    signup.cpp \
    splashscreen.cpp \
    user.cpp \
    utils.cpp \
    widget.cpp\
    navigation/mainwindow.cpp \
    navigation/mydialog.cpp\
    email/demos/demo2/sendemail.cpp \
    email/demos/demo2/qss.cpp \
    chatmainwindow.cpp  # 添加新的


HEADERS += \
    simplevideocall.h \
    aihealthservice.h \
    appointmentchoose.h \
    # chat.h \  # 移除旧的
    demo_vars.h \
    department_choose.h \
    departmentchoose.h \
    doctor_choose.h \
    doctor_individualinfo.h \
    doctorcase.h \
    doctorprofile.h \
    emergency.h \
    healthtest.h \
    healthtestoutcome.h \
    message.h \
    messagetype.h \
    patient_individualinfo.h \
    patientcase.h \
    patientprofile.h \
    schedule_choose.h \
    schedulechoose.h \
    seedoctorinfo.h \
    seepatientinfo.h \
    # selectreceiver.h \  # 移除旧的
    signup.h \
    splashscreen.h \
    user.h \
    utils.h \
    widget.h \
    navigation/mainwindow.h \
    navigation/mydialog.h \
    navigation/mystruct.h\
    email/demos/demo2/sendemail.h \
    ChatMainWindow.h  # 添加新的

FORMS += \
    appointmentchoose.ui \
    # chat.ui \  # 移除旧的
    department_choose.ui \
    departmentchoose.ui \
    doctor_choose.ui \
    doctor_individualinfo.ui \
    doctorcase.ui \
    doctorprofile.ui \
    healthtest.ui \
    healthtestoutcome.ui \
    patient_individualinfo.ui \
    patientcase.ui \
    patientprofile.ui \
    schedule_choose.ui \
    schedulechoose.ui \
    seedoctorinfo.ui \
    seepatientinfo.ui \
    # selectreceiver.ui \  # 移除旧的
    signUp.ui \
    widget.ui \
    navigation/mainwindow.ui \
    navigation/mydialog.ui\
    email/demos/demo2/sendemail.ui \
    chatmainwindow.ui  # 添加新的

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc\
    navigation/images.qrc\
    email/demos/demo2/qss.qrc

# ===== Email SMTP 动态库 =====
unix: LIBS += -L$$PWD/email/demos/demo2 -lSmtpMime
INCLUDEPATH += $$PWD/email/demos/demo2
DEPENDPATH += $$PWD/email/demos/demo2

DISTFILES +=
