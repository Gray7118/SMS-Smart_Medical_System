add_executable(demo2
  demo2.cpp
  sendemail.cpp
  sendemail.ui)

target_link_libraries(demo2 PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Gui
  Qt${QT_VERSION_MAJOR}::Widgets
  ${LIBRARY_TARGET_NAME})
