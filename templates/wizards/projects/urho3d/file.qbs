import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true
    files:
        luckey.h
        mastercontrol.h
@if %{SpawnMaster}
        spawnmaster.h
        sceneobject.h
@endif
@if %{InputMaster}
        inputmaster.h
        player.h
        controllable.h
@endif
@if %{EffectMaster}
        effectmaster.h
@endif

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}
