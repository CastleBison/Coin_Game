#include "MyCharacter.h"

#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(	TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Coin/UI/WBP_UI.WBP_UI_C'"));

	if (WidgetClassFinder.Succeeded())
	{
		CoinWidgetClass = WidgetClassFinder.Class;
	}
	else
	{
		CoinWidgetClass = nullptr;
	}
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (CoinWidgetClass)
	{
		CoinWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), CoinWidgetClass);

		if (CoinWidgetInstance)
		{
			CoinWidgetInstance->AddToViewport();
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Check"));
}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

