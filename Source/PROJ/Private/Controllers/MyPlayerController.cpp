#include "Controllers/MyPlayerController.h"
#include "GameFramework/Pawn.h" 
#include "Kismet/GameplayStatics.h"  

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetPawn())
    {
        GetPawn()->EnableInput(this); // Включаем ввод для Pawn
    }

    // Показываем курсор и включаем кликабельность объектов
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;

    // Принудительно захватываем фокус ввода
    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    SetInputMode(InputMode);


}


