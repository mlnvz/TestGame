#include "HUD/InGameHUDWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


void UInGameHUDWidget::UpdateScore(int32 Score)
{
    // Обновляем текстовые поля результатами
    if (ScoreText)
    {
        FString ScoreString = FString::Printf(TEXT("Score: %d"), Score);
        ScoreText->SetText(FText::FromString(ScoreString));
    }
}

void UInGameHUDWidget::UpdateLives(int32 Lives)
{
    // Меняем цвет и прозрачность сердечек в зависимости от оставшихся жизней
    if (Heart1)
    {
        Heart1->SetColorAndOpacity(Lives >= 1 ? FLinearColor::White : FLinearColor(1, 1, 1, 0.3f));
    }
    if (Heart2)
    {
        Heart2->SetColorAndOpacity(Lives >= 2 ? FLinearColor::White : FLinearColor(1, 1, 1, 0.3f));
    }
    if (Heart3)
    {
        Heart3->SetColorAndOpacity(Lives >= 3 ? FLinearColor::White : FLinearColor(1, 1, 1, 0.3f));
    }
}