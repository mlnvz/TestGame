
#include "GameModes/MainGameMode.h"
#include "HUD/GameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/MyPlayerController.h" // �������� ������������ ���� ��� AMyPlayerController
#include "Actors/PlayerBasket.h" // �������� ������������ ���� ��� APlayerBasket


AMainGameMode::AMainGameMode()
{
    DefaultPawnClass = APlayerBasket::StaticClass(); // ��������� ����� �������� ��� Pawn
    PlayerControllerClass = AMyPlayerController::StaticClass(); // ���������� ��������� PlayerController


    MaxLives = 3;
    Score = 0;
    Lives = MaxLives;
    GameTime = 0.0f;
    bIsGameActive = true;
    PrimaryActorTick.bCanEverTick = true;
}

void AMainGameMode::BeginPlay()
{
    Super::BeginPlay();


    // �������� ������ �� HUD
    GameHUD = Cast<AGameHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());

    if (GameHUD)
    {
        // �������������� ����������� ����� � ������
        GameHUD->UpdateScore(Score);
        GameHUD->UpdateLives(Lives);
    }

}

void AMainGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsGameActive)
    {
        GameTime += DeltaTime; // ����������� ����� ����
    }
}


void AMainGameMode::AddScore()
{
    Score++;

    if (GameHUD)
    {
        GameHUD->UpdateScore(Score);
    }
}

void AMainGameMode::LoseLife()
{
    Lives--;

    if (GameHUD)
    {
        GameHUD->UpdateLives(Lives);
    }


    // ���� ����� ���������
    if (Lives <= 0)
    {
        bIsGameActive = false; // ������������� ������� ������� ����, ���� ���� ��������� ������������
        
        // ���������� ���� ���������
            if (GameHUD)
            {
                GameHUD->ShowGameOverMenu(GameTime, Score);
            }

        // ��������� ���� ��� �������� (PlayerBasket)
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
       
        APawn* PlayerPawn = PlayerController->GetPawn();
        if (PlayerPawn)
        {
            PlayerPawn->DisableInput(PlayerController);
        }
    }
}