TARGET = %{Target}

LIBS += ../%{ProjectName}/Urho3D/lib/libUrho3D.a \\
    -lpthread \\
    -ldl \\
    -lGL

QMAKE_CXXFLAGS += -std=c++14 -O2

INCLUDEPATH += \\
    ../%{ProjectName}/Urho3D/include \\
    ../%{ProjectName}/Urho3D/include/Urho3D/ThirdParty \\

TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \\
	%{CrsFileName}
HEADERS += \\
	%{HdrFileName}

DISTFILES += \\
    LICENSE_TEMPLATE
