%{Cpp:LicenseTemplate}\

@if %{EffectMaster}
#include "effectmaster.h"
@endif
@if %{InputMaster}
#include "inputmaster.h"
#include "player.h"
@endif
@if %{SpawnMaster}
#include "spawnmaster.h"
@endif

#include "mastercontrol.h"

URHO3D_DEFINE_APPLICATION_MAIN(MasterControl);

MasterControl* MasterControl::instance_ = NULL;

MasterControl* MasterControl::GetInstance()
{
    return MasterControl::instance_;
}

MasterControl::MasterControl(Context *context):
    Application(context)
{
    instance_ = this;
}

void MasterControl::Setup()
{
    SetRandomSeed(TIME->GetSystemTime());

    engineParameters_[EP_LOG_NAME] = GetSubsystem<FileSystem>()->GetAppPreferencesDir("luckey", "logs")+"%{ProjectName}.log";
    engineParameters_[EP_WINDOW_TITLE] = "%{ProjectName}";
    engineParameters_[EP_WINDOW_ICON] = "icon.png";
    engineParameters_[EP_WORKER_THREADS] = false;
    engineParameters_[EP_RESOURCE_PATHS] = "Resources;";
}
void MasterControl::Start()
{
@if %{EffectMaster}
    context_->RegisterSubsystem(new EffectMaster(context_));
@endif
@if %{InputMaster}
    context_->RegisterSubsystem(new InputMaster(context_));
@endif
@if %{SpawnMaster}
    context_->RegisterSubsystem(new SpawnMaster(context_));
@endif
}
void MasterControl::Stop()
{
    engine_->DumpResources(true);
}
void MasterControl::Exit()
{
    engine_->Exit();
}

@if %{InputMaster}
Vector<SharedPtr<Player> > MasterControl::GetPlayers()
{
    return players_;
}
Player* MasterControl::GetPlayer(int playerId) const
{
    for (Player* p : players_) {

        if (p->GetPlayerId() == playerId){
            return p;
        }
    }
    return nullptr;
}
Player* MasterControl::GetNearestPlayer(Vector3 pos)
{
    Player* nearest{};
    for (Player* p : players_){
        if (p->IsAlive()){

            if (!nearest
            || (LucKey::Distance(GetSubsystem<InputMaster>()->GetControllableByPlayer(p->GetPlayerId())->GetWorldPosition(), pos) <
                LucKey::Distance(GetSubsystem<InputMaster>()->GetControllableByPlayer(nearest->GetPlayerId())->GetWorldPosition(), pos)))
            {
                nearest = p;
            }
        }
    }
    return nearest;
}
@endif
