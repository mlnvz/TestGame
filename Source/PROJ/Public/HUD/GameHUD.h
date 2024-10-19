#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD/GameOverWidget.h"
#include "HUD/InGameHUDWidget.h"
#include "GameHUD.generated.h"

UCLASS()
class PROJ_API AGameHUD : public AHUD
{
    GENERATED_BODY()

public:

    // Обновляем очки и жизни через этот HUD
    void UpdateScore(int32 Score);
    void UpdateLives(int32 Lives);

    // Отображение меню проигрыша
    void ShowGameOverMenu(float GameTime, int32 Score);

protected:
    virtual void BeginPlay() override;

private:
    // Класс виджета меню проигрыша
    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UGameOverWidget> GameOverWidgetClass;

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UInGameHUDWidget> InGameHUDWidgetClass;

    // Ссылка на созданный InGameHUDWidget
    UPROPERTY()
    UInGameHUDWidget* InGameHUDWidget;

};