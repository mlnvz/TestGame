
#include "GameModes/MainGameMode.h"
#include "HUD/GameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/MyPlayerController.h" // Включаем заголовочный файл для AMyPlayerController
#include "Actors/PlayerBasket.h" // Включаем заголовочный файл для APlayerBasket


AMainGameMode::AMainGameMode()
{
    DefaultPawnClass = APlayerBasket::StaticClass(); // Указываем класс корзинки как Pawn
    PlayerControllerClass = AMyPlayerController::StaticClass(); // Используем кастомный PlayerController


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


    // Получаем ссылку на HUD
    GameHUD = Cast<AGameHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());

    if (GameHUD)
    {
        // Инициализируем отображение очков и жизней
        GameHUD->UpdateScore(Score);
        GameHUD->UpdateLives(Lives);
    }

}

void AMainGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsGameActive)
    {
        GameTime += DeltaTime; // Увеличиваем время игры
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


    // Если жизни кончились
    if (Lives <= 0)
    {
        bIsGameActive = false; // Останавливаем подсчет времени игры, если меню проигрыша отображается
        
        // Показываем меню проигрыша
            if (GameHUD)
            {
                GameHUD->ShowGameOverMenu(GameTime, Score);
            }

        // Отключаем ввод для корзинки (PlayerBasket)
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
       
        APawn* PlayerPawn = PlayerController->GetPawn();
        if (PlayerPawn)
        {
            PlayerPawn->DisableInput(PlayerController);
        }
    }
}