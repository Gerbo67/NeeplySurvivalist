#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AMyAICharacter.generated.h"

UCLASS()
class NEEPLYSURVIVALIST_API AAMyAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAMyAICharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float Health = 80.0f;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	                         class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "AI")
	void OnDeath();

	void StartDeathSequence();

private:
	bool bIsDying = false;
};
