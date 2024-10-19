#include "Controllers/MyPlayerController.h"
#include "GameFramework/Pawn.h" 
#include "Kismet/GameplayStatics.h"  

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetPawn())
    {
        GetPawn()->EnableInput(this); // �������� ���� ��� Pawn
    }

    // ���������� ������ � �������� �������������� ��������
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;

    // ������������� ����������� ����� �����
    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    SetInputMode(InputMode);


}


