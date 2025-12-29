#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class COIN_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 위젯 블루프린트 클래스 (설계도)
	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<UUserWidget> CoinWidgetClass;

	// 실제 생성된 위젯 인스턴스
	UPROPERTY()
	UUserWidget* CoinWidgetInstance;

};
