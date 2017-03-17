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

HEADERS += \\
    luckey.h \\
    mastercontrol.h \\
    sceneobject.h \\
@if %{SpawnMaster}
    spawnmaster.h \\
@endif
@if %{InputMaster}
    inputmaster.h \\
    player.h \\
    controllable.h \\
@endif
@if %{EffectMaster}
    effectmaster.h \\
@endif

SOURCES += \\
    luckey.cpp \\
    mastercontrol.cpp \\
    sceneobject.cpp \\
@if %{SpawnMaster}
    spawnmaster.cpp \\
@endif
@if %{InputMaster}
    inputmaster.cpp \\
    player.cpp \\
    controllable.cpp \\
@endif
@if %{EffectMaster}
    effectmaster.cpp \\
@endif

DISTFILES += \\
    LICENSE_TEMPLATE
